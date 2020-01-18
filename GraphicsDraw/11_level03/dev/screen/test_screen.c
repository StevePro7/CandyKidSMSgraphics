#include "test_screen.h"
#include "..\engine\boss_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"

void screen_test_screen_load()
{
	engine_boss_manager_load();
	engine_font_manager_draw_text( "TEST SCREEN...!!", 2, 2 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}