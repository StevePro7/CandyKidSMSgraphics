#include "content_manager.h"
#include "global_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\banks\bank2.h"
#include "..\gfx.h"

//#define TREE_TILES		64
#define FONT_TILES		0
//#define SPRITE_TILES	256 + 64

void engine_content_manager_load_tiles()
{
	// Tree tiles.
	//devkit_SMS_loadPSGaidencompressedTiles( tree_avoid__tiles__psgcompr, TREE_TILES );
	//devkit_SMS_loadBGPalette( ( void * ) tree_avoid__palette__bin );

	// Font tiles.
	devkit_SMS_loadPSGaidencompressedTiles( font_tiles__tiles__psgcompr, FONT_TILES );
	devkit_SMS_loadBGPalette( ( void * ) font_tiles__palette__bin );
}

void engine_content_manager_load_sprites()
{
	// Sprite tiles.

	//Boss32
	//00.png boss64_pro01
	//devkit_SMS_mapROMBank( boss32_pro01__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss32_pro01__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss32_pro01__palette__bin );

	//01.png boss64_adi01
	devkit_SMS_mapROMBank( boss32_adi01__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( boss32_adi01__tiles__psgcompr, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) boss32_adi01__palette__bin );

	//02.png boss64_suz01
	//devkit_SMS_mapROMBank( boss32_suz01__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss32_suz01__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss32_suz01__palette__bin );


	//Boss64
	//00.png boss64_pro01
	//devkit_SMS_mapROMBank( boss64_pro01__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss64_pro01__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss64_pro01__palette__bin );

	//01.png boss64_pro02
	//devkit_SMS_mapROMBank( boss64_pro02__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss64_pro02__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss64_pro02__palette__bin );

	//02.png boss64_adi01
	//devkit_SMS_mapROMBank( boss64_adi01__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss64_adi01__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss64_adi01__palette__bin );

	//03.png boss64_adi02
	//devkit_SMS_mapROMBank( boss64_adi02__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss64_adi02__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss64_adi02__palette__bin );

	//04.png boss64_suz01
	//devkit_SMS_mapROMBank( boss64_suz01__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss64_suz01__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss64_suz01__palette__bin );

	//05.png boss64_suz02
	//devkit_SMS_mapROMBank( boss64_suz02__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss64_suz02__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss64_suz02__palette__bin );
}
