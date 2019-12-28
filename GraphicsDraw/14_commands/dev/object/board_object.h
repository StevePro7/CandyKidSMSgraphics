#ifndef _BOARD_OBJECT_H_
#define _BOARD_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_board_object
{
	unsigned char positions[ TREE_ROWS ][ TREE_COLS ];

} struct_board_object;

#endif//_BOARD_OBJECT_H_