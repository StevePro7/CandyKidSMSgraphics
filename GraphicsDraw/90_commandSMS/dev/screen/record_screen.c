#include "record_screen.h"
#include "..\engine\command_manager.h"
#include "..\engine\delay_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\frame_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\storage_manager.h"

static unsigned char first_time;

void screen_record_screen_load()
{
	unsigned char test;

	engine_command_manager_init();
	engine_frame_manager_init();
	engine_delay_manager_load( 0 );

	engine_font_manager_draw_text( "RECORD SCREEN!!", 4, 0 );
	engine_frame_manager_draw();
	engine_delay_manager_draw();
	first_time = 1;

	test = engine_storage_manager_available();
	if( test )
	{
		engine_storage_manager_read();
	}

	engine_font_manager_draw_data( test, 22, 7 );
}

void screen_record_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	unsigned char proceed;
	unsigned char input[5];
	unsigned int frame;
	frame = fo->frame_count;

	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			*screen_type = screen_type_record;
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	frame = fo->frame_count;
	input[ 0 ] = 260 == frame;
	//input[ 0 ] = 0 == frame;
	if( input[0] )
	{
		//engine_font_manager_draw_text( "FRAME 0", 15, 10 );
		engine_command_manager_add( frame, command_type_fire, 2020 );
		engine_command_manager_add( frame, command_type_jump, 1010 );
	}

	input[ 1 ] = 285 == frame;
	//input[ 1 ] = 4 == frame;
	if( input[1] )
	{
		engine_command_manager_add( frame, command_type_move, 19 );
		//engine_command_manager_add( frame, command_type_fire, 14 );
	}

	input[ 2 ] = 289 == frame;
	//input[ 2 ] = 14 == frame;
	if( input[ 2 ] )
	{
		engine_command_manager_add( frame, command_type_session, 0 );
	}

	// Execute all commands for this frame.
	engine_command_manager_execute( frame );

	// TODO - do I need to record and "end-of-session" command?
	if( input[2] )
	{
		engine_frame_manager_draw();

		engine_font_manager_draw_text( "SAVING", 20, 18 );
		engine_command_manager_save();
		//engine_storage_manager_write();
		engine_font_manager_draw_text( "SAVED!!!!", 20, 19 );

		*screen_type = screen_type_test;
		//*screen_type = screen_type_intro;
		return;
	}

	first_time = 0;
	*screen_type = screen_type_record;
}