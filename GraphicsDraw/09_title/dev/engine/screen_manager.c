#include "screen_manager.h"
#include "font_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"SPRITE TILES LOADED..."

static void draw_titile();

void engine_screen_manager_init()
{
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

	for( j = 0; j < 4; j++ )
	{
		for( i = 0; i < 26; i++ )
		{
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( *pnt + j * 26 + i );
		}
	}

	//devkit_SMS_setNextTileatXY( x + 1, y + 0 ); 	devkit_SMS_setTile( *pnt + 1 );
	//devkit_SMS_setNextTileatXY( x + 2, y + 0 ); 	devkit_SMS_setTile( *pnt + 2 );

	//devkit_SMS_setNextTileatXY( x + 0, y + 1 ); 	devkit_SMS_setTile( *pnt + 2 );
	//devkit_SMS_setNextTileatXY( x + 1, y + 1 ); 	devkit_SMS_setTile( *pnt + 3 );
}