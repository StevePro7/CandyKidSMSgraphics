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
	.globl _devkit_SMS_setTile
	.globl _devkit_SMS_setNextTileatXY
	.globl _engine_input_manager_move_fire1
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
;screen_manager.c:16: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:22: for( x = 2; x < 32; x += 2 )
	ld	b,#0x02
00103$:
;screen_manager.c:24: draw_tiles( x, 0, 0 );
	push	bc
	ld	hl,#0x0000
	push	hl
	push	bc
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
	pop	bc
;screen_manager.c:25: draw_tiles( x, 22, 0 );
	push	bc
	ld	hl,#0x0016
	push	hl
	push	bc
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
	pop	bc
;screen_manager.c:22: for( x = 2; x < 32; x += 2 )
	inc	b
	inc	b
	ld	a,b
	sub	a, #0x20
	jr	C,00103$
;screen_manager.c:27: for( y = 2; y < 22; y += 2 )
	ld	b,#0x02
00105$:
;screen_manager.c:29: draw_tiles( 2, y, 0 );
	push	bc
	xor	a, a
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a,#0x02
	push	af
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
	pop	bc
;screen_manager.c:30: draw_tiles( 30, y, 0 );
	push	bc
	xor	a, a
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a,#0x1e
	push	af
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
	pop	bc
;screen_manager.c:27: for( y = 2; y < 22; y += 2 )
	inc	b
	inc	b
	ld	a,b
	sub	a, #0x16
	jr	C,00105$
;screen_manager.c:35: draw_tiles( 26, 6, 6 );
	ld	hl,#0x0606
	push	hl
	ld	a,#0x1a
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:37: draw_tiles( 26, 10, 10 );
	inc	sp
	ld	hl,#0x0a0a
	ex	(sp),hl
	ld	a,#0x1a
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:38: draw_tiles( 28, 6, 4 );
	inc	sp
	ld	hl,#0x0406
	ex	(sp),hl
	ld	a,#0x1c
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:40: draw_tiles( 28, 10, 12 );
	inc	sp
	ld	hl,#0x0c0a
	ex	(sp),hl
	ld	a,#0x1c
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:41: draw_tiles( 26, 8, 14 );
	inc	sp
	ld	hl,#0x0e08
	ex	(sp),hl
	ld	a,#0x1a
	push	af
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
;screen_manager.c:56: draw_title();
	jp  _draw_title
;screen_manager.c:61: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:77: unsigned char input = engine_input_manager_move_fire1();
	call	_engine_input_manager_move_fire1
;screen_manager.c:78: if( input )
	ld	a,l
	or	a, a
;screen_manager.c:80: draw_skullnc();
	jp	NZ,_draw_skullnc
;screen_manager.c:84: draw_candykd();
	jp  _draw_candykd
;screen_manager.c:88: static void draw_title()
;	---------------------------------
; Function draw_title
; ---------------------------------
_draw_title:
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	dec	sp
;screen_manager.c:91: const unsigned int *pnt = ( const unsigned int * ) apex_tiles__tilemap__bin;
	ld	bc,#_apex_tiles__tilemap__bin+0
;screen_manager.c:103: for( j = 0; j < 4; j++ )
	ld	-3 (ix),#0x00
	ld	e,#0x00
;screen_manager.c:105: for( i = 0; i < w; i++ )
00111$:
	ld	a,-3 (ix)
	add	a, #0x02
	ld	-1 (ix),a
	ld	d,#0x00
00104$:
;screen_manager.c:107: devkit_SMS_setNextTileatXY( x + i, y + j );
	ld	a,d
	cp	a,#0x1a
	jr	NC,00107$
	add	a, #0x04
	ld	-2 (ix),a
	push	bc
	push	de
	ld	h,-1 (ix)
	ld	l,-2 (ix)
	push	hl
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
;screen_manager.c:108: devkit_SMS_setTile( *pnt + TITLE_START + j * w + i );
	ld	l, c
	ld	h, b
	ld	a, (hl)
	inc	hl
	ld	h,(hl)
	add	a, #0x34
	ld	l,a
	add	hl, de
	ld	a,l
	add	a, d
	push	bc
	push	de
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
	pop	bc
