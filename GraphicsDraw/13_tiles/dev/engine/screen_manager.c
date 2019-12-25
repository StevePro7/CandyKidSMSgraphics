#include "screen_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "..\devkit\_sms_manager.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"SPRITE TILES LOADED..."

static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx );
static void draw_candykd();
static void draw_skullnc();

void engine_screen_manager_init()
{
	engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
}

void engine_screen_manager_update()
{
	unsigned char input;

	unsigned char idx = 6;
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
	}
}

static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx)
{
	unsigned int tile = 256 + idx * 4;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
}
static void draw_candykd()
{
	unsigned char x = 176;
	unsigned char y = 32;
	unsigned int tile = 256 + 48;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
}
static void draw_skullnc()
{
	unsigned char x = 176;
	unsigned char y = 32;
	unsigned int tile = 256 + 64;

	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
}
