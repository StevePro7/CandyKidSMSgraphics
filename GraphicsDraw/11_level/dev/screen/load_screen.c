#include "load_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\hack_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\tile_manager.h"

void screen_load_screen_load()
{
	struct_hack_object *ho = &global_hack_object;

	engine_level_manager_init_level();
	engine_level_manager_load_level( ho->hack_world, ho->hack_round );
	//engine_tile_manager_draw_loop();
	engine_level_manager_draw_level();

	engine_font_manager_draw_data( ho->hack_world, 31, 0 );
	engine_font_manager_draw_data( ho->hack_round, 31, 1 );

	//engine_font_manager_draw_text( "123456", 26, 0 );
}

void screen_load_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_load;
}