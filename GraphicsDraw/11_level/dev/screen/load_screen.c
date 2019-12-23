#include "load_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\tile_manager.h"

void screen_load_screen_load()
{
	engine_level_manager_init_level();
	engine_level_manager_load_level( 0, 0 );
	engine_tile_manager_draw_loop();
	//engine_level_manager_draw_level();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_load;
}