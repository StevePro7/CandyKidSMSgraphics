#include "gamer_manager.h"
#include "sprite_manager.h"

// Global variable.
struct_gamer_object global_gamer_object;

void engine_gamer_manager_init()
{
	struct_gamer_object *go = &global_gamer_object;

	go->posnX = 32;
	go->posnY = 32;
	go->tileX = 2;
	go->tileY = 2;
}

void engine_gamer_manager_draw()
{
	struct_gamer_object *go = &global_gamer_object;

	engine_sprite_manager_draw( go->posnX, go->posnY, 256 );
}