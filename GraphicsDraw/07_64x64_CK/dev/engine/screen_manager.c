#include "screen_manager.h"
#include "font_manager.h"
#include "..\devkit\_sms_manager.h"

#define NORMAL_TILES_TEXT	"NORMAL TILES LOADED..."
#define SPRITE_TILES_TEXT	"SPRITE TILES LOADED..."

void engine_screen_manager_init()
{
	engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
}

void engine_screen_manager_update()
{
	const unsigned char max = 8;
	unsigned char x = 32;
	unsigned char y = 32;
	unsigned int tile = 256;

	unsigned char r = 0;
	unsigned char c = 0;
	
	for( r = 0; r < max; r++ )
	{
		for( c = 0; c < max; c++ )
		{
			devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
		}
	}
}