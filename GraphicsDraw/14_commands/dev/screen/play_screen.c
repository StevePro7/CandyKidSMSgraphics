#include "play_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\sprite_manager.h"

void screen_play_screen_load()
{
	unsigned char homeX[] = { PRO_HOME_X, ADI_HOME_X, SUZ_HOME_X };
	unsigned char homeY[] = { PRO_HOME_Y, ADI_HOME_Y, SUZ_HOME_Y };

	engine_level_manager_init_level();
	engine_level_manager_load_level( 0, 0 );
	engine_level_manager_draw_level();
	engine_board_manager_draw_edge();

//	engine_font_manager_draw_text( "PLAY SCREEN!!", 2, 0 );

	engine_board_manager_init();
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );
	engine_enemy_manager_init( homeX, homeY );
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_board_object *bo = &global_board_object;
	unsigned char tileX = 9;
	unsigned char tileY = 2;

	//engine_sprite_manager_draw( bo->posnX[tileX], bo->posnY[tileY], 256 );
	engine_enemy_manager_draw();
	engine_gamer_manager_draw();

	*screen_type = screen_type_play;
}