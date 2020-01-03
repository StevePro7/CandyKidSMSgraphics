#include "title_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include <limits.h>

void screen_title_screen_load()
{
	unsigned long max = 99999;
	int min = ( unsigned int ) 0 >> 1;
	unsigned char size;

	engine_font_manager_draw_text( "TITLE SCREEN!!!", 4, 4 );

	engine_font_manager_draw_data( min, 16, 6 );
	engine_font_manager_draw_data( max, 16, 8 );
	engine_font_manager_draw_char( '0', 17, 8 );
	//max += 1;
	//engine_font_manager_draw_data( max, 16, 9 );

	size = sizeof( long );
	engine_font_manager_draw_data( size, 16, 10 );
}

void screen_title_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_title;
}