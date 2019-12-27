#include "command_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "gamer_manager.h"

// Global variable.
struct_command_object global_command_object;

void engine_command_manager_init()
{
	struct_command_object *co = &global_command_object;
	unsigned int idx;

	co->frame = 0;
	co->command = 0;

	for( idx = 0; idx < MAX_MOVES_COMMANDS; idx++ )
	{
		co->move1_frames[ idx ] = 0;
		co->move1_events[ idx ] = 0;
		co->move2_frames[ idx ] = 0;
		co->move2_events[ idx ] = 0;
	}

	for( idx = 0; idx < MAX_SPEED_COMMANDS; idx++ )
	{
		co->speed_frames[ idx ] = 0;
		co->speed_events[ idx ] = 0;
	}
}

void engine_command_manager_load()
{
	struct_command_object *co = &global_command_object;
	co->frame = 10;
	co->command = 0x80;

	co->move1_frames[ 0 ] = 10;
	co->move1_events[ 0 ] = 0x80;
}

void engine_command_move_up()
{
	struct_gamer_object *go = &global_gamer_object;
	if( lifecycle_type_move == go->lifecycle )
	{
		return;
	}

	engine_gamer_manager_move( direction_type_upxx );
}

void engine_command_move_down()
{
	struct_gamer_object *go = &global_gamer_object;
	if( lifecycle_type_move == go->lifecycle )
	{
		return;
	}

	engine_gamer_manager_move( direction_type_down );
}

void engine_command_move_left()
{
	struct_gamer_object *go = &global_gamer_object;
	if( lifecycle_type_move == go->lifecycle )
	{
		return;
	}

	engine_gamer_manager_move( direction_type_left );
}

void engine_command_move_right()
{
	struct_gamer_object *go = &global_gamer_object;
	if( lifecycle_type_move == go->lifecycle )
	{
		return;
	}

	engine_gamer_manager_move( direction_type_rght );
}