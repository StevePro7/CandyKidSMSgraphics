#include "screen_manager.h"
#include "font_manager.h"
#include "..\devkit\_sms_manager.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"SPRITE TILES LOADED..."

static void draw_sprites();
static void draw_adriana();

void engine_screen_manager_init()
{
	engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
}

void engine_screen_manager_update()
{
	draw_sprites();
	draw_adriana();
}

static void draw_sprites()
{
	const unsigned char max = 8;
	unsigned char x = 64;
	unsigned char y = 32;
	unsigned int tile = 256;

	unsigned char r = 0;
	unsigned char c = 0;

	c = 2; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	c = 3; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	c = 4; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	c = 5; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );

	for( r = 1; r < max - 0; r++ )
	{
		for( c = 1; c < max - 1; c++ )
		{
			devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
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
