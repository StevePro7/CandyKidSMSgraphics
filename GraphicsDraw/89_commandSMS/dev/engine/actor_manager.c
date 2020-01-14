#include "actor_manager.h"
#include "font_manager.h"

static void print( char *text, unsigned int idx, unsigned intx );
// Public method.
void engine_actor_manager_update()
{
}

// Execute commands.
void engine_actor_manager_exec_fire( unsigned int args )
{
	engine_font_manager_draw_text( "EXEC FIRE", 2, 12 );
	engine_font_manager_draw_data( args, 17, 12 );
}
void engine_actor_manager_exec_jump( unsigned int args )
{
	engine_font_manager_draw_text( "EXEC JUMP", 2, 13 );
	engine_font_manager_draw_data( args, 17, 13 );
}
void engine_actor_manager_exec_move( unsigned int args )
{
	engine_font_manager_draw_text( "EXEC MOVE", 2, 14 );
	engine_font_manager_draw_data( args, 17, 14 );
}

// Undo commands.
void engine_actor_manager_undo_fire( unsigned int args )
{
	//engine_font_manager_draw_text( "UNDO FIRE", 2, 12 );
	engine_font_manager_draw_text( "         ", 2, 12 );
	args = 0;
}
void engine_actor_manager_undo_jump( unsigned int args )
{
	//engine_font_manager_draw_text( "UNDO JUMP", 2, 13 );
	engine_font_manager_draw_text( "         ", 2, 13 );
	args = 0;
}
void engine_actor_manager_undo_move( unsigned int args )
{
	//engine_font_manager_draw_text( "UNDO MOVE", 2, 14 );
	engine_font_manager_draw_text( "         ", 2, 14 );
	args = 0;
}

static void print( char *text, unsigned int idx, unsigned int args1 )
{
	engine_font_manager_draw_text( text, 2, idx + 4 );
	engine_font_manager_draw_data( args1, 17, idx + 4 );
}