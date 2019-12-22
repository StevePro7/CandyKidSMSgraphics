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
;screen_manager.c:9: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:13: for( x = 2; x < 32; x += 2 )
	ld	b, #0x02
00103$:
;screen_manager.c:15: draw_tree( x, 0 );
	push	bc
	xor	a, a
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_draw_tree
	pop	af
	pop	bc
;screen_manager.c:16: draw_tree( x, 22 );
	push	bc
	ld	a, #0x16
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_draw_tree
	pop	af
	pop	bc
;screen_manager.c:13: for( x = 2; x < 32; x += 2 )
	inc	b
	inc	b
	ld	a, b
	sub	a, #0x20
	jr	C,00103$
;screen_manager.c:19: for( y = 2; y < 22; y += 2 )
	ld	b, #0x02
00105$:
;screen_manager.c:21: draw_tree( 2, y );
	push	bc
	push	bc
	inc	sp
	ld	a, #0x02
	push	af
	inc	sp
	call	_draw_tree
	pop	af
	pop	bc
;screen_manager.c:22: draw_tree( 30, y );
	push	bc
	push	bc
	inc	sp
	ld	a, #0x1e
	push	af
	inc	sp
	call	_draw_tree
	pop	af
	pop	bc
;screen_manager.c:19: for( y = 2; y < 22; y += 2 )
	inc	b
	inc	b
	ld	a, b
	sub	a, #0x16
	jr	C,00105$
;screen_manager.c:25: draw_titile();
	jp  _draw_titile
;screen_manager.c:28: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:30: }
	ret
;screen_manager.c:32: static void draw_titile()
;	---------------------------------
; Function draw_titile
; ---------------------------------
_draw_titile:
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;screen_manager.c:34: const unsigned int *pnt = ( const unsigned int * ) game_title__tilemap__bin;
	ld	bc, #_game_title__tilemap__bin+0
	inc	sp
	inc	sp
	push	bc
;screen_manager.c:42: for( j = 0; j < 4; j++ )
	ld	c, #0x00
;screen_manager.c:44: for( i = 0; i < 26; i++ )
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
;screen_manager.c:46: devkit_SMS_setNextTileatXY( x + i, y + j );
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
;screen_manager.c:47: devkit_SMS_setTile( *pnt + j * 26 + i );
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
;screen_manager.c:44: for( i = 0; i < 26; i++ )
	inc	d
	ld	a, d
	sub	a, #0x1a
	jr	C,00103$
;screen_manager.c:42: for( j = 0; j < 4; j++ )
	inc	c
	ld	a, c
	sub	a, #0x04
	jr	C,00109$
	ld	sp, ix
	pop	ix
	ret
;screen_manager.c:52: static void draw_tree( unsigned char x, unsigned char y )
;	---------------------------------
; Function draw_tree
; ---------------------------------
_draw_tree:
	push	ix
	ld	ix,#0
	add	ix,sp
;screen_manager.c:54: const unsigned int *pnt = ( const unsigned int * ) tree_avoid__tilemap__bin;
	ld	de, #_tree_avoid__tilemap__bin
;screen_manager.c:56: devkit_SMS_setNextTileatXY( x + 0, y + 0 ); 	devkit_SMS_setTile( *pnt + 0 );
	push	de
	ld	h, 5 (ix)
	ld	l, 4 (ix)
	push	hl
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	ld	l, e
	ld	h, d
	ld	b, (hl)
	inc	hl
	ld	c, (hl)
	push	de
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
;screen_manager.c:57: devkit_SMS_setNextTileatXY( x + 1, y + 0 ); 	devkit_SMS_setTile( *pnt + 1 );
	ld	c, 4 (ix)
	inc	c
	push	bc
	push	de
	ld	b, 5 (ix)
	push	bc
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
	ld	l, e
	ld	h, d
	ld	a, (hl)
	inc	hl
	ld	b, (hl)
	ld	b, a
	inc	b
	push	bc
	push	de
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
	pop	bc
;screen_manager.c:58: devkit_SMS_setNextTileatXY( x + 0, y + 1 ); 	devkit_SMS_setTile( *pnt + 2 );
	ld	b, 5 (ix)
	inc	b
	push	bc
	push	de
	push	bc
	inc	sp
	ld	a, 4 (ix)
	push	af
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
	ld	l, e
	ld	h, d
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	inc	l
	inc	l
	push	bc
	push	de
	ld	a, l
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	de
	pop	bc
;screen_manager.c:59: devkit_SMS_setNextTileatXY( x + 1, y + 1 ); 	devkit_SMS_setTile( *pnt + 3 );
	push	de
	push	bc
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	hl
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	b, c
	inc	b
	inc	b
	inc	b
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
