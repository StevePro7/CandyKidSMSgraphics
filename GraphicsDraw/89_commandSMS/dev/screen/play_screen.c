#include "play_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\event_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\sprite_manager.h"

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
#pragma disable_warning 110
#endif

void screen_play_screen_load()
{
	unsigned char test;

	test = engine_storage_manager_available();
	engine_font_manager_draw_data( test, 22, 7 );

	engine_font_manager_draw_text( "PLAY SCREEN!!", 4, 0 );

	engine_storage_manager_read();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	

	*screen_type = screen_type_play;
}