#include "command_manager.h"
#include "actor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"

// TODO clean up as won't be necc.
#define FRAME_BANK_SHIFT	5
#define FRAME_MASK_SHIFT	0x1F;

struct_command_object global_command_object;

static void( *execute[ MAX_CMD_TYPE ] )( unsigned char args );
static void( *undo[ MAX_CMD_TYPE ] )( unsigned char args );

static unsigned char command_index;
static unsigned char add_index;
static unsigned char exec_index;
static unsigned char undo_index;

static unsigned int new_frame[ MAX_COMMANDS ];
static unsigned char new_command[ MAX_COMMANDS ];
static unsigned char new_args[ MAX_COMMANDS ];

static void empty_exec_command( unsigned char args );
static void empty_undo_command( unsigned char args );
static void session_exec_command( unsigned char args );
static void session_undo_command( unsigned char args );

// Public methods.
void engine_command_manager_init()
{
	unsigned int idx;
	for( idx = 0; idx < MAX_COMMANDS; idx++ )
	{
		new_frame[ idx ] = 0;
		new_command[ idx ] = ( unsigned char ) INVALID_INDEX;
		new_args[ idx ] = 0;
	}

	// IMPORTANT execute + undo must be same order!!
	execute[ command_type_empty ] = empty_exec_command;
	execute[ command_type_fire ] = engine_actor_manager_exec_fire;
	execute[ command_type_jump ] = engine_actor_manager_exec_jump;
	execute[ command_type_move ] = engine_actor_manager_exec_move;
	execute[ command_type_bank4 ] = engine_actor_manager_exec_bank4;
	execute[ command_type_bank5 ] = engine_actor_manager_exec_bank5;
	execute[ command_type_bank6 ] = engine_actor_manager_exec_bank6;
	execute[ command_type_bank7 ] = engine_actor_manager_exec_bank7;
	execute[ command_type_speed ] = engine_actor_manager_exec_speed;
	execute[ command_type_steve ] = engine_actor_manager_exec_steve;
	execute[ command_type_session ] = session_exec_command;

	undo[ command_type_empty ] = empty_undo_command;
	undo[ command_type_fire ] = engine_actor_manager_undo_fire;
	undo[ command_type_jump ] = engine_actor_manager_undo_jump;
	undo[ command_type_move ] = engine_actor_manager_undo_move;
	undo[ command_type_bank4 ] = engine_actor_manager_undo_bank4;
	undo[ command_type_bank5 ] = engine_actor_manager_undo_bank5;
	undo[ command_type_bank6 ] = engine_actor_manager_undo_bank6;
	undo[ command_type_bank7 ] = engine_actor_manager_undo_bank7;
	undo[ command_type_speed ] = engine_actor_manager_undo_speed;
	undo[ command_type_steve ] = engine_actor_manager_undo_steve;
	undo[ command_type_session ] = session_undo_command;

	command_index = 0;
	add_index = 0;
	exec_index = 0;
	undo_index = 0;
}

unsigned char engine_command_manager_type( unsigned int frame, unsigned char command_type )
{
	unsigned char frame_bank;
	unsigned char frame_main;
	unsigned char shift_bank;

	// IMPORTANT if an_command is an unsigned char then this new code will fail!
	unsigned int an_command;

	frame_bank = frame / MAX_BYTE_SIZE;
	frame_main = frame % MAX_BYTE_SIZE;
	shift_bank = frame_bank << FRAME_BANK_SHIFT;
	an_command = shift_bank | command_type;

	return an_command;
}

void engine_command_manager_add( unsigned int frame, unsigned char command_type, unsigned char args )
{
	new_frame[ add_index ] = frame;
	new_command[ add_index ] = command_type;
	new_args[ add_index ] = args;
	add_index++;

	// The index will wrap from 255 to 0 naturally.
	//if( add_index >= ( MAX_COMMANDS - 1 ) )
	//{
	//	add_index = 0
	//}
}

//void engine_command_manager_addX( unsigned int frame, unsigned char command_type, unsigned int args )
//{
//	// IMPORTANT if an_command is an unsigned char then this new code will fail!
//	unsigned int an_command;
//	an_command = engine_command_manager_type( frame, command_type );
//
//	new_frame[ add_index ] = frame % MAX_BYTE_SIZE; ;// frame_main;
//	new_command[ add_index ] = an_command;
//	new_args[ add_index ] = args;
//	add_index++;
//}

