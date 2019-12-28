#include "gamer_manager.h"
#include "board_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "sprite_manager.h"

#define SPRITE_TILES_KID	256 + 48

// Global variable.
struct_gamer_object global_gamer_object;

static void calcd_frame();
static void calcd_spots();

void engine_gamer_manager_init( unsigned char homeX, unsigned char homeY )
{
	struct_gamer_object *go = &global_gamer_object;

	go->homeX = homeX;
	go->homeY = homeY;
	go->tileX = homeX;
	go->tileY = homeY;
	go->delta = 0;
	go->total = 0;
	go->speed = 1;

	go->direction = direction_type_none;
	go->lifecycle = lifecycle_type_idle;

	go->image = 0;
	go->frame = 0;
	calcd_frame();
	calcd_spots();

	engine_font_manager_draw_data( go->posnX, 20, 2 );
	engine_font_manager_draw_data( go->posnY, 20, 3 );
}

void engine_gamer_manager_update()
{
	struct_gamer_object *go = &global_gamer_object;
	
}


void engine_gamer_manager_updateX()
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

			calcd_spots();
			/*go->posnX = go->tileX * TILE_SIZE;
			go->posnY = go->tileY * TILE_SIZE;*/

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

unsigned char engine_gamer_manager_direction()
{
	unsigned char direction = direction_type_none;

	unsigned char input;
	input = engine_input_manager_move_up();
	if( input )
	{
		direction = direction_type_upxx;
	}
	else
	{
		input = engine_input_manager_move_down();
		if( input )
		{
			direction = direction_type_down;
		}
		else
		{
			input = engine_input_manager_move_left();
			if( input )
			{
				direction = direction_type_left;
			}
			else
			{
				input = engine_input_manager_move_right();
				if( input )
				{
					direction = direction_type_rght;
				}
			}
		}
	}

	return direction;
}

static void calcd_frame()
{
	struct_gamer_object *go = &global_gamer_object;
	go->calcd = SPRITE_TILES_KID + go->image * 8 + go->frame * 4;
}
static void calcd_spots()
{
	struct_gamer_object *go = &global_gamer_object;
	struct_board_object *bo = &global_board_object;
	go->posnX = bo->posnX[ go->tileX ];
	go->posnY = bo->posnY[ go->tileY ];
}