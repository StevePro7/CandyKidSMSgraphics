#include "gamer_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"

#define SPRITE_TILES_KID	256 + 48

// Global variable.
struct_gamer_object global_gamer_object;

static void calcd_frame();

void engine_gamer_manager_init()
{
	struct_gamer_object *go = &global_gamer_object;

	go->posnX = 32;
	go->posnY = 32;
	go->tileX = 2;
	go->tileY = 2;
	go->delta = 0;
	go->total = 0;
	go->speed = 1;
	//go->direction = direction_type_none;
	//go->lifecycle = lifecycle_type_idle;

	go->direction = direction_type_rght;
	go->lifecycle = lifecycle_type_move;

	go->image = 0;
	go->frame = 0;
	calcd_frame();
}

void engine_gamer_manager_update()
{
	struct_gamer_object *go = &global_gamer_object;

	if( lifecycle_type_idle == go->lifecycle )
	{
		return;
	}

	if( lifecycle_type_move == go->lifecycle )
	{
		if( direction_type_rght == go->direction )
		{
			go->delta += go->speed;
			go->posnX += go->speed;
			go->total += go->speed;
			if( go->delta >= 8 )
			{
				go->frame = 1 - go->frame;
				go->delta = 0;
				calcd_frame();
			}

			if( go->total >= 16 )
			{
				go->tileX++;
				go->posnX = go->tileX * 16;
				go->direction = direction_type_none;
				go->lifecycle = lifecycle_type_idle;
				go->delta = 0;
				go->total = 0;
			}

		}
	}
}

void engine_gamer_manager_draw()
{
	struct_gamer_object *go = &global_gamer_object;

	engine_sprite_manager_draw( go->posnX, go->posnY, go->calcd );
}

void engine_gamer_manager_text()
{
	struct_gamer_object *go = &global_gamer_object;

	engine_font_manager_draw_data( go->delta, 20, 2 );
	engine_font_manager_draw_data( go->total, 20, 3 );
}

static void calcd_frame()
{
	struct_gamer_object *go = &global_gamer_object;
	go->calcd = SPRITE_TILES_KID + go->image * 8 + go->frame * 4;
}