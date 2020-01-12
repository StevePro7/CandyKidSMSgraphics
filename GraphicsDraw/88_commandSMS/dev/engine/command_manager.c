#include "command_manager.h"
#include "enum_manager.h"
#include "actor_manager.h"

// Global variable.
struct_command_master global_command_master;
struct_command_object global_command_objects[ MAX_COMMANDS ];

#define TYPE_COMMANDS	4

static void( *execute[ TYPE_COMMANDS ] )( unsigned int index );
static void( *undo[ TYPE_COMMANDS ] )( unsigned int index );

static unsigned char frame_index;
static unsigned char command_index;

static unsigned char add_index;
static unsigned char undo_index;

static unsigned char counter;
static unsigned int frames[ MAX_COMMANDS ];
static unsigned char commands[ MAX_COMMANDS ];


static unsigned char new_frame[ MAX_COMMANDS ];
static unsigned char new_count[ MAX_COMMANDS ];
static unsigned char new_command[ MAX_COMMANDS ];
static unsigned char new_args[ MAX_COMMANDS ];

static void empty_exec_command( unsigned int index );
static void empty_undo_command( unsigned int index );

// Public methods.
void engine_command_manager_init()
{
	struct_command_master *co = &global_command_master;

	// IMPORTANT execute + undo must be same order!!
	execute[ command_type_empty ] = empty_exec_command;
	execute[ command_type_fire ] = engine_actor_manager_exec_fire;
	execute[ command_type_jump ] = engine_actor_manager_exec_jump;
	execute[ command_type_move ] = engine_actor_manager_exec_move;

	undo[ command_type_empty ] = empty_undo_command;
	undo[ command_type_fire ] = engine_actor_manager_undo_fire;
	undo[ command_type_jump ] = engine_actor_manager_undo_jump;
	undo[ command_type_move ] = engine_actor_manager_undo_move;

	frame_index = 0;
	command_index = 0;
	add_index = 0;
	undo_index = 0;
	counter = 0;

	co->save_frames[ 0 ] = 0;
	co->save_frames[ 1 ] = 0;
	co->save_frames[ 2 ] = 0;
}

void engine_command_manager_add( unsigned int frame, unsigned char command_type, unsigned char args1, unsigned char args2 )
{
	//struct_command_object *co = &global_command_object;
	struct_command_object *co;

	//co->delta = delta;
	//co->timer = timer;

	//commands[ index ] = command;
	//commands[ 1 ] = 0;
	//commands[ 2 ] = 1;
	frames[ command_index ] = frame;
	commands[ command_index ] = command_type;

	co = &global_command_objects[ command_index ];
	co->args1 = args1;
	co->args2 = args2;

	/*if( 0 == wip_count[ frame ] )
	{
		wip_frame[ frame ] = command_index;
	}

	wip_count[ frame ]++;
	wip_command[ command_index ] = command_type;*/


	new_frame[ frame_index ] = frame;
	new_count[ frame_index ]++;
	new_command[ add_index ] = command_type;
	new_args[ add_index ] = args1;					// TODO combine the args

	//command_index++;
	add_index++;
	//command_count++;
	counter++;
}


void engine_command_manager_execute( unsigned int frame )
{
	//unsigned int index;
	//unsigned char exec_index;
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
	//exec_index = command_index  - count;

	/*for( loop = 0; loop < count; loop++ )
	{
		index = exec_index + loop;
		command = new_command[ index ];
		execute[ command ]( 0 );
	}*/

	for( loop = 0; loop < count; loop++ )
	{
		//index = exec_index + loop;
		command = new_command[ command_index++ ];
		execute[ command ]( 0 );
	}

	// Execute all commands this frame thus increment frame index.
	frame_index++;
}

void engine_command_manager_undo( unsigned int frame )
{
	//unsigned int index;
	unsigned int exec_index;
	unsigned char count;
	//unsigned char command;
	//unsigned int loop;


	// If we are not on the correct frame to execute then simply return.
	if( frame != new_frame[ frame_index ] )
	{
		return;
	}

	// Maybe now not required
	// If there are no commands to execute this frame then simply return.
	if( 0 == new_count[ frame_index ] )
	{
		return;
	}


	count = new_count[ frame_index ];
	exec_index = command_index - count;


	/*for( loop = count; loop >= 0; loop-- )
	{
		index = exec_index + loop;
		command = new_command[ index ];
		undo[ command ]( 0 );
	}
*/
	frame_index--;
}

void engine_command_manager_setframes( unsigned int* input )
{
	unsigned int idx;
	unsigned int frm;

	for( idx = 0; idx < MAX_COMMANDS; idx++ )
	{
		frm = input[ idx ];
		if( !frm )
		{
			break;
		}

		frames[ idx ] = frm;
	}
}

void engine_command_manager_set_save_frames( unsigned int* frames )
{
	struct_command_master *co = &global_command_master;
	unsigned int idx;
	unsigned int frm;

	for( idx = 0; idx < 3; idx++ )
	{
		frm = frames[ idx ];
		co->save_frames[ idx ] = frm;
	}
}

void engine_command_manager_set_playback( unsigned char* frames, unsigned char* counts, unsigned char* commands, unsigned char* args )
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

static void empty_exec_command( unsigned int index )
{
	index = 0;
}
static void empty_undo_command( unsigned int index )
{
	index = 0;
}

