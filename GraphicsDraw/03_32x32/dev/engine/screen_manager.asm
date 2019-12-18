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
;screen_manager.c:13: }
	ret
;screen_manager.c:15: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:18: draw_sprites( 48, 32, idx + 0 );
	ld	hl, #0x0020
	push	hl
	ld	a, #0x30
	push	af
	inc	sp
	call	_draw_sprites
;screen_manager.c:20: draw_sprites( 128, 32, idx + 0 );
	inc	sp
	ld	hl,#0x0020
	ex	(sp),hl
	ld	a, #0x80
	push	af
	inc	sp
	call	_draw_sprites
	pop	af
	inc	sp
;screen_manager.c:33: draw_adriana();
	jp  _draw_adriana
;screen_manager.c:36: static void draw_sprites( unsigned char x, unsigned char y, unsigned char idx )
;	---------------------------------
; Function draw_sprites
; ---------------------------------
_draw_sprites:
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	dec	sp
;screen_manager.c:38: unsigned int tile = 256 + idx * 4;
	ld	l, 6 (ix)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	bc,#0x0100
	add	hl,bc
	ex	(sp), hl
;screen_manager.c:41: for( r = 0; r < 4; r++ )
	ld	e, #0x00
;screen_manager.c:43: for( c = 1; c < 4; c++ )
00109$:
	ld	a, e
	rlca
	rlca
	rlca
	and	a, #0xf8
	ld	c, a
	ld	a, 5 (ix)
	add	a, c
	ld	-1 (ix), a
	ld	d, #0x01
00103$:
;screen_manager.c:45: unsigned t = r * 4 + c;
	ld	l, e
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	c, d
	ld	b, #0x00
	add	hl, bc
;screen_manager.c:46: devkit_SMS_addSprite( x + c * 8, y + r * 8, tile + t );
	pop	bc
	push	bc
	add	hl, bc
	ld	a, d
	rlca
	rlca
	rlca
	and	a, #0xf8
	ld	c, a
	ld	a, 4 (ix)
	add	a, c
	ld	b, a
	push	de
	push	hl
	ld	a, -1 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	pop	de
;screen_manager.c:43: for( c = 1; c < 4; c++ )
	inc	d
	ld	a, d
	sub	a, #0x04
	jr	C,00103$
;screen_manager.c:41: for( r = 0; r < 4; r++ )
	inc	e
	ld	a, e
	sub	a, #0x04
	jr	C,00109$
	ld	sp, ix
	pop	ix
	ret
;screen_manager.c:51: static void draw_adriana()
;	---------------------------------
; Function draw_adriana
; ---------------------------------
_draw_adriana:
;screen_manager.c:57: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl, #0x0140
	push	hl
	ld	hl, #0x20b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:58: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0141
	ex	(sp),hl
	ld	hl, #0x20b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:59: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	hl, #0x0142
	ex	(sp),hl
	ld	hl, #0x28b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:60: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
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
