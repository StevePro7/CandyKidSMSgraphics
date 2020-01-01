#include "screen_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"STEVEN TILES LOADED..."
#define TITLE_START		52

static void draw_title();
static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx );
static void draw_candykd();
static void draw_skullnc();

void engine_screen_manager_init()
{
	unsigned char x, y;
	//unsigned char idx = 24;

	// trees
	for( x = 2; x < 32; x += 2 )
	{
		draw_tiles( x, 0, 0 );
		draw_tiles( x, 22, 0 );
	}
	for( y = 2; y < 22; y += 2 )
	{
		draw_tiles( 2, y, 0 );
		draw_tiles( 30, y, 0 );
	}
	

	//// bonus
	draw_tiles( 26, 6, 6 );
	//draw_tiles( 26, 8, 8 );
	draw_tiles( 26, 10, 10 );
	draw_tiles( 28, 6, 4 );

	draw_tiles( 28, 10, 12 );
	draw_tiles( 26, 8, 14 );
	//draw_tiles( 16, 4, 12 );
	//draw_tiles( 20, 4, 16 );
	//draw_tiles( 24, 4, 20 );

	//// candy
	//for( y = 0; y < 4; y += 2 )
	//{
	//	for( x = 2; x < 16; x += 2 )
	//	{
	//		draw_tiles( x + 4, y + 10, idx );
	//		idx += 4;
	//	}
	//}

	draw_title();

	//engine_font_manager_draw_text( NORMAL_TILES_TEXT, 4, 20 );
}

void engine_screen_manager_update()
{
	/*
	unsigned char idx = 6;
	draw_sprites( 48, 32, idx + 0 );
	draw_sprites( 80, 32, idx + 1 );

	draw_sprites( 48, 64, idx + 2 );
	draw_sprites( 80, 64, idx + 3 );

	draw_sprites( 48, 96, idx + 4 );
	draw_sprites( 80, 96, idx + 5 );

	draw_sprites( 48, 128, idx + 6 );
	draw_sprites( 80, 128, idx + 7 );
	*/
	unsigned char input = engine_input_manager_move_fire1();
	if( input )
	{
		draw_skullnc();
	}
	else
	{
		draw_candykd();
	}
}

static void draw_title()
{
	//const unsigned int *pnt = ( const unsigned int * ) game_title__tilemap__bin;
	const unsigned int *pnt = ( const unsigned int * ) apex_tiles__tilemap__bin;

	unsigned char x = 4;
	unsigned char y = 2;

	unsigned char i;
	unsigned char j;

	unsigned char w = 26;
	unsigned char l = 4;

	// CANDY KID title is 26 cols * 4 rows of 8x8 tiles.
	for( j = 0; j < 4; j++ )
	{
		for( i = 0; i < w; i++ )
		{
			devkit_SMS_setNextTileatXY( x + i, y + j );
			devkit_SMS_setTile( *pnt + TITLE_START + j * w + i );
		}
	}
}

static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx)
{
	//const unsigned int *pnt = ( const unsigned int * ) game_title__tilemap__bin;
	const unsigned int *pnt = ( const unsigned int * ) apex_tiles__tilemap__bin;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 ); devkit_SMS_setTile( *pnt + idx + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 ); devkit_SMS_setTile( *pnt + idx + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 ); devkit_SMS_setTile( *pnt + idx + 26 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 ); devkit_SMS_setTile( *pnt + idx + 27 );
}
static void draw_candykd()
{
	unsigned char x = 224;
	unsigned char y = 64;
	unsigned int tile = 256 + 96;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 6 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 7 );
}
static void draw_skullnc()
{
	unsigned char x = 224;
	unsigned char y = 64;
	unsigned int tile = 256 + 110;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 6 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 7 );
}
