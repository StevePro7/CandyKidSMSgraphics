#include "screen_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"STEVEN TILES LOADED..."

static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx );
//static void draw_candykd();
//static void draw_skullnc();

void engine_screen_manager_init()
{
	unsigned char x, y;
	unsigned char idx = 24;


	// trees
	draw_tiles( 4, 4, 0 );
	draw_tiles( 8, 4, 4 );

	// bonus
	draw_tiles( 12, 4, 8 );
	draw_tiles( 16, 4, 12 );
	draw_tiles( 20, 4, 16 );
	draw_tiles( 24, 4, 20 );

	// candy
	for( y = 0; y < 4; y += 2 )
	{
		for( x = 2; x < 16; x += 2 )
		{
			draw_tiles( x + 4, y + 10, idx );
			idx += 4;
		}
	}

}

void engine_screen_manager_update()
{
	

	

	/*unsigned char idx = 6;
	draw_sprites( 48, 32, idx + 0 );
	draw_sprites( 80, 32, idx + 1 );

	draw_sprites( 48, 64, idx + 2 );
	draw_sprites( 80, 64, idx + 3 );

	draw_sprites( 48, 96, idx + 4 );
	draw_sprites( 80, 96, idx + 5 );

	draw_sprites( 48, 128, idx + 6 );
	draw_sprites( 80, 128, idx + 7 );

	input = engine_input_manager_move_fire1();
	if( input )
	{
		draw_skullnc();
	}
	else
	{
		draw_candykd();
	}*/
}

static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx)
{
	const unsigned char *pnt = data_tiles__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 ); devkit_SMS_setTile( *pnt + idx + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 ); devkit_SMS_setTile( *pnt + idx + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 ); devkit_SMS_setTile( *pnt + idx + 2 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 ); devkit_SMS_setTile( *pnt + idx + 3 );
}
//static void draw_candykd()
//{
//	unsigned char x = 176;
//	unsigned char y = 32;
//	unsigned int tile = 256 + 48;
//
//	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
//	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
//	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
//	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
//}
//static void draw_skullnc()
//{
//	unsigned char x = 176;
//	unsigned char y = 32;
//	unsigned int tile = 256 + 64;
//
//	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
//	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
//	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
//	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
//}
