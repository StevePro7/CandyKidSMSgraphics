#include "demo_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"

void screen_demo_screen_load()
{
	engine_font_manager_draw_text( "DEMO SCREEN", 2, 4 );
}

void screen_demo_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_demo;
}