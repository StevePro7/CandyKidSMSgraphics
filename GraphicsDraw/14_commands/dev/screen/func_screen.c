#include "func_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\font_manager.h"

void screen_func_screen_load()
{
	engine_font_manager_draw_text( "HELLO FUNC SCREEN", 2, 1 );

	engine_enemy_manager_init();
	engine_enemy_manager_load();
}

void screen_func_screen_update( unsigned char *screen_type )
{
	engine_enemy_manager_draw();
	*screen_type = screen_type_func;
}