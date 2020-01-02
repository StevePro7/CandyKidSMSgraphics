#include "tile_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "..\banks\bank2.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define BASE_TILE_OFFSET	26

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

// TODO rename this as is too generic!
void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	engine_tile_manager_draw_blank( x, y );
	if( tile_type_trees != index )
	{
		return;
	}

	engine_tile_manager_draw_tree( tree_type_avoid, x, y );
}

void engine_tile_manager_draw_blank( unsigned char x, unsigned char y )
{
	engine_font_manager_draw_char( ' ', x + 0, y + 0 );
	engine_font_manager_draw_char( ' ', x + 1, y + 0 );
	engine_font_manager_draw_char( ' ', x + 0, y + 1 );
	engine_font_manager_draw_char( ' ', x + 1, y + 1 );
}

void engine_tile_manager_draw_tree( unsigned char type, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = game_tiles__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + ( type * 2 ) + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + ( type * 2 ) + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + ( type * 2 ) + BASE_TILE_OFFSET + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + ( type * 2 ) + BASE_TILE_OFFSET + 1 );
}