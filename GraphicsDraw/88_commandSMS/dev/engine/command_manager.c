#include "command_manager.h"
#include "enum_manager.h"
#include "actor_manager.h"

// Global variable.
struct_command_object global_command_object;
struct_command_object global_command_objects[ MAX_COMMANDS ];

#define TYPE_COMMANDS	4

static void( *execute[ TYPE_COMMANDS ] )( );
static void( *undo[ TYPE_COMMANDS ] )( );

static unsigned char command_index;
static unsigned char command_count;

static unsigned char counter;
static unsigned char commands[ MAX_COMMANDS ];

static void empty_exec_command();
static void empty_undo_command();

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

	command_index = 0;
	command_count = 0;
	counter = 0;
}

void engine_command_manager_add( unsigned char index, unsigned char command, unsigned char delta, unsigned char timer )
{
	struct_command_object *co = &global_command_object;
	struct_command_object *co2;

	co->delta = delta;
	co->timer = timer;

	commands[ index ] = command;
	//commands[ 1 ] = 0;
	//commands[ 2 ] = 1;

	co2 = &global_command_objects[ command_index ];

	command_index++;
	command_count++;
	counter++;
}

void engine_command_manager_execute()
{
	unsigned char idx;
	unsigned char cmd;

	for( idx = 0; idx < counter; idx++ )
	{
		cmd = commands[ idx ];
		execute[ cmd ]();
	}
}

void engine_command_manager_undo()
{
	unsigned char idx;
	unsigned char cmd;

	for( idx = 0; idx < counter; idx++ )
	{
		cmd = commands[ idx ];
		undo[ cmd ]();
	}
}

static void empty_exec_command()
{
}
static void empty_undo_command()
{
}