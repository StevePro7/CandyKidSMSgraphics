#include "tile_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define BASE_TILE_OFFSET	64

void engine_tile_manager_load_tile( unsigned char *tile_type, unsigned char tile_data )
{
	if( '1' == tile_data )
	{
		*tile_type = tile_type_candy;
		return;
	}
	if( '2' == tile_data )
	{
		*tile_type = tile_type_trees;
		return;
	}
	if( '3' == tile_data )
	{
		*tile_type = tile_type_bonusA;
		return;
	}
	if( '4' == tile_data )
	{
		*tile_type = tile_type_bonusB;
		return;
	}
	if( '5' == tile_data )
	{
		*tile_type = tile_type_bonusC;
		return;
	}
	if( '6' == tile_data )
	{
		*tile_type = tile_type_bonusD;
		return;
	}

	*tile_type = tile_type_blank;
}

void engine_tile_manager_load_coll( unsigned char *coll_type, unsigned char tile_data )
{
	if( '2' == tile_data )
	{
		*coll_type = coll_type_block;
		return;
	}

	*coll_type = coll_type_empty;
}

//void engine_tile_manager_draw_loop()
//{
//	unsigned char x;
//	unsigned char y;
//
//	/*for( x = 0; x < TREE_WIDE * 2; x += 2 )
//	{
//		draw_tree( x, 0 );
//		draw_tree( x, 22 );
//	}
//	for( y = 2; y < TREE_HIGH * 2 - 2 ; y += 2 )
//	{
//		draw_tree( 0, y );
//		draw_tree( 22, y );
//	}*/
//}

void engine_tile_manager_draw_blank( unsigned char x, unsigned char y )
{
	engine_font_manager_draw_char( ' ', x + 0, y + 0 );
	engine_font_manager_draw_char( ' ', x + 1, y + 0 );
	engine_font_manager_draw_char( ' ', x + 0, y + 1 );
	engine_font_manager_draw_char( ' ', x + 1, y + 1 );
}

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	engine_tile_manager_draw_blank( x, y );
	if( tile_type_trees != index )
	{
		return;
	}

	engine_tile_manager_draw_tree( x, y );
}

void engine_tile_manager_draw_tree( unsigned char x, unsigned char y )
{
	const unsigned char *pnt = tree_avoid__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + 2 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + 3 );
}