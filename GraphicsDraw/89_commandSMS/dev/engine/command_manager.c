#include "command_manager.h"
#include "actor_manager.h"
#include "enum_manager.h"
#include "global_manager.h"

struct_command_object global_command_object;

#define TYPE_COMMANDS	4

static void( *execute[ TYPE_COMMANDS ] )( unsigned int index );
static void( *undo[ TYPE_COMMANDS ] )( unsigned int index );

static unsigned char frame_index;
static unsigned char command_index;
static unsigned char add_index;
static unsigned char exec_index;
static unsigned char undo_index;

static unsigned int new_frame[ MAX_COMMANDS ];
static unsigned int new_count[ MAX_COMMANDS ];
static unsigned int  new_command[ MAX_COMMANDS ];
static unsigned int new_args[ MAX_COMMANDS ];

static void start_exec_command( unsigned int index );
static void start_undo_command( unsigned int index );
static void finish_exec_command( unsigned int index );
static void finish_undo_command( unsigned int index );

// Public methods.
void engine_command_manager_init()
{
	// IMPORTANT execute + undo must be same order!!
	execute[ command_type_start ] = start_exec_command;
	execute[ command_type_fire ] = engine_actor_manager_exec_fire;
	execute[ command_type_jump ] = engine_actor_manager_exec_jump;
	execute[ command_type_move ] = engine_actor_manager_exec_move;
	execute[ command_type_finish ] = finish_exec_command;

	undo[ command_type_start ] = start_undo_command;
	undo[ command_type_fire ] = engine_actor_manager_undo_fire;
	undo[ command_type_jump ] = engine_actor_manager_undo_jump;
	undo[ command_type_move ] = engine_actor_manager_undo_move;
	undo[ command_type_finish ] = finish_undo_command;

	frame_index = 0;
	command_index = 0;
	add_index = 0;
	undo_index = 0;
}

void engine_command_manager_add( unsigned int frame, unsigned char command_type, unsigned int args )
{
	new_frame[ frame_index ] = frame;
	new_count[ frame_index ]++;
	new_command[ add_index ] = command_type;
	new_args[ add_index ] = args;

	add_index++;
}


void engine_command_manager_execute( unsigned int frame )
{
	unsigned char count;
	unsigned char command;
	unsigned char loop;

	// If we are not on the correct frame to execute then simply return.
	if( frame != new_frame[ frame_index ] )
	{
		return;
	}

	// If there are no commands to execute this frame then simply return.
	if( 0 == new_count[ frame_index ] )
	{
		return;
	}

	count = new_count[ frame_index ];
	for( loop = 0; loop < count; loop++ )
	{
		exec_index = command_index;
		command = new_command[ command_index++ ];
		execute[ command ]( 0 );
	}

	// Execute all commands this frame thus increment frame index.
	undo_index = frame_index;
	frame_index++;
}

void engine_command_manager_undo( unsigned int frame )
{
	unsigned char count;
	unsigned char command;
	unsigned int loop;

	// If we are not on the correct frame to execute then simply return.
	if( frame != new_frame[ frame_index ] )
	{
		return;
	}

	// If there are no commands to execute this frame then simply return.
	if( 0 == new_count[ frame_index ] )
	{
		return;
	}

	count = new_count[ frame_index ];
	for( loop = 0; loop < count; loop++ )
	{
		command = new_command[ command_index-- ];
		undo[ command ]( 0 );						// TODO add args!
	}

	if( frame_index > 0 )
	{
		frame_index--;
	}
}

void engine_command_manager_set_playback( unsigned int* frames, unsigned int* counts, unsigned int* commands, unsigned int* args )
{
	unsigned char idx;
	for( idx = 0; idx < MAX_COMMANDS; idx++ )
	{
		new_frame[ idx ] = 0;
		new_count[ idx ] = 0;
		new_command[ idx ] = 0;
		new_args[ idx ] = 0;
	}

	for( idx = 0; idx < MAX_COMMANDS; idx++ )
	{
		new_frame[ idx ] = frames[ idx ];
		new_count[ idx ] = counts[ idx ];
		new_command[ idx ] = commands[ idx ];
		new_args[ idx ] = args[ idx ];
	}
}

unsigned char engine_command_manager_align_undo()
{
	frame_index = undo_index;
	command_index = exec_index;
	return new_frame[ undo_index ];
}

static void start_exec_command( unsigned int index )
{
	index = 0;
}
static void start_undo_command( unsigned int index )
{
	index = 0;
}
static void finish_exec_command( unsigned int index )
{
	index = 0;
}
static void finish_undo_command( unsigned int index )
{
	index = 0;
}

