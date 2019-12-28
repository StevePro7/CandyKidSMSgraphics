#include "intro_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\event_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\mask_manager.h"
#include "..\engine\move_manager.h"
#include "..\engine\sprite_manager.h"

static unsigned int frameCount;

static unsigned char count, timer;

void screen_intro_screen_load()
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

	engine_event_manager_init();

	frameCount = 0;
	engine_font_manager_draw_data( frameCount, 30, 0 );

	count = 0;
	timer = 60;
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	struct_gamer_object *go = &global_gamer_object;

	unsigned char kidMove;
	unsigned char proMove;// , adiMove, suzMove;
	unsigned char theMove;

	// Clear events.
	engine_event_manager_clear();

	// Draw sprites first.
	engine_gamer_manager_draw();
	//engine_enemy_manager_draw();


	// Update.
	count++;
	if( count < timer )
	{
		*screen_type = screen_type_play;
		return;
	}
	else
	{
		count = 0;
	}


	kidMove = 0x00;
	if( lifecycle_type_idle == go->lifecycle )
	{
		kidMove = engine_event_manager_kidMove();
		if( MOVEMENT_ALL_NONE_MASK != kidMove )
		{
			// TODO move_manager - check can go this way i.e. not blocked by tree
			engine_font_manager_draw_data( kidMove, 30, 2 );
		}
	}

	proMove = 0x00;
	theMove = kidMove + proMove;
	if( MOVEMENT_ALL_NONE_MASK != theMove )
	{
		engine_font_manager_draw_data( kidMove, 30, 3 );
		engine_event_manager_move1( frameCount, theMove );
	}

	engine_gamer_manager_update();

	frameCount++;
	engine_font_manager_draw_data( frameCount, 30, 0 );

	*screen_type = screen_type_intro;
}