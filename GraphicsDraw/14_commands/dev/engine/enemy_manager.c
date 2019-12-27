#include "enemy_manager.h"

// Global variables.
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

// Methods.
void engine_enemy_manager_init()
{
	struct_enemy_object *eo;
	unsigned char idx;
	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		eo->posnX = 0;
		eo->posnY = 0;
		eo->tileX = 0;
		eo->tileY = 0;
	}
}