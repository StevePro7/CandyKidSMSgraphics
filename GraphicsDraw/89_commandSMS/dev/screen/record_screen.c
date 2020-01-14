#include "record_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"

static unsigned char first_time;

void screen_record_screen_load()
{
	engine_command_manager_init();
	engine_delay_manager_load( 30 );
	engine_frame_manager_init();

	engine_font_manager_draw_text( "RECORD SCREEN!!", 4, 0 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
	first_time = 1;
}

void screen_record_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned char input;
	unsigned char input2;
	unsigned char input3;
	unsigned int frame;
	frame = fo->frame_count;

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_record;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	frame = fo->frame_count;
	input = 2 == frame;
	if( input )
	{
//		engine_font_manager_draw_text( "ADD COMMANDS #3", 2, 1 );
		engine_command_manager_add( frame, command_type_jump, 22, 33 );
		engine_command_manager_add( frame, command_type_move, 22, 33 );
	}

	input2 = 5 == frame;
	if( input2 )
	{
		engine_command_manager_add( frame, command_type_fire, 22, 33 );
	}

	engine_command_manager_execute( frame );

	input3 = 7 == frame;
	if( input3 )
	{
		engine_frame_manager_draw();
		*screen_type = screen_type_test;
		return;
	}

	first_time = 0;
	*screen_type = screen_type_record;
}