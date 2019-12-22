#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_level_object
{
	unsigned char collision_array[ MAX_ROWS * MAX_COLS ];
	unsigned char drawtiles_array[ MAX_ROWS * MAX_COLS ];
	unsigned int load_cols;
	unsigned int draw_cols;

	unsigned char candyCount;
	unsigned char bonusCount;

} struct_level_object;

extern const unsigned char *levelAAdata[];
extern const unsigned char levelAAsize[];
extern const unsigned char levelAAbank[];

#endif//_LEVEL_OBJECT_H_