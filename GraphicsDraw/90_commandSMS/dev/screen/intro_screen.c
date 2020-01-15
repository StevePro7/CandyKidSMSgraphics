#include "intro_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\event_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\mask_manager.h"
#include "..\engine\move_manager.h"
#include "..\engine\sprite_manager.h"

void screen_intro_screen_load()
{
	engine_font_manager_draw_text( "INTRO SCREEN...!!", 2, 0 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}