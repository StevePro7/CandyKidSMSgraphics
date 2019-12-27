#include "command_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "gamer_manager.h"

// Global variable.
struct_command_object global_command_object;

void engine_command_manager_init()
{
	struct_command_object *co = &global_command_object;
	co->frame = 0;
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