#include "boss_manager.h"
#include "..\object\boss_object.h"
#include "..\devkit\_sms_manager.h"

void engine_boss_manager_load()
{
	unsigned char index = 2;
	unsigned int tile = 256;

	const unsigned char *data = ( const unsigned char * ) boss_32_data[ index ];
	const unsigned char bank = ( const unsigned char ) boss_32_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}