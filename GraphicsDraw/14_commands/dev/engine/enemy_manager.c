#include "enemy_manager.h"
#include "enum_manager.h"
#include "sprite_manager.h"

#define SPRITE_TILES_PRO	256 + 0

// Global variables.
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

static void calcd_frame( unsigned char index );

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

		eo->image = 3;
		eo->frame = 0;
		calcd_frame( idx );
	}
}

void engine_enemy_manager_load()
{
	struct_enemy_object *eo = &global_enemy_objects[ mama_type_pro ];
	eo->posnX = 144;
	eo->posnY = 128;
	eo->tileX = 9;
	eo->tileY = 9;
}

void engine_enemy_manager_draw()
{
	struct_enemy_object *eo = &global_enemy_objects[ mama_type_pro ];
	engine_sprite_manager_draw( eo->posnX, eo->posnY, eo->calcd );
}

static void calcd_frame( unsigned char index )
{
	struct_enemy_object *eo = &global_enemy_objects[ index ];
	eo->calcd = SPRITE_TILES_PRO + eo->image * 8 + eo->frame * 4;
}