#include "record_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"

void screen_record_screen_load()
{
	engine_font_manager_draw_text( "RECORD SCREEN", 4, 8 );
}

void screen_record_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_record;
}