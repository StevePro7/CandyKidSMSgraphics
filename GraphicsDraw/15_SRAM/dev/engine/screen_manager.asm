;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module screen_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _incPoints
	.globl _getPoints
	.globl _writeSaveGame
	.globl _readSaveGame
	.globl _isSaveGamePresent
	.globl _engine_font_manager_draw_data
	.globl _engine_font_manager_draw_text
	.globl _engine_screen_manager_init
	.globl _engine_screen_manager_update
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
;screen_manager.c:9: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:11: bool test = isSaveGamePresent();
	call	_isSaveGamePresent
;screen_manager.c:12: engine_font_manager_draw_text( "HELLO", 2, 0 );
	ld	bc, #___str_0+0
	push	hl
	ld	de, #0x0002
	push	de
	push	bc
	call	_engine_font_manager_draw_text
	pop	af
	pop	af
	pop	hl
;screen_manager.c:13: engine_font_manager_draw_data( test, 2, 2 );
	ld	c, l
	ld	b, #0x00
	push	hl
	ld	de, #0x0202
	push	de
	push	bc
	call	_engine_font_manager_draw_data
	pop	af
	pop	af
	pop	hl
;screen_manager.c:14: engine_font_manager_draw_text( "THERE", 20, 2 );
	ld	bc, #___str_1+0
	push	hl
	ld	de, #0x0214
	push	de
	push	bc
	call	_engine_font_manager_draw_text
	pop	af
	pop	af
	pop	hl
;screen_manager.c:15: if( test )
	bit	0, l
	jp	Z,_writeSaveGame
;screen_manager.c:17: engine_font_manager_draw_data( getPoints(), 12, 4 );
	call	_getPoints
	ld	bc, #0x040c
	push	bc
	push	hl
	call	_engine_font_manager_draw_data
	pop	af
	pop	af
;screen_manager.c:18: readSaveGame();
	call	_readSaveGame
;screen_manager.c:19: engine_font_manager_draw_data( getPoints(), 12, 5 );
	call	_getPoints
	ld	bc, #0x050c
	push	bc
	push	hl
	call	_engine_font_manager_draw_data
	pop	af
	pop	af
;screen_manager.c:20: incPoints();
	call	_incPoints
;screen_manager.c:21: engine_font_manager_draw_data( getPoints(), 12, 6 );
	call	_getPoints
	ld	bc, #0x060c
	push	bc
	push	hl
	call	_engine_font_manager_draw_data
	pop	af
	pop	af
;screen_manager.c:24: writeSaveGame();
	jp  _writeSaveGame
___str_0:
	.ascii "HELLO"
	.db 0x00
___str_1:
	.ascii "THERE"
	.db 0x00
;screen_manager.c:27: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:29: }
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
