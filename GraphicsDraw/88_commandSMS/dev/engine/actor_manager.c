#include "actor_manager.h"
#include "command_manager.h"
#include "font_manager.h"
//#include <stdio.h>

// Public method.
void engine_actor_manager_update()
{
}

// Execute commands.
void engine_actor_manager_exec_fire( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "EXEC FIRE", 2, 12 );
}
void engine_actor_manager_exec_jump( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "EXEC JUMP", 2, 13 );
}
void engine_actor_manager_exec_move( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "EXEC MOVE", 2, 14 );
	engine_font_manager_draw_data( co->args1, 17, 14 );
	engine_font_manager_draw_data( co->args2, 27, 14 );
}

// Undo commands.
void engine_actor_manager_undo_fire( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO FIRE", 2, 16 );
}
void engine_actor_manager_undo_jump( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO JUMP", 2, 17 );
}
void engine_actor_manager_undo_move( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO MOVE", 2, 18 );
	engine_font_manager_draw_data( co->args1, 17, 18 );
	engine_font_manager_draw_data( co->args2, 27, 18 );
}