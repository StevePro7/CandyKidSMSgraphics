#include "test_screen.h"
#include "..\engine\board_manager.h"
//#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\tile_manager.h"

static unsigned char count;
static unsigned char timer;

void screen_test_screen_load()
{
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );

	engine_font_manager_draw_text( "HELLO STEVEPRO SCREEN", 2, 1 );
	engine_tile_manager_draw_tree( 2, 2 );
	engine_tile_manager_draw_tree( 4, 2 );
	engine_tile_manager_draw_tree( 6, 2 );
	engine_tile_manager_draw_tree( 8, 2 );

	count = 0;
	timer = 0;
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	engine_gamer_manager_draw();

	input = engine_input_manager_move_up();
	if( input )
	{
		//engine_command_move_up();
	}
	input = engine_input_manager_move_down();
	if( input )
	{
		//engine_command_move_down();
	}
	input = engine_input_manager_move_left();
	if( input )
	{
		//engine_command_move_left();
	}
	input = engine_input_manager_move_right();
	if( input )
	{
		//engine_command_move_right();
	}

	//engine_gamer_manager_update();
	//engine_gamer_manager_text();

	count++;
	if( count >= timer )
	{
		engine_gamer_manager_update();
		//engine_gamer_manager_text();
		count = 0;
	}

	*screen_type = screen_type_test;
}