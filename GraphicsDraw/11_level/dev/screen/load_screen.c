#include "load_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\hack_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\tile_manager.h"

void screen_load_screen_load()
{
	struct_hack_object *ho = &global_hack_object;

	engine_level_manager_init_level();
	engine_level_manager_load_level( ho->hack_world, ho->hack_round );
	engine_level_manager_draw_level();

	engine_font_manager_draw_data( ho->hack_world + 1, 31, 0 );
	engine_font_manager_draw_data( ho->hack_round + 1, 31, 1 );
}

void screen_load_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char input;

	input = engine_input_manager_hold_right();
	if( input )
	{
		ho->hack_round++;
		if( ho->hack_round >= MAX_ROUNDS )
		{
			ho->hack_round = 0;
		}
		engine_level_manager_init_level();
		engine_level_manager_load_level( ho->hack_world, ho->hack_round );
		engine_level_manager_draw_level();

		engine_font_manager_draw_data( ho->hack_world + 1, 31, 0 );
		engine_font_manager_draw_data( ho->hack_round + 1, 31, 1 );
	}

	input = engine_input_manager_hold_down();
	if( input )
	{
		ho->hack_world++;
		if( ho->hack_world >= MAX_WORLDS )
		{
			ho->hack_world = 0;
		}
		engine_level_manager_init_level();
		engine_level_manager_load_level( ho->hack_world, ho->hack_round );
		engine_level_manager_draw_level();

		engine_font_manager_draw_data( ho->hack_world + 1, 31, 0 );
		engine_font_manager_draw_data( ho->hack_round + 1, 31, 1 );
	}

	*screen_type = screen_type_load;
}