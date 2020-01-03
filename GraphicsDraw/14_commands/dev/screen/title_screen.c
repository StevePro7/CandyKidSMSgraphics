#include "title_screen.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
//#include <limits.h>

void screen_title_screen_load()
{
	//unsigned long max = 99999;
	//int min = ( unsigned int ) 0 >> 1;
	//unsigned char size;
	engine_font_manager_draw_text( "TITLE SCREEN!", 4, 4 );

	//size = sizeof( long );
	//engine_font_manager_draw_data( size, 16, 10 );

	engine_delay_manager_init();
	engine_delay_manager_load( 60 );
	engine_frame_manager_init();
	engine_frame_manager_draw();
}

void screen_title_screen_update( unsigned char *screen_type )
{
	unsigned char proceed = engine_delay_manager_update();
	if( !proceed )
	{
		*screen_type = screen_type_title;
		return;
	}

	engine_frame_manager_update();
	engine_frame_manager_draw();
	*screen_type = screen_type_title;
}