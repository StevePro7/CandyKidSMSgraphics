;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module screen_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_setTile
	.globl _devkit_SMS_setNextTileatXY
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
;screen_manager.c:16: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:22: draw_tiles( 2, 0, 0 );
	ld	hl, #0x0000
	push	hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:23: draw_tiles( 4, 0, 0 );
	inc	sp
	ld	hl,#0x0000
	ex	(sp),hl
	ld	a, #0x04
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:24: draw_tiles( 2, 2, 0 );
	inc	sp
	ld	hl,#0x0002
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:25: draw_tiles( 2, 4, 0 );
	inc	sp
	ld	hl,#0x0004
	ex	(sp),hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:27: draw_tiles( 30, 0, 0 );
	inc	sp
	ld	hl,#0x0000
	ex	(sp),hl
	ld	a, #0x1e
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:28: draw_tiles( 30, 2, 0 );
	inc	sp
	ld	hl,#0x0002
	ex	(sp),hl
	ld	a, #0x1e
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:29: draw_tiles( 30, 4, 0 );
	inc	sp
	ld	hl,#0x0004
	ex	(sp),hl
	ld	a, #0x1e
	push	af
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
;screen_manager.c:47: draw_title();
	call	_draw_title
;screen_manager.c:49: engine_font_manager_draw_text( NORMAL_TILES_TEXT, 4, 20 );
	ld	hl, #0x1404
	push	hl
	ld	hl, #___str_0
	push	hl
	call	_engine_font_manager_draw_text
	pop	af
	pop	af
	ret
___str_0:
	.ascii "NORMAL TILES LOADED..."
	.db 0x00
;screen_manager.c:52: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:76: }
	ret
;screen_manager.c:78: static void draw_title()
;	---------------------------------
; Function draw_title
; ---------------------------------
_draw_title:
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;screen_manager.c:81: const unsigned int *pnt = ( const unsigned int * ) apex_tiles__tilemap__bin;
	ld	de, #_apex_tiles__tilemap__bin+0
;screen_manager.c:93: for( j = 0; j < 4; j++ )
	ld	c, #0x00
;screen_manager.c:95: for( i = 0; i < w; i++ )
00111$:
	ld	b, c
	inc	b
	inc	b
	ld	a, c
	add	a, a
	add	a, c
	add	a, a
	add	a, a
	add	a, c
	add	a, a
	ld	-1 (ix), a
	ld	-2 (ix), #0x00
00104$:
	ld	a, -2 (ix)
	sub	a, #0x1a
	jr	NC,00107$
;screen_manager.c:97: devkit_SMS_setNextTileatXY( x + i, y + j );
	ld	a, -2 (ix)
	add	a, #0x04
	push	bc
	push	de
	push	bc
	inc	sp
	push	af
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
;screen_manager.c:98: devkit_SMS_setTile( *pnt + TITLE_START + j * w + i );
	ld	l, e
	ld	h, d
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	add	a, #0x34
	add	a, -1 (ix)
	add	a, -2 (ix)
	push	bc
	push	de
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
	pop	bc
;screen_manager.c:95: for( i = 0; i < w; i++ )
	inc	-2 (ix)
	jr	00104$
00107$:
;screen_manager.c:93: for( j = 0; j < 4; j++ )
	inc	c
	ld	a, c
	sub	a, #0x04
	jr	C,00111$
	ld	sp, ix
	pop	ix
	ret
;screen_manager.c:103: static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx)
;	---------------------------------
; Function draw_tiles
; ---------------------------------
_draw_tiles:
	push	ix
	ld	ix,#0
	add	ix,sp
;screen_manager.c:106: const unsigned int *pnt = ( const unsigned int * ) apex_tiles__tilemap__bin;
	ld	bc, #_apex_tiles__tilemap__bin
;screen_manager.c:108: devkit_SMS_setNextTileatXY( x + 0, y + 0 ); devkit_SMS_setTile( *pnt + idx + 0 );
	push	bc
	ld	h, 5 (ix)
	ld	l, 4 (ix)
	push	hl
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	bc
	ld	l, c
	ld	h, b
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	a, e
	add	a, 6 (ix)
	ld	d, a
	push	bc
	push	de
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	bc
;screen_manager.c:109: devkit_SMS_setNextTileatXY( x + 1, y + 0 ); devkit_SMS_setTile( *pnt + idx + 1 );
	ld	e, 4 (ix)
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
	ld	d, (hl)
	add	a, 6 (ix)
	ld	d, a
	inc	d
	push	bc
	push	de
	push	de
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
	pop	bc
;screen_manager.c:110: devkit_SMS_setNextTileatXY( x + 0, y + 1 ); devkit_SMS_setTile( *pnt + idx + 26 );
	ld	d, 5 (ix)
	inc	d
	push	bc
	push	de
	push	de
	inc	sp
	ld	a, 4 (ix)
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
	ld	h, (hl)
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
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, c
	add	a, 6 (ix)
	add	a, #0x1b
	ld	b, a
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
