#include "boss_manager.h"
#include "..\object\boss_object.h"
#include "..\devkit\_sms_manager.h"

void engine_boss_manager_load()
{
	unsigned char index = 2;
	unsigned int tile = 256;

	const unsigned char *image = ( const unsigned char * ) boss_32_image[ index ];
	const unsigned char *color = ( const unsigned char * ) boss_32_color[ index ];
	const unsigned char bank = ( const unsigned char ) boss_32_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( image, tile );
	devkit_SMS_loadSpritePalette( ( void * ) color );

	//devkit_SMS_loadPSGaidencompressedTiles( sprites__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) sprites__palette__bin );
}