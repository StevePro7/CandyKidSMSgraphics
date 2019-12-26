;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module content_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
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
;content_manager.c:9: void engine_content_manager_load_tiles()
;	---------------------------------
; Function engine_content_manager_load_tiles
; ---------------------------------
_engine_content_manager_load_tiles::
;content_manager.c:16: devkit_SMS_loadPSGaidencompressedTiles( data_tiles__tiles__psgcompr, TREE_TILES );
	ld	hl, #0x0040
	push	hl
	ld	hl, #_data_tiles__tiles__psgcompr
	push	hl
	call	_devkit_SMS_loadPSGaidencompressedTiles
	pop	af
	pop	af
;content_manager.c:17: devkit_SMS_loadBGPalette( ( void * ) data_tiles__palette__bin );
	ld	bc, #_data_tiles__palette__bin+0
	push	bc
	call	_devkit_SMS_loadBGPalette
	pop	af
	ret
;content_manager.c:25: void engine_content_manager_load_sprites()
;	---------------------------------
; Function engine_content_manager_load_sprites
; ---------------------------------
_engine_content_manager_load_sprites::
;content_manager.c:36: }
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
