#include "boss_manager.h"
#include "global_manager.h"
#include "..\object\boss_object.h"
#include "..\devkit\_sms_manager.h"

void engine_boss_manager_load()
{
	unsigned char index = 1;

	const unsigned char *image = ( const unsigned char * ) boss_64_image[ index ];
	const unsigned char *color = ( const unsigned char * ) boss_64_color[ index ];
	const unsigned char bank = ( const unsigned char ) boss_64_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( image, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) color );
}

void engine_boss_manager_load_32( unsigned char index )
{
	const unsigned char *image = ( const unsigned char * ) boss_32_image[ index ];
	const unsigned char *color = ( const unsigned char * ) boss_32_color[ index ];
	const unsigned char bank = ( const unsigned char ) boss_32_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( image, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) color );
}

void engine_boss_manager_load_64( unsigned char index )
{
	const unsigned char *image = ( const unsigned char * ) boss_64_image[ index ];
	const unsigned char *color = ( const unsigned char * ) boss_64_color[ index ];
	const unsigned char bank = ( const unsigned char ) boss_64_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( image, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) color );
}