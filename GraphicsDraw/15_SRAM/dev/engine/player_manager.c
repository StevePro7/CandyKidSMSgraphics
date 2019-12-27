#include "player_manager.h"
#include "..\devkit\_sms_manager.h"

// Global variable.
struct_player_object global_player_object;

#define PLAYER_SPRITE_TILE		256
#define PLAYER_VELOCITY			2

//#define PLAYER_MIN_X			32
//#define PLAYER_MAX_X			224
//#define PLAYER_MIN_Y			32
//#define PLAYER_MAX_Y			160


void engine_player_manager_init( unsigned char px, unsigned char py )
{
	struct_player_object *po = &global_player_object;
	po->px = px;
	po->py = py;
}

void engine_player_manager_update( char dx, char dy )
{
	struct_player_object *po = &global_player_object;

	po->px += dx * PLAYER_VELOCITY;
	po->py += dy * PLAYER_VELOCITY;

	/*if( po->px < PLAYER_MIN_X )
	{
		po->px = PLAYER_MIN_X;
	}
	if ( po->px > PLAYER_MAX_X )
	{
		po->px = PLAYER_MAX_X;
	}
	if( po->py < PLAYER_MIN_Y )
	{
		po->py = PLAYER_MIN_Y;
	}
	if( po->py > PLAYER_MAX_Y )
	{
		po->py = PLAYER_MAX_Y;
	}*/
}

void engine_player_manager_draw()
{
	struct_player_object *po = &global_player_object;

	devkit_SMS_addSprite( po->px + 0, po->py + 0, PLAYER_SPRITE_TILE + 0 );
	devkit_SMS_addSprite( po->px + 8, po->py + 0, PLAYER_SPRITE_TILE + 1 );
	devkit_SMS_addSprite( po->px + 0, po->py + 8, PLAYER_SPRITE_TILE + 2 );
	devkit_SMS_addSprite( po->px + 8, po->py + 8, PLAYER_SPRITE_TILE + 3 );
}

unsigned char engine_player_getX()
{
	struct_player_object *po = &global_player_object;
	return po->px;
}
unsigned char engine_player_getY()
{
	struct_player_object *po = &global_player_object;
	return po->py;
}