void engine_command_manager_execute( unsigned int frame )
{
	unsigned int check;
	unsigned char command;
	unsigned int args;

	// If we are not on the correct frame to execute then simply return.
	check = new_frame[ exec_index ];
	if( frame != check )
	{
		return;
	}

	while( 1 )
	{
		command_index = exec_index;
		command = new_command[ command_index ];

		args = new_args[ command_index ];
		execute[ command ]( args );

		// The index will wrap from 255 to 0 naturally.
		exec_index++;
		//if( exec_index >= ( MAX_COMMANDS - 1 ) )
		//{
		//	exec_index = 0
		//}

		check = new_frame[ exec_index ];

		// If we are not on the correct frame to execute then simply return.
		if( frame != check )
		{
			break;
		}

		command = new_command[ exec_index ];
		if( ( unsigned char ) INVALID_INDEX == command )
		{
			break;
		}
	}

	// Execute all commands this frame thus increment frame index.
	undo_index = command_index;
}

void engine_command_manager_undo( unsigned int frame )
{
	unsigned char frame_bank;
	unsigned char frame_main;
	unsigned char check_main;
	unsigned char shift_bank;

	unsigned char command_main;
	unsigned char command;
	unsigned int args;

	frame_main = frame % MAX_BYTE_SIZE;
	check_main = new_frame[ undo_index ];

	// If we are not on the correct frame to execute then simply return.
	if( frame_main != check_main )
	{
		return;
	}

	frame_bank = frame / MAX_BYTE_SIZE;
	command_main = new_command[ undo_index ];
	shift_bank = command_main >> FRAME_BANK_SHIFT;
	if( frame_bank != shift_bank )
	{
		return;
	}

	while( 1 )
	{
		command_index = undo_index;
		command_main = new_command[ command_index ];
		command = command_main & FRAME_MASK_SHIFT;

		if( command_type_empty == command )
		{
			break;
		}

		args = new_args[ command_index ];
		undo[ command ]( args );

		// Decrement undo index and break if at the end...
		if( undo_index > 0 )
		{
			undo_index--;
		}
		if( 0 == command_index && 0 == undo_index )
		{
			break;
		}

		// If we are not on the correct frame to execute then simply return.
		check_main = new_frame[ undo_index ];
		if( frame_main != check_main )
		{
			break;
		}

		command_main = new_command[ undo_index ];
		shift_bank = command_main >> FRAME_BANK_SHIFT;
		if( frame_bank != shift_bank )
		{
			break;
		}
	}

	command_index = undo_index;
}

void engine_command_manager_load( unsigned int* frames, unsigned char* commands, unsigned char* args )
{
	unsigned int idx;

	for( idx = 0; idx < MAX_COMMANDS; idx++ )
	{
		new_frame[ idx ] = frames[ idx ];
		new_command[ idx ] = commands[ idx ];
		new_args[ idx ] = args[ idx ];
	}
}

void engine_command_manager_save()
{
	struct_command_object *co = &global_command_object;
	unsigned int idx;

	for( idx = 0; idx < MAX_COMMANDS; idx++ )
	{
		co->frames[ idx ] = new_frame[ idx ];
		co->commands[ idx ] = new_command[ idx ];
		co->args[ idx ] = new_args[ idx ];
	}
}

unsigned int engine_command_manager_align_undo()
{
	unsigned int undo_frame;
	unsigned char frame_main;
	unsigned char command_main;
	unsigned char shift_bank;

	exec_index = command_index;
	frame_main = new_frame[ undo_index ];
	command_main = new_command[ undo_index ];
	shift_bank = command_main >> FRAME_BANK_SHIFT;

	undo_frame = shift_bank * MAX_BYTE_SIZE;
	undo_frame += frame_main;
	return undo_frame;
}

static void empty_exec_command( unsigned char args )
{
	args = 0;
}
static void empty_undo_command( unsigned char args )
{
	args = 0;
}
static void session_exec_command( unsigned char args )
{
	args = 0;
}
static void session_undo_command( unsigned char args )
{
	args = 0;
}