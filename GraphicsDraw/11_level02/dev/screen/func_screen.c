#include "func_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\tile_manager.h"

void screen_func_screen_load()
{
	engine_font_manager_draw_text( "HELLO FUNC SCREEN", 2, 2 );

	engine_tile_manager_draw_tree( tree_type_avoid, 4, 4 );

	engine_tile_manager_draw_tree( tree_type_death, 8, 8 );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_func;
}