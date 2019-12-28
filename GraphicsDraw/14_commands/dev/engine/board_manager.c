#include "board_manager.h"

// Global variable.
struct_board_object global_board_object;

// Methods.
void engine_board_manager_init()
{
	struct_board_object *bo = &global_board_object;
	unsigned char loop;
	unsigned char data;
	unsigned char left = SCREEN_TILE_LEFT * TILE_HALF;

	for( loop = 0; loop < TREE_ROWS; loop++ )
	{
		data = loop * TILE_SIZE;
		bo->posnX[ loop ] = left + data;
		bo->posnY[ loop ] = data;
	}
}