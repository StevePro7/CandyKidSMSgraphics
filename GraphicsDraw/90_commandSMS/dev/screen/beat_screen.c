#include "beat_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"

static unsigned char first_time;

void screen_beat_screen_load()
{
	engine_command_manager_init();
	engine_delay_manager_load( 10 );
	engine_frame_manager_init();

	engine_font_manager_draw_text( "BEAT SCREEN!!", 4, 2 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
	first_time = 1;
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	//unsigned char input;
	unsigned int frame = fo->frame_count;

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_beat;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	frame = fo->frame_count;

	// Execute all commands for this frame.
	engine_command_manager_execute( frame );

	first_time = 0;
	*screen_type = screen_type_beat;
}