;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module screen_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_addSprite
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
;screen_manager.c:8: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:10: engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
	ld	hl, #0x0002
	push	hl
	ld	hl, #___str_0
	push	hl
	call	_engine_font_manager_draw_text
	pop	af
	pop	af
	ret
___str_0:
	.ascii "SPRITE TILES LOADED..."
	.db 0x00
;screen_manager.c:13: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;screen_manager.c:22: for( r = 0; r < 8; r++ )
	ld	c, #0x00
;screen_manager.c:24: for( c = 0; c < 8; c++ )
00109$:
	ld	a, c
	rlca
	rlca
	rlca
	and	a, #0xf8
	add	a, #0x20
	ld	-1 (ix), a
	ld	b, #0x00
00103$:
;screen_manager.c:26: devkit_SMS_addSprite( x + c * 8, y + r * 8, tile + ( r * 8 + c ) );
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	e, b
	ld	d, #0x00
	add	hl, de
	ld	de, #0x0100
	add	hl, de
	ld	a, b
	rlca
	rlca
	rlca
	and	a, #0xf8
	add	a, #0x20
	ld	e, a
	push	bc
	push	hl
	ld	d, -1 (ix)
	push	de
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	bc
;screen_manager.c:24: for( c = 0; c < 8; c++ )
	inc	b
	ld	a, b
	sub	a, #0x08
	jr	C,00103$
;screen_manager.c:22: for( r = 0; r < 8; r++ )
	inc	c
	ld	a, c
	sub	a, #0x08
	jr	C,00109$
	inc	sp
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
