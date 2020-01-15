#include "title_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"

static unsigned char first_time;

void screen_title_screen_load()
{
	unsigned int frames[ MAX_COMMANDS ] = { 1, 3, 0, 0, 0, 0, 0, 0, 0, 0 };
	unsigned int counts[ MAX_COMMANDS ] = { 2, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
	unsigned int commands[ MAX_COMMANDS ] = { 2, 3, 1,  0, 0, 0, 0, 0, 0, 0 };
	unsigned int args[ MAX_COMMANDS ] = { 12, 23, 34,  0, 0, 0, 0, 0, 0, 0 };

	engine_font_manager_draw_text( "TITLE SCREEN!!!", 4, 0 );

	engine_command_manager_init();
	engine_delay_manager_init();
	engine_delay_manager_load( 50 );
	engine_frame_manager_init();
	engine_frame_manager_draw();

	engine_command_manager_load( 2, 3, frames, counts, commands, args );
	first_time = 1;
}

void screen_title_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned int frame;
	frame = fo->frame_count;

	engine_frame_manager_draw();
	engine_delay_manager_draw();

	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_title;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}
	frame = fo->frame_count;

	engine_command_manager_execute( frame );

	first_time = 0;
	*screen_type = screen_type_title;
}