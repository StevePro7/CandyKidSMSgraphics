#include "screen_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Screens
#include "..\screen\none_screen.h"
#include "..\screen\splash_screen.h"
#include "..\screen\title_screen.h"
#include "..\screen\intro_screen.h"
#include "..\screen\load_screen.h"
#include "..\screen\demo_screen.h"
#include "..\screen\play_screen.h"
#include "..\screen\record_screen.h"
#include "..\screen\save_screen.h"
#include "..\screen\test_screen.h"
#include "..\screen\func_screen.h"

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

void engine_screen_manager_init( unsigned char open_screen_type )
{
	next_screen_type = open_screen_type;
	curr_screen_type = screen_type_none;

	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	load_method[ screen_type_title ] = screen_title_screen_load;
	load_method[ screen_type_intro ] = screen_intro_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_demo ] = screen_demo_screen_load;
	load_method[ screen_type_play ] = screen_play_screen_load;
	load_method[ screen_type_record ] = screen_record_screen_load;
	load_method[ screen_type_save ] = screen_save_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	load_method[ screen_type_func ] = screen_func_screen_load;

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	update_method[ screen_type_title ] = screen_title_screen_update;
	update_method[ screen_type_intro ] = screen_intro_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_demo ] = screen_demo_screen_update;
	update_method[ screen_type_play ]= screen_play_screen_update;
	update_method[ screen_type_record ] = screen_record_screen_update;
	update_method[ screen_type_save ] = screen_save_screen_update;
	update_method[ screen_type_test ] = screen_test_screen_update;
	update_method[ screen_type_func ] = screen_func_screen_update;
}

void engine_screen_manager_update()
{
	if( curr_screen_type != next_screen_type )
	{
		curr_screen_type = next_screen_type;
		load_method[ curr_screen_type ]();
	}

	update_method[ curr_screen_type ]( &next_screen_type );
}