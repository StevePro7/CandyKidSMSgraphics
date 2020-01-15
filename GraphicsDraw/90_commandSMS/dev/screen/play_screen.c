#include "play_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\event_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\sprite_manager.h"

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
#pragma disable_warning 110
#endif

void screen_play_screen_load()
{
	engine_board_manager_init();
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );
	engine_command_manager_init();

	engine_font_manager_draw_text( "PLAY SCREEN!!!!", 4, 0 );
}

void screen_play_screen_update( unsigned char *screen_type )
{
	// Draw sprites first.
	engine_gamer_manager_draw();

	*screen_type = screen_type_play;
}