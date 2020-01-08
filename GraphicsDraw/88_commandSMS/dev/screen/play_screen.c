#include "play_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\event_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\mask_manager.h"
#include "..\engine\move_manager.h"
#include "..\engine\state_manager.h"
#include "..\engine\sprite_manager.h"

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
#pragma disable_warning 110
#endif


static unsigned int frameCount;

static unsigned char count, timer;

void screen_play_screen_load()
{
	unsigned char homeX[] = { PRO_HOME_X, ADI_HOME_X, SUZ_HOME_X };
	unsigned char homeY[] = { PRO_HOME_Y, ADI_HOME_Y, SUZ_HOME_Y };

	engine_board_manager_draw_edge();

	engine_font_manager_draw_text( "PLAY SCREEN", 2, 0 );

	engine_board_manager_init();
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );
	engine_enemy_manager_init( homeX, homeY );

	engine_command_manager_init();
	engine_event_manager_init();

	frameCount = 0;
	engine_font_manager_draw_data( frameCount, 30, 0 );

	engine_state_manager_init();
	count = 0;
	timer = 0;
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_gamer_object *go = &global_gamer_object;
	unsigned char gamer_direction = direction_type_none;

	// Clear events.
	engine_event_manager_clear();

	// Draw sprites first.
	engine_gamer_manager_draw();

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


	// Gamer.
	if( direction_type_none == go->direction && lifecycle_type_idle == go->lifecycle )
	{
		engine_font_manager_draw_data( gamer_direction, 20, 9 );
		gamer_direction = engine_gamer_manager_direction();
		engine_font_manager_draw_data( gamer_direction, 20, 5 );

		gamer_direction = engine_move_manager_check( gamer_direction );
		engine_font_manager_draw_data( gamer_direction, 20, 6 );

		// TODO hardcoded!
		if( direction_type_none != gamer_direction )
		{
			engine_event_manager_add_event( 0x01, gamer_direction );
		}
	}
	else if( direction_type_none != go->direction && lifecycle_type_move == go->lifecycle )
	{
		//  warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
		engine_gamer_manager_update();
	}

	if( direction_type_none != go->direction && lifecycle_type_idle == go->lifecycle )
	{
		// Check collision.
		engine_gamer_manager_stop();
	}

	engine_event_manager_process_events();

	frameCount++;
	//engine_font_manager_draw_data( frameCount, 30, 0 );

	*screen_type = screen_type_play;
}