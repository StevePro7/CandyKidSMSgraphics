#include "vulcanlaser.h"

void vulcanlaser_foo()
{
}

//// warning 85: unreferenced function argument: 'en'
//#ifdef _CONSOLE
//#else
//#pragma disable_warning 85
//#endif
//
//void InitVulcanLaser( enemy *en )
//{
//	// Sound
//	PlaySound( enemylaser_psg, 1 );
//}
//
//unsigned char UpdateVulcanLaser( enemy *en )
//{
//	// Movement
//	en->enemyposy += ( DEFAULTENEMYSHOOTLASERSPEED + 1 + ( gamelevel << 1 ) );
//
//	// Exit?
//	if( ( en->enemyposy >= 208 ) && ( en->enemyposy < 224 ) )
//		return 0;
//
//	// Draw the sprite
//	DrawSpriteArray( VULCANLASERBASE, en->enemyposx, en->enemyposy, 8, 48 );
//
//	return 1;
//}
//