;screen_manager.c:105: for( i = 0; i < w; i++ )
	inc	d
	jr	00104$
00107$:
;screen_manager.c:103: for( j = 0; j < 4; j++ )
	ld	a,e
	add	a, #0x1a
	ld	e,a
	inc	-3 (ix)
	ld	a,-3 (ix)
	sub	a, #0x04
	jr	C,00111$
	ld	sp, ix
	pop	ix
	ret
;screen_manager.c:113: static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx)
;	---------------------------------
; Function draw_tiles
; ---------------------------------
_draw_tiles:
	push	ix
	ld	ix,#0
	add	ix,sp
;screen_manager.c:116: const unsigned int *pnt = ( const unsigned int * ) apex_tiles__tilemap__bin;
	ld	bc,#_apex_tiles__tilemap__bin
;screen_manager.c:118: devkit_SMS_setNextTileatXY( x + 0, y + 0 ); devkit_SMS_setTile( *pnt + idx + 0 );
	push	bc
	ld	h,5 (ix)
	ld	l,4 (ix)
	push	hl
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	bc
	ld	l, c
	ld	h, b
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	a,e
	add	a, 6 (ix)
	ld	d,a
	push	bc
	push	de
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	bc
;screen_manager.c:119: devkit_SMS_setNextTileatXY( x + 1, y + 0 ); devkit_SMS_setTile( *pnt + idx + 1 );
	ld	e,4 (ix)
	inc	e
	push	bc
	push	de
	ld	d, 5 (ix)
	push	de
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
	ld	l, c
	ld	h, b
	ld	a, (hl)
	inc	hl
	ld	d,(hl)
	add	a, 6 (ix)
	ld	d,a
	inc	d
	push	bc
	push	de
	push	de
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
	pop	bc
;screen_manager.c:120: devkit_SMS_setNextTileatXY( x + 0, y + 1 ); devkit_SMS_setTile( *pnt + idx + 26 );
	ld	d,5 (ix)
	inc	d
	push	bc
	push	de
	push	de
	inc	sp
	ld	a,4 (ix)
	push	af
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
	ld	l, c
	ld	h, b
	ld	a, (hl)
	inc	hl
	ld	h,(hl)
	add	a, 6 (ix)
	add	a, #0x1a
	push	bc
	push	de
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	hl
	ld	c,(hl)
	inc	hl
	ld	b,(hl)
	ld	a,c
	add	a, 6 (ix)
	add	a, #0x1b
	ld	b,a
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	ix
	ret
;screen_manager.c:123: static void draw_candykd()
;	---------------------------------
; Function draw_candykd
; ---------------------------------
_draw_candykd:
;screen_manager.c:129: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl,#0x0160
	push	hl
	ld	hl,#0x40e0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:130: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0161
	ex	(sp),hl
	ld	hl,#0x40e8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:131: devkit_SMS_addSprite( x + 0, y + 8, tile + 6 );
	ld	hl, #0x0166
	ex	(sp),hl
	ld	hl,#0x48e0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:132: devkit_SMS_addSprite( x + 8, y + 8, tile + 7 );
	ld	hl, #0x0167
	ex	(sp),hl
	ld	hl,#0x48e8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
;screen_manager.c:134: static void draw_skullnc()
;	---------------------------------
; Function draw_skullnc
; ---------------------------------
_draw_skullnc:
;screen_manager.c:140: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl,#0x016e
	push	hl
	ld	hl,#0x40e0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:141: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x016f
	ex	(sp),hl
	ld	hl,#0x40e8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:142: devkit_SMS_addSprite( x + 0, y + 8, tile + 6 );
	ld	hl, #0x0174
	ex	(sp),hl
	ld	hl,#0x48e0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:143: devkit_SMS_addSprite( x + 8, y + 8, tile + 7 );
	ld	hl, #0x0175
	ex	(sp),hl
	ld	hl,#0x48e8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
