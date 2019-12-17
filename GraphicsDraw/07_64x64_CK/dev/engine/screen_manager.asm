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
;screen_manager.c:11: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:13: engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
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
;screen_manager.c:16: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:18: draw_sprites();
	call	_draw_sprites
;screen_manager.c:19: draw_adriana();
	jp  _draw_adriana
;screen_manager.c:22: static void draw_sprites()
;	---------------------------------
; Function draw_sprites
; ---------------------------------
_draw_sprites:
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	dec	sp
;screen_manager.c:32: c = 2; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	ld	hl, #0x0102
	push	hl
	ld	hl, #0x2050
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:33: c = 3; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	ld	hl, #0x0103
	ex	(sp),hl
	ld	hl, #0x2058
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:34: c = 4; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	ld	hl, #0x0104
	ex	(sp),hl
	ld	hl, #0x2060
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:35: c = 5; 	devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	ld	hl, #0x0105
	ex	(sp),hl
	ld	hl, #0x2068
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
;screen_manager.c:37: for( r = 1; r < max - 0; r++ )
	ld	c, #0x01
00107$:
	ld	a, c
	ld	e, #0x00
	sub	a, #0x08
	ld	a, e
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	NC,00109$
;screen_manager.c:39: for( c = 1; c < max - 1; c++ )
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	a, c
	add	a, a
	add	a, a
	add	a, a
	add	a, #0x20
	ld	-3 (ix), a
	ld	b, #0x01
00104$:
	ld	e, b
	ld	d, #0x00
	ld	a, e
	sub	a, #0x07
	ld	a, d
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	NC,00108$
;screen_manager.c:41: devkit_SMS_addSprite( x + c * max, y + r * max, tile + ( r * max + c ) );
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	add	hl, de
	ld	e, l
	ld	d, h
	ld	iy, #0x0100
	add	iy, de
	ld	l, b
	ld	e, l
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	a, l
	add	a, #0x40
	ld	d, a
	push	bc
	push	iy
	ld	a, -3 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	bc
;screen_manager.c:39: for( c = 1; c < max - 1; c++ )
	inc	b
	jr	00104$
00108$:
;screen_manager.c:37: for( r = 1; r < max - 0; r++ )
	inc	c
	jr	00107$
00109$:
	ld	sp, ix
	pop	ix
	ret
;screen_manager.c:45: static void draw_adriana()
;	---------------------------------
; Function draw_adriana
; ---------------------------------
_draw_adriana:
;screen_manager.c:51: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl, #0x0140
	push	hl
	ld	hl, #0x20b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:52: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0141
	ex	(sp),hl
	ld	hl, #0x20b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:53: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	hl, #0x0142
	ex	(sp),hl
	ld	hl, #0x28b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:54: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
	ld	hl, #0x0143
	ex	(sp),hl
	ld	hl, #0x28b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
