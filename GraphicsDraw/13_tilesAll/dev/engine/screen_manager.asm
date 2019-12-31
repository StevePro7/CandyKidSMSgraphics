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
;screen_manager.c:15: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:40: draw_titile();
	jp  _draw_titile
;screen_manager.c:43: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:67: }
	ret
;screen_manager.c:69: static void draw_titile()
;	---------------------------------
; Function draw_titile
; ---------------------------------
_draw_titile:
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;screen_manager.c:71: const unsigned int *pnt = ( const unsigned int * ) game_title__tilemap__bin;
	ld	bc, #_game_title__tilemap__bin+0
	inc	sp
	inc	sp
	push	bc
;screen_manager.c:80: for( j = 0; j < 4; j++ )
	ld	c, #0x00
;screen_manager.c:82: for( i = 0; i < 26; i++ )
00109$:
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
	ld	e, a
	ld	d, #0x00
00103$:
;screen_manager.c:84: devkit_SMS_setNextTileatXY( x + i, y + j );
	ld	a, d
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
;screen_manager.c:85: devkit_SMS_setTile( *pnt + j * 26 + i );
	pop	hl
	push	hl
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ld	a, l
	add	a, d
	push	bc
	push	de
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
	pop	bc
;screen_manager.c:82: for( i = 0; i < 26; i++ )
	inc	d
	ld	a, d
	sub	a, #0x1a
	jr	C,00103$
;screen_manager.c:80: for( j = 0; j < 4; j++ )
	inc	c
	ld	a, c
	sub	a, #0x04
	jr	C,00109$
	ld	sp, ix
	pop	ix
	ret
;screen_manager.c:90: static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx)
;	---------------------------------
; Function draw_tiles
; ---------------------------------
_draw_tiles:
	push	ix
	ld	ix,#0
	add	ix,sp
;screen_manager.c:92: const unsigned char *pnt = data_tiles__tilemap__bin;
;screen_manager.c:94: devkit_SMS_setNextTileatXY( x + 0, y + 0 ); devkit_SMS_setTile( *pnt + idx + 0 );
	ld	h, 5 (ix)
	ld	l, 4 (ix)
	push	hl
	call	_devkit_SMS_setNextTileatXY
	pop	af
	ld	hl, #_data_tiles__tilemap__bin + 0
	ld	c, (hl)
	ld	a, c
	add	a, 6 (ix)
	ld	b, a
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
;screen_manager.c:95: devkit_SMS_setNextTileatXY( x + 1, y + 0 ); devkit_SMS_setTile( *pnt + idx + 1 );
	ld	c, 4 (ix)
	inc	c
	push	bc
	ld	b, 5 (ix)
	push	bc
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	bc
	ld	a,(#_data_tiles__tilemap__bin + 0)
	add	a, 6 (ix)
	ld	b, a
	inc	b
	push	bc
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	bc
;screen_manager.c:96: devkit_SMS_setNextTileatXY( x + 0, y + 1 ); devkit_SMS_setTile( *pnt + idx + 2 );
	ld	b, 5 (ix)
	inc	b
	push	bc
	push	bc
	inc	sp
	ld	a, 4 (ix)
	push	af
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	bc
	ld	a,(#_data_tiles__tilemap__bin + 0)
	add	a, 6 (ix)
	add	a, #0x02
	push	bc
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	ld	a,(#_data_tiles__tilemap__bin + 0)
	add	a, 6 (ix)
	add	a, #0x03
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
