#include "test_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"

void screen_test_screen_load()
{
	engine_font_manager_draw_text( "HELLO TEST SCREEN", 2, 1 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}