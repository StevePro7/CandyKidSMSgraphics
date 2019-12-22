#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_intro = 2,
	screen_type_load = 3,
	screen_type_test = 4,
	screen_type_func = 5,

} enum_screen_type;

typedef enum tag_enum_tile_type
{
	tile_type_blank = 0,
	tile_type_candy = 1,
	tile_type_trees = 2,
	tile_type_bonusA = 3,
	tile_type_bonusB = 4,
	tile_type_bonusC = 5,
	tile_type_bonusD = 6,

} enum_tile_type;

typedef enum tag_enum_coll_type
{
	coll_type_empty = 0,
	coll_type_block = 1,

} enum_coll_type;

#endif//_ENUM_MANAGER_H_