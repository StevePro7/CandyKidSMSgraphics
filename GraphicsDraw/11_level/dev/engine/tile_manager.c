#include "tile_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "..\banks\bank2.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"
#include <stdlib.h>

#define BASE_TILE_OFFSET	64

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = tree_avoid__tilemap__bin;
	//index = BASE_TILE_OFFSET + ( index / 8 ) * 16 + index * 2;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + index + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + index + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + index + 2 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + index + 3 );
}