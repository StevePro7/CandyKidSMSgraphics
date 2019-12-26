#include "test_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\tile_manager.h"

void screen_test_screen_load()
{
	engine_gamer_manager_init();

	engine_font_manager_draw_text( "HELLO STEVEPRO SCREEN", 2, 1 );
	engine_tile_manager_draw_tree( 2, 2 );
	engine_tile_manager_draw_tree( 4, 2 );
	engine_tile_manager_draw_tree( 6, 2 );
	engine_tile_manager_draw_tree( 8, 2 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	engine_gamer_manager_draw();
	*screen_type = screen_type_test;
}