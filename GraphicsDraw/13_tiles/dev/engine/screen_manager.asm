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
;screen_manager.c:14: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
	dec	sp
;screen_manager.c:17: unsigned char idx = 24;
	ld	iy, #0
	add	iy, sp
	ld	0 (iy), #0x18
;screen_manager.c:21: draw_tiles( 4, 4, 0 );
	ld	hl, #0x0004
	push	hl
	ld	a, #0x04
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:22: draw_tiles( 8, 4, 4 );
	inc	sp
	ld	hl,#0x0404
	ex	(sp),hl
	ld	a, #0x08
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:25: draw_tiles( 12, 4, 8 );
	inc	sp
	ld	hl,#0x0804
	ex	(sp),hl
	ld	a, #0x0c
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:26: draw_tiles( 16, 4, 12 );
	inc	sp
	ld	hl,#0x0c04
	ex	(sp),hl
	ld	a, #0x10
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:27: draw_tiles( 20, 4, 16 );
	inc	sp
	ld	hl,#0x1004
	ex	(sp),hl
	ld	a, #0x14
	push	af
	inc	sp
	call	_draw_tiles
;screen_manager.c:28: draw_tiles( 24, 4, 20 );
	inc	sp
	ld	hl,#0x1404
	ex	(sp),hl
	ld	a, #0x18
	push	af
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
;screen_manager.c:31: for( y = 0; y < 4; y += 2 )
	ld	l, #0x00
;screen_manager.c:33: for( x = 2; x < 16; x += 2 )
00109$:
	ld	a, l
	add	a, #0x0a
	ld	h, a
	ld	iy, #0
	add	iy, sp
	ld	e, 0 (iy)
	ld	d, #0x02
00103$:
;screen_manager.c:35: draw_tiles( x + 4, y + 10, idx );
	ld	b, d
	inc	b
	inc	b
	inc	b
	inc	b
	push	hl
	push	de
	ld	a, e
	push	af
	inc	sp
	push	hl
	inc	sp
	push	bc
	inc	sp
	call	_draw_tiles
	pop	af
	inc	sp
	pop	de
	pop	hl
;screen_manager.c:36: idx += 4;
	inc	e
	inc	e
	inc	e
	inc	e
;screen_manager.c:33: for( x = 2; x < 16; x += 2 )
	inc	d
	inc	d
	ld	a, d
	sub	a, #0x10
	jr	C,00103$
;screen_manager.c:31: for( y = 0; y < 4; y += 2 )
	ld	iy, #0
	add	iy, sp
	ld	0 (iy), e
	inc	l
	inc	l
	ld	a, l
	sub	a, #0x04
	jr	C,00109$
	inc	sp
	ret
;screen_manager.c:42: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:70: }
	ret
;screen_manager.c:72: static void draw_tiles( unsigned char x, unsigned char y, unsigned char idx)
;	---------------------------------
; Function draw_tiles
; ---------------------------------
_draw_tiles:
	push	ix
	ld	ix,#0
	add	ix,sp
;screen_manager.c:74: const unsigned char *pnt = data_tiles__tilemap__bin;
;screen_manager.c:76: devkit_SMS_setNextTileatXY( x + 0, y + 0 ); devkit_SMS_setTile( *pnt + idx + 0 );
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
;screen_manager.c:77: devkit_SMS_setNextTileatXY( x + 1, y + 0 ); devkit_SMS_setTile( *pnt + idx + 1 );
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
;screen_manager.c:78: devkit_SMS_setNextTileatXY( x + 0, y + 1 ); devkit_SMS_setTile( *pnt + idx + 2 );
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
