#include "play_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\event_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\sprite_manager.h"

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
#pragma disable_warning 110
#endif

static unsigned char first_time;

void screen_play_screen_load()
{
	engine_board_manager_init();
	engine_gamer_manager_init( KID_HOME_X, KID_HOME_Y );

	engine_command_manager_init();
	engine_delay_manager_load( 0 );

	engine_font_manager_draw_text( "PLAY SCREEN!!!!", 4, 0 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
	first_time = 1;
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	unsigned char gamer_direction = direction_type_none;

	unsigned char proceed;
	unsigned char input[ 5 ];
	unsigned int frame;
	frame = fo->frame_count;

	// Draw sprites first.
	engine_gamer_manager_draw();

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_play;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	// Continue...
	frame = fo->frame_count;

	// Move gamer.
	if( direction_type_none == go->direction && lifecycle_type_idle == go->lifecycle )
	{
		input[ 0 ] = 4 == frame;
		if( input[ 0 ] )
		{
			engine_command_manager_add( frame, command_type_move, direction_type_rght );
		}

		input[ 1 ] = 24 == frame;
		if( input[ 1 ] )
		{
			engine_command_manager_add( frame, command_type_move, direction_type_rght );
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


	// Execute all commands for this frame.
	engine_command_manager_execute( frame );

	first_time = 0;
	*screen_type = screen_type_play;
}