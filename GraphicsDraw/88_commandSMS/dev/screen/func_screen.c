#include "func_screen.h"
#include "..\engine\board_manager.h"
//#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\tile_manager.h"

static unsigned char count;
static unsigned char frame;
static unsigned char timer;

static unsigned char move1_frames;
static unsigned char move1_events;

void screen_func_screen_load()
{
	//unsigned char homeX[] = { PRO_HOME_X, ADI_HOME_X, SUZ_HOME_X };
	//unsigned char homeY[] = { PRO_HOME_Y, ADI_HOME_Y, SUZ_HOME_Y };
	engine_font_manager_draw_text( "FUNCTN SCREEN", 4, 0 );

	//engine_command_manager_init();
	//engine_command_manager_load();

	//engine_enemy_manager_init( homeX, homeY );
	//engine_enemy_manager_load();

	count = 0;
	frame = 0;
	timer = 0;

	//move1_frames = 20;
	//move1_events = 0x80;

	//engine_font_manager_draw_data( frame, 30, 0 );

	//engine_tile_manager_draw_tree( tree_type_avoid,  20, 14 );
	//engine_tile_manager_draw_tree( tree_type_avoid,  20, 16 );
	engine_tile_manager_draw_tree( tree_type_avoid,  20, 18 );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	//engine_enemy_manager_draw();

	//count++;
	//if( count >= timer )
	//{
	//	if( move1_frames == frame )
	//	{
	//		move1_frames = 255;
	//		frame = 0;

	//		if( 0x80 == move1_events )
	//		{
	//			//engine_command_move_up2();
	//		}
	//	}
	//	else
	//	{
	//		frame++;
	//	}

	//	engine_font_manager_draw_data( frame, 30, 0 );
	//	engine_enemy_manager_update();
	//	count = 0;
	//}

	*screen_type = screen_type_func;
}