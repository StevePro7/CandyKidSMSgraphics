;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module tile_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_setTile
	.globl _devkit_SMS_setNextTileatXY
	.globl _engine_tile_manager_draw
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
;tile_manager.c:7: void engine_tile_manager_draw()
;	---------------------------------
; Function engine_tile_manager_draw
; ---------------------------------
_engine_tile_manager_draw::
;tile_manager.c:10: for( tx = 2; tx < 32; tx += 2 )
	ld	b, #0x02
00103$:
;tile_manager.c:12: draw( tx, 0 );
	push	bc
	xor	a, a
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_draw
	pop	af
	pop	bc
;tile_manager.c:13: draw( tx, 22 );
	push	bc
	ld	a, #0x16
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_draw
	pop	af
	pop	bc
;tile_manager.c:10: for( tx = 2; tx < 32; tx += 2 )
	inc	b
	inc	b
	ld	a, b
	sub	a, #0x20
	jr	C,00103$
;tile_manager.c:16: for( ty = 2; ty < 22; ty += 2 )
	ld	b, #0x02
00105$:
;tile_manager.c:18: draw( 2, ty );
	push	bc
	push	bc
	inc	sp
	ld	a, #0x02
	push	af
	inc	sp
	call	_draw
	pop	af
	pop	bc
;tile_manager.c:19: draw( 30, ty );
	push	bc
	push	bc
	inc	sp
	ld	a, #0x1e
	push	af
	inc	sp
	call	_draw
	pop	af
	pop	bc
;tile_manager.c:16: for( ty = 2; ty < 22; ty += 2 )
	inc	b
	inc	b
	ld	a, b
	sub	a, #0x16
	jr	C,00105$
	ret
;tile_manager.c:23: static void draw( unsigned char x, unsigned char y )
;	---------------------------------
; Function draw
; ---------------------------------
_draw:
	push	ix
	ld	ix,#0
	add	ix,sp
;tile_manager.c:25: const unsigned char *pnt = tree_avoid__tilemap__bin;
;tile_manager.c:27: devkit_SMS_setNextTileatXY( x + 0, y + 0 ); devkit_SMS_setTile( *pnt + 0 );
	ld	h, 5 (ix)
	ld	l, 4 (ix)
	push	hl
	call	_devkit_SMS_setNextTileatXY
	pop	af
	ld	hl, #_tree_avoid__tilemap__bin + 0
	ld	b, (hl)
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
;tile_manager.c:28: devkit_SMS_setNextTileatXY( x + 1, y + 0 ); devkit_SMS_setTile( *pnt + 1 );
	ld	c, 4 (ix)
	inc	c
	push	bc
	ld	b, 5 (ix)
	push	bc
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	bc
	ld	hl, #_tree_avoid__tilemap__bin + 0
	ld	b, (hl)
	inc	b
	push	bc
	push	bc
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	bc
;tile_manager.c:29: devkit_SMS_setNextTileatXY( x + 0, y + 1 ); devkit_SMS_setTile( *pnt + 2 );
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
	ld	hl, #_tree_avoid__tilemap__bin + 0
	ld	d, (hl)
	inc	d
	inc	d
	push	bc
	push	de
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	ld	a, (#_tree_avoid__tilemap__bin + 0)
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
