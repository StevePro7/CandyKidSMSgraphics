#include "func_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\engine\tile_manager.h"

void screen_func_screen_load()
{
	unsigned char idx;

	engine_font_manager_draw_text( "HELLO FUNC SCREEN", 2, 2 );

	engine_tile_manager_draw_tree( tree_type_avoid, 4, 4 );
	engine_tile_manager_draw_tree( tree_type_death, 6, 6 );

	engine_tile_manager_draw_bonus( tile_type_bonusA, 1, 10, 8 );
	engine_tile_manager_draw_bonus( tile_type_bonusB, 1, 14, 8 );
	engine_tile_manager_draw_bonus( tile_type_bonusC, 1, 18, 8 );
	engine_tile_manager_draw_bonus( tile_type_bonusD, 1, 22, 8 );

	engine_tile_manager_draw_bonus( tile_type_bonusA, 2, 10, 12 );
	engine_tile_manager_draw_bonus( tile_type_bonusB, 2, 14, 12 );
	engine_tile_manager_draw_bonus( tile_type_bonusC, 2, 18, 12 );
	engine_tile_manager_draw_bonus( tile_type_bonusD, 2, 22, 12 );

	for( idx = 0; idx < 12; idx++ )
	{
		engine_tile_manager_draw_candy( idx, idx * 2 + 2, 18 );
	}
}

void screen_func_screen_update( unsigned char *screen_type )
{
	engine_sprite_manager_draw_entity( 128, 96, 256 + 96 );
	*screen_type = screen_type_func;
}