#include "gamer_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
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

	go->direction = direction_type_none;
	go->lifecycle = lifecycle_type_idle;

	//go->direction = direction_type_rght;
	//go->lifecycle = lifecycle_type_move;

	go->image = 0;
	go->frame = 0;
	calcd_frame();

	engine_font_manager_draw_data( go->posnX, 20, 2 );
	engine_font_manager_draw_data( go->posnY, 20, 3 );
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
		go->delta += go->speed;
		go->total += go->speed;

		if( direction_type_upxx == go->direction )
		{
			go->posnY -= go->speed;
		}
		else if( direction_type_down == go->direction )
		{
			go->posnY += go->speed;
		}
		else if( direction_type_left == go->direction )
		{
			go->posnX -= go->speed;
		}
		else if( direction_type_rght == go->direction )
		{
			go->posnX += go->speed;
		}

		if( go->total >= TILE_SIZE )
		{
			if( direction_type_upxx == go->direction )
			{
				go->tileY--;
			}
			else if( direction_type_down == go->direction )
			{
				go->tileY++;
			}
			else if( direction_type_left == go->direction )
			{
				go->tileX--;
			}
			else if( direction_type_rght == go->direction )
			{
				go->tileX++;
			}

			go->posnX = go->tileX * TILE_SIZE;
			go->posnY = go->tileY * TILE_SIZE;

			go->direction = direction_type_none;
			go->lifecycle = lifecycle_type_idle;
			go->delta = 0;
			go->total = 0;

			engine_font_manager_draw_data( go->posnX, 20, 2 );
			engine_font_manager_draw_data( go->posnY, 20, 3 );
		}

		if( go->delta > TILE_HALF)
		{
			go->frame = 1 - go->frame;
			go->delta = 0;
			calcd_frame();
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

void engine_gamer_manager_move( unsigned char direction )
{
	struct_gamer_object *go = &global_gamer_object;
	go->direction = direction;
	go->lifecycle = lifecycle_type_move;
	go->frame = 1;
	calcd_frame();
}

static void calcd_frame()
{
	struct_gamer_object *go = &global_gamer_object;
	go->calcd = SPRITE_TILES_KID + go->image * 8 + go->frame * 4;
}