#include "actor_manager.h"
#include "command_manager.h"
#include "font_manager.h"
//#include <stdio.h>

static void print( char *text, unsigned int idx, unsigned char x, unsigned char y );
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
	//engine_font_manager_draw_data( co->args1, 17, 14 );
	//engine_font_manager_draw_data( co->args2, 27, 14 );
}
void engine_actor_manager_exec_move( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "EXEC MOVE", 2, 14 );
	//engine_font_manager_draw_data( co->args1, 17, 14 );
	//engine_font_manager_draw_data( co->args2, 27, 14 );
}

// Undo commands.
void engine_actor_manager_undo_fire( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO FIRE", 2, 12 );
}
void engine_actor_manager_undo_jump( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO JUMP", 2, 13 );
}
void engine_actor_manager_undo_move( unsigned int index )
{
	struct_command_object *co = &global_command_objects[ index ];
	engine_font_manager_draw_text( "UNDO MOVE", 2, 14 );
	//engine_font_manager_draw_data( co->args1, 17, 18 );
	//engine_font_manager_draw_data( co->args2, 27, 18 );
}

static void print( char *text, unsigned int idx, unsigned char args1, unsigned char args2 )
{
	engine_font_manager_draw_text( text, 2, idx + 4 );
	engine_font_manager_draw_data( args1, 17, idx + 4 );
	engine_font_manager_draw_data( args2, 27, idx + 4 );
}