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
	push	af
;screen_manager.c:24: devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	ld	hl, #0x0100
	push	hl
	ld	hl, #0x2020
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
;screen_manager.c:26: for( r = 1; r < max; r++ )
	ld	c, #0x01
00107$:
	ld	a, c
	sub	a, #0x08
	jr	NC,00102$
;screen_manager.c:28: for( c = 0; c < max; c++ )
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ex	(sp), hl
	ld	l, c
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	a, l
	add	a, #0x20
	ld	b, a
	ld	e, #0x00
00104$:
	ld	a, e
	sub	a, #0x08
	jr	NC,00108$
;screen_manager.c:30: devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	ld	d, e
	ld	h, #0x00
	ld	a, -2 (ix)
	add	a, d
	ld	l, a
	ld	a, -1 (ix)
	adc	a, h
	ld	h, a
	ld	iy, #0x0100
	push	bc
	ld	c, l
	ld	b, h
	add	iy, bc
	pop	bc
	push	de
	ld	l, e
	add	hl, hl
	add	hl, hl
	add	hl, hl
	pop	de
	ld	a, l
	add	a, #0x20
	ld	d, a
	push	bc
	push	de
	push	iy
	ld	c, d
	push	bc
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	de
	pop	bc
;screen_manager.c:28: for( c = 0; c < max; c++ )
	inc	e
	jr	00104$
00108$:
;screen_manager.c:26: for( r = 1; r < max; r++ )
	inc	c
	jr	00107$
00102$:
;screen_manager.c:36: devkit_SMS_addSprite( x + 0, y + 0, tile + 64 );
	ld	hl, #0x0140
	push	hl
	ld	hl, #0x2080
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:37: devkit_SMS_addSprite( x + 8, y + 0, tile + 65 );
	ld	hl, #0x0141
	ex	(sp),hl
	ld	hl, #0x2088
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:38: devkit_SMS_addSprite( x + 0, y + 8, tile + 66 );
	ld	hl, #0x0142
	ex	(sp),hl
	ld	hl, #0x2880
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:39: devkit_SMS_addSprite( x + 8, y + 8, tile + 67 );
	ld	hl, #0x0143
	ex	(sp),hl
	ld	hl, #0x2888
	push	hl
	call	_devkit_SMS_addSprite
	ld	sp,ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
