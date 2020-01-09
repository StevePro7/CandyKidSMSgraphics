#include "demo_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"

void screen_demo_screen_load()
{
	engine_command_manager_init();
	engine_delay_manager_load( 60 );
	engine_frame_manager_init();

	engine_font_manager_draw_text( "DEMO SCREEN!!!!!!", 2, 4 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
}

void screen_demo_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned char input;
	unsigned char frame = fo->frame_count;
	
	engine_frame_manager_draw();

	engine_delay_manager_draw();
	proceed = engine_delay_manager_update();
	if( !proceed )
	{
		*screen_type = screen_type_demo;
		return;
	}

	

	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_font_manager_draw_text( "HOLD DOWN", 2, 6 );
		engine_command_manager_add( frame, command_type_jump, 0, 0 );
		engine_command_manager_add( frame, command_type_move, 10, 20 );

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


	engine_frame_manager_update();

	*screen_type = screen_type_demo;
}