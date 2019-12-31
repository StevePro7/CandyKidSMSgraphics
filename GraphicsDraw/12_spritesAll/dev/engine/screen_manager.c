#include "screen_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "..\devkit\_sms_manager.h"

#define SPRITE_TILES_TEXT	"NEW SPRITE TILES LOADED..."

static void draw_boss( unsigned char x, unsigned char y );
static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx );
//static void draw_candykd();
//static void draw_skullnc();

void engine_screen_manager_init()
{
	engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
}

void engine_screen_manager_update()
{
	//unsigned char idx = 0;
	//unsigned char input;

	draw_boss( 64, 32 );
	/*idx += 36;

	input = engine_input_manager_move_left();
	if( input )
	{
		idx += 2;
	}
	input = engine_input_manager_move_right();
	if( input )
	{
		idx += 4;
	}

	input = engine_input_manager_move_up();
	if( input )
	{
		idx += 12;
	}
	input = engine_input_manager_move_down();
	if( input )
	{
		idx += 14;
	}
	input = engine_input_manager_move_fire1();
	if( input )
	{
		idx += 16;
	}*/

	//draw_sprites( 52, 120, 4 );
	draw_sprites( 56, 88, 48 );
	
}

static void draw_boss( unsigned char x, unsigned char y )
{
	unsigned int tile;
	unsigned char r, c;
	for( r = 0; r < 8; r++ )
	{
		for( c = 0; c < 6; c++ )
		{
			tile = BOSS01_TILES + r * 6 + c;
			devkit_SMS_addSprite( x + c * 8, y + r * 8, tile );
		}
	}
}

static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx)
{
	unsigned int tile = ENTITY_TILES + idx;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 6 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 7 );
}
//static void draw_candykd()
//{
//	unsigned char x = 56;
//	unsigned char y = 40;
//	unsigned int tile = SPRITE_TILES + 48;
//
//	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
//	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
//	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
//	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
//
//	devkit_SMS_addSprite( x + 0, y + 32, tile + 0 );
//	devkit_SMS_addSprite( x + 8, y + 32, tile + 1 );
//	devkit_SMS_addSprite( x + 0, y + 40, tile + 2 );
//	devkit_SMS_addSprite( x + 8, y + 40, tile + 3 );
//}
//static void draw_skullnc()
//{
//	unsigned char x = 56;
//	unsigned char y = 40;
//	unsigned int tile = SPRITE_TILES + 64;
//
//	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
//	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
//	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
//	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
//
//	tile = SPRITE_TILES + 68;
//	devkit_SMS_addSprite( x + 0, y + 32, tile + 0 );
//	devkit_SMS_addSprite( x + 8, y + 32, tile + 1 );
//	devkit_SMS_addSprite( x + 0, y + 40, tile + 2 );
//	devkit_SMS_addSprite( x + 8, y + 40, tile + 3 );
//}
