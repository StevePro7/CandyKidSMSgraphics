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
;screen_manager.c:12: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:14: engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
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
;screen_manager.c:17: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:33: draw_skullnc();
	jp  _draw_skullnc
;screen_manager.c:36: static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx)
;	---------------------------------
; Function draw_sprites
; ---------------------------------
_draw_sprites:
	push	ix
	ld	ix,#0
	add	ix,sp
;screen_manager.c:38: unsigned int tile = 256 + idx * 4;
	ld	l, 6 (ix)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	bc,#0x0100
	add	hl,bc
	ld	c, l
	ld	b, h
;screen_manager.c:40: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	push	bc
	push	bc
	ld	h, 5 (ix)
	ld	l, 4 (ix)
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	bc
;screen_manager.c:41: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	l, c
	ld	h, b
	inc	hl
	ld	a, 4 (ix)
	add	a, #0x08
	ld	e, a
	push	bc
	push	de
	push	hl
	ld	d, 5 (ix)
	push	de
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	de
	pop	bc
;screen_manager.c:42: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	ld	a, 5 (ix)
	add	a, #0x08
	ld	d, a
	push	bc
	push	de
	push	hl
	push	de
	inc	sp
	ld	a, 4 (ix)
	push	af
	inc	sp
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	de
	pop	bc
;screen_manager.c:43: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
	inc	bc
	inc	bc
	inc	bc
	push	bc
	push	de
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	ix
	ret
;screen_manager.c:66: static void draw_adriana()
;	---------------------------------
; Function draw_adriana
; ---------------------------------
_draw_adriana:
;screen_manager.c:72: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl, #0x0140
	push	hl
	ld	hl, #0x20b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:73: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0141
	ex	(sp),hl
	ld	hl, #0x20b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:74: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	hl, #0x0142
	ex	(sp),hl
	ld	hl, #0x28b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:75: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
	ld	hl, #0x0143
	ex	(sp),hl
	ld	hl, #0x28b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
;screen_manager.c:77: static void draw_skullnc()
;	---------------------------------
; Function draw_skullnc
; ---------------------------------
_draw_skullnc:
;screen_manager.c:83: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl, #0x0150
	push	hl
	ld	hl, #0x20b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:84: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0151
	ex	(sp),hl
	ld	hl, #0x20b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:85: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	hl, #0x0152
	ex	(sp),hl
	ld	hl, #0x28b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:86: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
	ld	hl, #0x0153
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
