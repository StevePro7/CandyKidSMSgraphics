;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module content_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_loadSpritePalette
	.globl _devkit_SMS_loadBGPalette
	.globl _devkit_SMS_loadPSGaidencompressedTiles
	.globl _engine_content_manager_load_tiles
	.globl _engine_content_manager_load_sprites
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;content_manager.c:10: void engine_content_manager_load_tiles()
;	---------------------------------
; Function engine_content_manager_load_tiles
; ---------------------------------
_engine_content_manager_load_tiles::
;content_manager.c:13: devkit_SMS_loadPSGaidencompressedTiles( tree_death__tiles__psgcompr, TREE_TILES );
	ld	hl, #0x0040
	push	hl
	ld	hl, #_tree_death__tiles__psgcompr
	push	hl
	call	_devkit_SMS_loadPSGaidencompressedTiles
	pop	af
	pop	af
;content_manager.c:14: devkit_SMS_loadBGPalette( ( void * ) tree_death__palette__bin );
	ld	bc, #_tree_death__palette__bin+0
	push	bc
	call	_devkit_SMS_loadBGPalette
	pop	af
	ret
;content_manager.c:26: void engine_content_manager_load_sprites()
;	---------------------------------
; Function engine_content_manager_load_sprites
; ---------------------------------
_engine_content_manager_load_sprites::
;content_manager.c:29: devkit_SMS_loadPSGaidencompressedTiles( sprites__tiles__psgcompr, SPRITE_TILES );
	ld	hl, #0x0100
	push	hl
	ld	hl, #_sprites__tiles__psgcompr
	push	hl
	call	_devkit_SMS_loadPSGaidencompressedTiles
	pop	af
	pop	af
;content_manager.c:30: devkit_SMS_loadSpritePalette( ( void * ) sprites__palette__bin );
	ld	bc, #_sprites__palette__bin+0
	push	bc
	call	_devkit_SMS_loadSpritePalette
;content_manager.c:32: devkit_SMS_loadPSGaidencompressedTiles( adriana__tiles__psgcompr, SPRITE_TILES + 64 );
	ld	hl, #0x0140
	ex	(sp),hl
	ld	hl, #_adriana__tiles__psgcompr
	push	hl
	call	_devkit_SMS_loadPSGaidencompressedTiles
	pop	af
	pop	af
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
