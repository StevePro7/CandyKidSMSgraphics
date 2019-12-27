#include "screen_manager.h"
#include "font_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"SPRITE TILES LOADED..."

static void draw_titile();
static void draw_tree( unsigned char x, unsigned char y );

void engine_screen_manager_init()
{
	/*unsigned char x;
	unsigned char y;
	for( x = 2; x < 32; x += 2 )
	{
		draw_tree( x, 0 );
		draw_tree( x, 22 );
	}

	for( y = 2; y < 22; y += 2 )
	{
		draw_tree( 2, y );
		draw_tree( 30, y );
	}*/

	draw_titile();
}

void engine_screen_manager_update()
{
}

static void draw_titile()
{
	const unsigned int *pnt = ( const unsigned int * ) game_title__tilemap__bin;

	unsigned char x = 4;
	unsigned char y = 2;

	unsigned char i;
	unsigned char j;

	// CANDY KID title is 26 cols * 4 rows of 8x8 tiles.
	for( j = 0; j < 4; j++ )
	{
		for( i = 0; i < 26; i++ )
		{
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( *pnt + j * 26 + i );
		}
	}
}

static void draw_tree( unsigned char x, unsigned char y )
{
	const unsigned int *pnt = ( const unsigned int * ) tree_avoid__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 ); 	devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 ); 	devkit_SMS_setTile( *pnt + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 ); 	devkit_SMS_setTile( *pnt + 2 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 ); 	devkit_SMS_setTile( *pnt + 3 );
}