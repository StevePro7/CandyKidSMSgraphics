;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW64)
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
	ld	hl,#0x0002
	push	hl
	ld	hl,#___str_0
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
;screen_manager.c:19: draw_sprites( 48, 32, idx + 0 );
	ld	hl,#0x0620
	push	hl
	ld	a,#0x30
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:20: draw_sprites( 80, 32, idx + 1 );
	inc	sp
	ld	hl,#0x0720
	ex	(sp),hl
	ld	a,#0x50
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:22: draw_sprites( 48, 64, idx + 2 );
	inc	sp
	ld	hl,#0x0840
	ex	(sp),hl
	ld	a,#0x30
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:23: draw_sprites( 80, 64, idx + 3 );
	inc	sp
	ld	hl,#0x0940
	ex	(sp),hl
	ld	a,#0x50
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:25: draw_sprites( 48, 96, idx + 4 );
	inc	sp
	ld	hl,#0x0a60
	ex	(sp),hl
	ld	a,#0x30
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:26: draw_sprites( 80, 96, idx + 5 );
	inc	sp
	ld	hl,#0x0b60
	ex	(sp),hl
	ld	a,#0x50
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:28: draw_sprites( 48, 128, idx + 6 );
	inc	sp
	ld	hl,#0x0c80
	ex	(sp),hl
	ld	a,#0x30
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:29: draw_sprites( 80, 128, idx + 7 );
	inc	sp
	ld	hl,#0x0d80
	ex	(sp),hl
	ld	a,#0x50
	push	af
	inc	sp
	call	_draw_sprites
	pop	af
	inc	sp
	ret
;screen_manager.c:34: static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx)
;	---------------------------------
; Function draw_sprites
; ---------------------------------
_draw_sprites:
	push	ix
	ld	ix,#0
	add	ix,sp
;screen_manager.c:36: unsigned int tile = 256 + idx * 4;
	ld	l,6 (ix)
	ld	h,#0x00
	add	hl, hl
	add	hl, hl
	ld	bc,#0x0100
	add	hl,bc
	ld	c,l
	ld	b,h
;screen_manager.c:38: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	push	bc
	push	bc
	ld	h,5 (ix)
	ld	l,4 (ix)
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	bc
;screen_manager.c:39: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	l, c
	ld	h, b
	inc	hl
	ld	a,4 (ix)
	add	a, #0x08
	ld	e,a
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
;screen_manager.c:40: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	ld	a,5 (ix)
	add	a, #0x08
	ld	d,a
	push	bc
	push	de
	push	hl
	push	de
	inc	sp
	ld	a,4 (ix)
	push	af
	inc	sp
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	de
	pop	bc
;screen_manager.c:41: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
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
;screen_manager.c:64: static void draw_adriana()
;	---------------------------------
; Function draw_adriana
; ---------------------------------
_draw_adriana:
;screen_manager.c:70: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl,#0x0140
	push	hl
	ld	hl,#0x20b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:71: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0141
	ex	(sp),hl
	ld	hl,#0x20b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:72: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	hl, #0x0142
	ex	(sp),hl
	ld	hl,#0x28b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:73: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
	ld	hl, #0x0143
	ex	(sp),hl
	ld	hl,#0x28b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
