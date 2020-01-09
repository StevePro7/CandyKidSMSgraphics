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
	//printf( "EXEC fire\n" );
}
//void engine_actor_manager_exec_jump()
//{
//	engine_font_manager_draw_text( "EXEC JUMP", 2, 13 );
//	//printf( "EXEC jump\n" );
//}
void engine_actor_manager_exec_move( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "EXEC MOVE", 2, 14 );
	engine_font_manager_draw_data( co->args1, 17, 14 );
	engine_font_manager_draw_data( co->args2, 27, 14 );
	//printf( "EXEC move : %d %d\n", co->delta, co->timer );
}

// Undo commands.
void engine_actor_manager_undo_fire( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO FIRE", 2, 16 );
	//printf( "UNDO fire\n" );
}
//void engine_actor_manager_undo_jump()
//{
//	engine_font_manager_draw_text( "UNDO JUMP", 2, 17 );
//	//printf( "UNDO jump\n" );
//}
void engine_actor_manager_undo_move( unsigned int index )
{
	//struct_command_object *co = &global_command_object;
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO MOVE", 2, 18 );
	engine_font_manager_draw_data( co->args1, 17, 18 );
	engine_font_manager_draw_data( co->args2, 27, 18 );
	//printf( "UNDO move\n" );
}