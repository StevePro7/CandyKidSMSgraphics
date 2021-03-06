;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW64)
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
;content_manager.c:9: void engine_content_manager_load_tiles()
;	---------------------------------
; Function engine_content_manager_load_tiles
; ---------------------------------
_engine_content_manager_load_tiles::
;content_manager.c:12: devkit_SMS_loadPSGaidencompressedTiles( font_tiles__tiles__psgcompr, FONT_TILES );
	ld	hl,#0x0000
	push	hl
	ld	hl,#_font_tiles__tiles__psgcompr
	push	hl
	call	_devkit_SMS_loadPSGaidencompressedTiles
	pop	af
;content_manager.c:16: devkit_SMS_loadPSGaidencompressedTiles( apex_tiles__tiles__psgcompr, APEX_TILES );
	ld	hl, #0x0040
	ex	(sp),hl
	ld	hl,#_apex_tiles__tiles__psgcompr
	push	hl
	call	_devkit_SMS_loadPSGaidencompressedTiles
	pop	af
	pop	af
;content_manager.c:17: devkit_SMS_loadBGPalette( ( void * ) apex_tiles__palette__bin );
	ld	bc,#_apex_tiles__palette__bin+0
	push	bc
	call	_devkit_SMS_loadBGPalette
	pop	af
	ret
;content_manager.c:20: void engine_content_manager_load_sprites()
;	---------------------------------
; Function engine_content_manager_load_sprites
; ---------------------------------
_engine_content_manager_load_sprites::
;content_manager.c:23: devkit_SMS_loadPSGaidencompressedTiles( sprites__tiles__psgcompr, SPRITE_TILES );
	ld	hl,#0x0100
	push	hl
	ld	hl,#_sprites__tiles__psgcompr
	push	hl
	call	_devkit_SMS_loadPSGaidencompressedTiles
	pop	af
	pop	af
;content_manager.c:24: devkit_SMS_loadSpritePalette( ( void * ) sprites__palette__bin );
	ld	bc,#_sprites__palette__bin+0
	push	bc
	call	_devkit_SMS_loadSpritePalette
	pop	af
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
