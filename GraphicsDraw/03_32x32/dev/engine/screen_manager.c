#include "screen_manager.h"
#include "font_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"SPRITE TILES LOADED..."

static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx );
static void draw_adriana();
static void draw_tree( unsigned char x, unsigned char y );

void engine_screen_manager_init()
{
	unsigned char x;
	for( x = 2; x < 20; x += 2 )
	{
		draw_tree( x, 2 );
	}
}

void engine_screen_manager_update()
{
	unsigned char idx = 0;
	draw_sprites( 48, 32, idx + 0 );

	draw_sprites( 128, 32, idx + 0 );

	//draw_sprites( 80, 32, idx + 1 );

	/*draw_sprites( 48, 64, idx + 2 );
	draw_sprites( 80, 64, idx + 3 );

	draw_sprites( 48, 96, idx + 4 );
	draw_sprites( 80, 96, idx + 5 );

	draw_sprites( 48, 128, idx + 6 );
	draw_sprites( 80, 128, idx + 7 );*/

	draw_adriana();
}

static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx )
{
	const unsigned char offset = 4;
	unsigned int tile = 256 + idx * 4;
	unsigned char r, c;

	for( r = 0; r < 4; r++ )
	{
		for( c = 0; c < 3; c++ )
		{
			unsigned t = r * 4 + c;
			devkit_SMS_addSprite( x + c * 8 + offset, y + r * 8, tile + t );
		}
	}
	
}
static void draw_adriana()
{
	unsigned char x = 176;
	unsigned char y = 32;
	unsigned int tile = 256 + 64;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
}

static void draw_tree( unsigned char x, unsigned char y )
{
	const unsigned int *pnt = ( const unsigned int * )tree_avoid__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 ); 	devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 ); 	devkit_SMS_setTile( *pnt + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 ); 	devkit_SMS_setTile( *pnt + 2 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 ); 	devkit_SMS_setTile( *pnt + 3 );
}