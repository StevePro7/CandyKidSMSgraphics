#include "content_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define DATA_TILES		64
#define FONT_TILES		0
#define SPRITE_TILES	256

void engine_content_manager_load_tiles()
{
	// Tree tiles.
	//devkit_SMS_loadPSGaidencompressedTiles( tree_avoid__tiles__psgcompr, TREE_TILES );
	//devkit_SMS_loadBGPalette( ( void * ) tree_avoid__palette__bin );

	// Data tiles.
	devkit_SMS_loadPSGaidencompressedTiles( data_tiles__tiles__psgcompr, DATA_TILES );
	devkit_SMS_loadBGPalette( ( void * ) data_tiles__palette__bin );

	// Font tiles.
	devkit_SMS_loadPSGaidencompressedTiles( font_tiles__tiles__psgcompr, FONT_TILES );
	//devkit_SMS_loadBGPalette( ( void * ) font_tiles__palette__bin );

}

void engine_content_manager_load_sprites()
{
	// Sprite tiles.
	//devkit_SMS_loadPSGaidencompressedTiles( sprites__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) sprites__palette__bin );

	//devkit_SMS_loadPSGaidencompressedTiles( adriana__tiles__psgcompr, SPRITE_TILES + 64 );
	//devkit_SMS_loadSpritePalette( ( void * ) adriana__palette__bin );

	//devkit_SMS_loadPSGaidencompressedTiles( skullnc__tiles__psgcompr, SPRITE_TILES + 80 );
	//devkit_SMS_loadSpritePalette( ( void * ) skullnc__palette__bin );
}