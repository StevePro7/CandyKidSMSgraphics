#include "sprite_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned int tile )
{
	devkit_SMS_addSprite_bulk4( x, y, tile );
}