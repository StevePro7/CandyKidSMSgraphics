#include "tile_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "..\banks\bank2.h"
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

void engine_tile_manager_load_coll( unsigned char *coll_type, unsigned char tile_data, unsigned char trees_avoid )
{
	if( '2' == tile_data )
	{
		if( trees_avoid )
		{
			*coll_type = coll_type_block;
			return;
		}
	}

	*coll_type = coll_type_empty;
}

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = tree_avoid__tilemap__bin;
	//index = BASE_TILE_OFFSET + ( index / 8 ) * 16 + index * 2;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + index + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + index + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + index + 2 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + index + 3 );
}