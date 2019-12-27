#include "func_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\font_manager.h"

static unsigned char count;
static unsigned char frame;
static unsigned char timer;

void screen_func_screen_load()
{
	engine_font_manager_draw_text( "HELLO FUNC SCREEN!!", 2, 1 );

	engine_command_manager_init();

	engine_enemy_manager_init();
	engine_enemy_manager_load();

	count = 0;
	frame = 0;
	timer = 60;

	engine_font_manager_draw_data( frame, 30, 0 );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	engine_enemy_manager_draw();

	count++;
	if( count >= timer )
	{
		frame++;
		engine_font_manager_draw_data( frame, 30, 0 );
		//engine_enemy_manager_update();
		count = 0;
	}

	*screen_type = screen_type_func;
}