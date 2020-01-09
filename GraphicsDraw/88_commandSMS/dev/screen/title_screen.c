#include "title_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"
//#include <limits.h>

void screen_title_screen_load()
{
	unsigned int frames[ MAX_COMMANDS ] = { 1, 1, 4, 0, 0, 0, 0, 0, 0, 0 };
	unsigned int commands[ MAX_COMMANDS ] = { 2, 3, 2,  0, 0, 0, 0, 0, 0, 0 };		// TODO add commands

	//unsigned long max = 99999;
	//int min = ( unsigned int ) 0 >> 1;
	//unsigned char size;
	engine_font_manager_draw_text( "TITLE SCREEN!!!", 4, 4 );

	//size = sizeof( long );
	//engine_font_manager_draw_data( size, 16, 10 );

	engine_command_manager_init();
	engine_delay_manager_init();
	engine_delay_manager_load( 60 );
	engine_frame_manager_init();
	engine_frame_manager_draw();

	engine_command_manager_setframes( frames );									// TODO add commands
}

void screen_title_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
//	unsigned char input;
	unsigned char proceed = engine_delay_manager_update();
	if( !proceed )
	{
		*screen_type = screen_type_title;
		return;
	}

	/*if( 0 == fo->frame_delta )
	{

	}

	engine_font_manager_draw_text( "     ", 10, 10 );
	input = engine_input_manager_move_fire1();
	if( input )
	{
		engine_font_manager_draw_text( "FIRE!", 10, 10 );
	}*/

	engine_frame_manager_update();
	engine_frame_manager_draw();

	*screen_type = screen_type_title;
}