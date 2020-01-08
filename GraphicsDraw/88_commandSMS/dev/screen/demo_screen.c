#include "demo_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\input_manager.h"

void screen_demo_screen_load()
{
	engine_command_manager_init();
	engine_font_manager_draw_text( "DEMO SCREEN!", 2, 4 );
}

void screen_demo_screen_update( unsigned char *screen_type )
{
	unsigned char input;

	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_font_manager_draw_text( "HOLD DOWN", 2, 6 );
		engine_command_manager_add( 0, command_type_move, 10, 20 );
		engine_font_manager_draw_text( "HOLD END", 22, 6 );
	}
	/*input = engine_input_manager_hold_left();
	if( input )
	{
		engine_font_manager_draw_text( "HOLD LEFT", 2, 7 );
		engine_command_manager_add( 0, 2, 10, 20 );
		engine_font_manager_draw_text( "HOLD END", 22, 7 );
	}*/

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		engine_font_manager_draw_text( "FIRE1 DOWN", 2, 8 );
		engine_command_manager_execute();
		engine_font_manager_draw_text( "FIRE1 END", 22, 8 );
	}
	input = engine_input_manager_hold_fire2();
	if( input )
	{
		engine_font_manager_draw_text( "FIRE2 DOWN", 2, 10 );
		engine_command_manager_undo();
		engine_font_manager_draw_text( "FIRE2 END", 22, 10 );
	}

	*screen_type = screen_type_demo;
}