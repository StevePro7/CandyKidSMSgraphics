#include "command_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "gamer_manager.h"

void engine_command_move_left()
{
	struct_gamer_object *go = &global_gamer_object;
	if( lifecycle_type_move == go->lifecycle )
	{
		return;
	}

	/*go->direction = direction_type_left;
	go->lifecycle = lifecycle_type_move;*/
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
	/*go->direction = direction_type_rght;
	go->lifecycle = lifecycle_type_move;*/
}