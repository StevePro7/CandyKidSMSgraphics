#include "demo_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"

static unsigned char first_time;

void screen_demo_screen_load()
{
	engine_command_manager_init();
	engine_delay_manager_load( 5 );
	engine_frame_manager_init();

	engine_font_manager_draw_text( "DEMO SCREEN!!!!!!", 2, 0 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
}

void screen_demo_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned char input;
	unsigned int frame = fo->frame_count;
	
	engine_frame_manager_draw();
	engine_delay_manager_draw();

	proceed = engine_delay_manager_update();
	if( !proceed )
	{
		*screen_type = screen_type_demo;
		return;
	}

	input = 3 == frame;
	if( input )
	{
		engine_font_manager_draw_text( "ADD COMMANDS #3", 2, 1 );
		engine_command_manager_add( frame, command_type_jump, 22 );
	}

	engine_frame_manager_update();
	*screen_type = screen_type_demo;
}