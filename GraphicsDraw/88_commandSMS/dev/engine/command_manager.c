#include "command_manager.h"
#include "enum_manager.h"
#include "actor_manager.h"

// Global variable.
//struct_command_object global_command_object;
struct_command_object global_command_objects[ MAX_COMMANDS ];

#define TYPE_COMMANDS	4

static void( *execute[ TYPE_COMMANDS ] )( unsigned int index );
static void( *undo[ TYPE_COMMANDS ] )( unsigned int index );

static unsigned char command_index;
//static unsigned char command_count;

static unsigned char counter;
static unsigned int frames[ MAX_COMMANDS ];
static unsigned char commands[ MAX_COMMANDS ];

static unsigned int wip_frame[ MAX_COMMANDS ];
static unsigned char wip_count[ MAX_COMMANDS ];
static unsigned char wip_command[ MAX_COMMANDS ];


static void empty_exec_command( unsigned int index );
static void empty_undo_command( unsigned int index );

// Public methods.
void engine_command_manager_init()
{
	// IMPORTANT execute + undo must be same order!!
	execute[ command_type_empty ] = empty_exec_command;
	execute[ command_type_fire ] = engine_actor_manager_exec_fire;
	execute[ command_type_jump ] = engine_actor_manager_exec_jump;
	execute[ command_type_move ] = engine_actor_manager_exec_move;

	undo[ command_type_empty ] = empty_undo_command;
	undo[ command_type_fire ] = engine_actor_manager_undo_fire;
	undo[ command_type_jump ] = engine_actor_manager_undo_jump;
	undo[ command_type_move ] = engine_actor_manager_undo_move;

	command_index = 1;
	//command_count = 0;
	counter = 0;
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

	if( 0 == wip_count[ frame ] )
	{
		wip_frame[ frame ] = command_index;
	}

	wip_count[ frame ]++;
	wip_command[ command_index ] = command_type;

	command_index++;
	//command_count++;
	counter++;

	
}

// OLD hardcoded method
//void engine_command_manager_execute()
//{
	//unsigned int idx;
	//unsigned char cmd;

	//for( idx = 0; idx < counter; idx++ )
	//{
	//	cmd = commands[ idx ];
	//	execute[ cmd ]();
	//}

	//idx = 0;
	//cmd = commands[ idx ];
	//execute[ cmd ]( idx );
//}

void engine_command_manager_execute( unsigned int frame )
{
	unsigned int index;
	unsigned int cmd_idx;
	unsigned char count;
	unsigned char command;
	unsigned char loop;

	index = wip_frame[ frame ];
	if( command_type_empty == index )
	{
		return;
	}

	count = wip_count[ frame ];

	for( loop = 0; loop < count; loop++ )
	{
		cmd_idx = index + loop;
		command = wip_command[ cmd_idx ];

		execute[ command ]( cmd_idx );
	}
}

//void engine_command_manager_undo()
//{
//	unsigned char idx;
//	unsigned char cmd;
//
//	//for( idx = 0; idx < counter; idx++ )
//	//{
//	//	cmd = commands[ idx ];
//	//	undo[ cmd ]();
//	//}
//
//	idx = 0;
//	cmd = commands[ idx ];
//	undo[ cmd ]( idx );
//}
void engine_command_manager_undo( unsigned int frame )
{
	frame += 32;
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

static void empty_exec_command( unsigned int index )
{
	index = 0;
}
static void empty_undo_command( unsigned int index )
{
	index = 0;
}

