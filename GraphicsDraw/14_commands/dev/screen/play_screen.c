#include "play_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\sprite_manager.h"

void screen_play_screen_load()
{
	engine_level_manager_init_level();
	engine_level_manager_load_level( 0, 0 );
	engine_level_manager_draw_level();
//	engine_font_manager_draw_text( "PLAY SCREEN!!", 2, 0 );

	engine_board_manager_init();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_board_object *bo = &global_board_object;
	unsigned char tileX = 9;
	unsigned char tileY = 2;

	engine_sprite_manager_draw( bo->posnX[tileX], bo->posnY[tileY], 256 );
	*screen_type = screen_type_play;
}