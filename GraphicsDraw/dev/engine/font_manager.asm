;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW64)
;--------------------------------------------------------
	.module font_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_setTile
	.globl _devkit_SMS_setNextTileatXY
	.globl _engine_font_manager_draw_char
	.globl _engine_font_manager_draw_text
	.globl _engine_font_manager_draw_data
	.globl _engine_font_manager_draw_data_ZERO
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
;font_manager.c:10: void engine_font_manager_draw_char( unsigned char ch, unsigned char x, unsigned char y )
;	---------------------------------
; Function engine_font_manager_draw_char
; ---------------------------------
_engine_font_manager_draw_char::
;font_manager.c:12: const unsigned char *pnt = font_tiles__tilemap__bin;
;font_manager.c:13: unsigned char tile = ch - TEXT_ROOT;
	ld	hl, #2+0
	add	hl, sp
	ld	a, (hl)
	add	a,#0xe0
	ld	c,a
;font_manager.c:14: devkit_SMS_setNextTileatXY( x, y );
	push	bc
	ld	hl, #6+0
	add	hl, sp
	ld	a, (hl)
	push	af
	inc	sp
	ld	hl, #6+0
	add	hl, sp
	ld	a, (hl)
	push	af
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	bc
;font_manager.c:15: devkit_SMS_setTile( *pnt + tile );
	ld	a,(#_font_tiles__tilemap__bin + 0)
	add	a, c
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	ret
;font_manager.c:18: void engine_font_manager_draw_text( unsigned char *text, unsigned char x, unsigned char y )
;	---------------------------------
; Function engine_font_manager_draw_text
; ---------------------------------
_engine_font_manager_draw_text::
	push	ix
	ld	ix,#0
	add	ix,sp
;font_manager.c:20: const unsigned char *pnt = font_tiles__tilemap__bin;
;font_manager.c:23: while( '\0' != text[idx] )
	ld	c,6 (ix)
	ld	b,#0x00
00101$:
	ld	a,4 (ix)
	add	a, b
	ld	e,a
	ld	a,5 (ix)
	adc	a, #0x00
	ld	d,a
	ld	a,(de)
	or	a, a
	jr	Z,00104$
;font_manager.c:25: signed char tile = text[idx] - TEXT_ROOT;
	add	a,#0xe0
	ld	e,a
;font_manager.c:26: devkit_SMS_setNextTileatXY( x++, y );
	ld	d,c
	inc	c
	ld	6 (ix),c
	push	bc
	push	de
	ld	a,7 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
;font_manager.c:27: devkit_SMS_setTile( *pnt + tile );
	ld	a,(#_font_tiles__tilemap__bin + 0)
	add	a, e
	push	bc
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	bc
;font_manager.c:28: idx++;
	inc	b
	jr	00101$
00104$:
	pop	ix
	ret
;font_manager.c:32: void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y )
;	---------------------------------
; Function engine_font_manager_draw_data
; ---------------------------------
_engine_font_manager_draw_data::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl,#-10
	add	hl,sp
	ld	sp,hl
;font_manager.c:34: const unsigned char *pnt = font_tiles__tilemap__bin;
;font_manager.c:43: for( idx = 0; idx < DATA_LONG; ++idx )
	ld	hl,#0x0001
	add	hl,sp
	ld	-5 (ix),l
	ld	-4 (ix),h
	ld	a,6 (ix)
	ld	-1 (ix),a
	ld	-10 (ix),#0x00
00106$:
;font_manager.c:45: quotient = data / UNIT_ROOT;
	ld	hl,#0x000a
	push	hl
	ld	l,4 (ix)
	ld	h,5 (ix)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	c,l
	ld	b,h
	ld	-3 (ix),c
	ld	-2 (ix),b
;font_manager.c:46: remainder = data % UNIT_ROOT;
	push	bc
	ld	hl,#0x000a
	push	hl
	ld	l,4 (ix)
	ld	h,5 (ix)
	push	hl
	call	__moduint
	pop	af
	pop	af
	pop	bc
	ld	e,l
;font_manager.c:48: hold[idx] = remainder;
	ld	a,-10 (ix)
	add	a, -5 (ix)
	ld	l,a
	ld	a,#0x00
	adc	a, -4 (ix)
	ld	h,a
	ld	(hl),e
;font_manager.c:49: data /= UNIT_ROOT;
	ld	4 (ix),c
	ld	5 (ix),b
;font_manager.c:51: tile = hold[idx] + DATA_ROOT;
	ld	a,e
	add	a, #0x10
	ld	c,a
;font_manager.c:52: if( 0 == quotient && 0 == remainder && idx > 0 )
	ld	a,-2 (ix)
	or	a,-3 (ix)
	jr	NZ,00102$
	ld	a,e
	or	a, a
	jr	NZ,00102$
	ld	a,-10 (ix)
	or	a, a
	jr	Z,00102$
;font_manager.c:55: tile = 0;
	ld	c,#0x00
00102$:
;font_manager.c:58: devkit_SMS_setNextTileatXY( x--, y );
	ld	b,-1 (ix)
	dec	-1 (ix)
	ld	a,-1 (ix)
	ld	6 (ix),a
	push	bc
	ld	a,7 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	bc
;font_manager.c:59: devkit_SMS_setTile( *pnt + tile );
	ld	a,(#_font_tiles__tilemap__bin + 0)
	add	a, c
	push	af
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
;font_manager.c:43: for( idx = 0; idx < DATA_LONG; ++idx )
	inc	-10 (ix)
	ld	a,-10 (ix)
	sub	a, #0x04
	jp	C,00106$
	ld	sp, ix
	pop	ix
	ret
;font_manager.c:63: void engine_font_manager_draw_data_ZERO( unsigned int data, unsigned char x, unsigned char y )
;	---------------------------------
; Function engine_font_manager_draw_data_ZERO
; ---------------------------------
_engine_font_manager_draw_data_ZERO::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl,#-6
	add	hl,sp
	ld	sp,hl
;font_manager.c:65: const unsigned char *pnt = font_tiles__tilemap__bin;
;font_manager.c:72: for( idx = 0; idx < DATA_LONG; ++idx )
	ld	hl,#0x0000
	add	hl,sp
	ld	-2 (ix),l
	ld	-1 (ix),h
	ld	c,6 (ix)
	ld	b,#0x00
00102$:
;font_manager.c:74: hold[idx] = data % UNIT_ROOT;
	ld	a,b
	add	a, -2 (ix)
	ld	l,a
	ld	a,#0x00
	adc	a, -1 (ix)
	ld	h,a
	push	hl
	push	bc
	ld	de,#0x000a
	push	de
	ld	e,4 (ix)
	ld	d,5 (ix)
	push	de
	call	__moduint
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	pop	hl
	ld	(hl),e
;font_manager.c:75: data /= UNIT_ROOT;
	push	bc
	push	de
	ld	hl,#0x000a
	push	hl
	ld	l,4 (ix)
	ld	h,5 (ix)
	push	hl
	call	__divuint
	pop	af
	pop	af
	pop	de
	pop	bc
	ld	4 (ix),l
	ld	5 (ix),h
;font_manager.c:77: tile = hold[idx] + DATA_ROOT;
	ld	a,e
	add	a, #0x10
	ld	e,a
;font_manager.c:79: devkit_SMS_setNextTileatXY( x--, y );
	ld	d,c
	dec	c
	ld	6 (ix),c
	push	bc
	push	de
	ld	a,7 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	call	_devkit_SMS_setNextTileatXY
	pop	af
	pop	de
	pop	bc
;font_manager.c:80: devkit_SMS_setTile( *pnt + tile );
	ld	a,(#_font_tiles__tilemap__bin + 0)
	add	a, e
	ld	d,a
	push	bc
	push	de
	inc	sp
	call	_devkit_SMS_setTile
	inc	sp
	pop	bc
;font_manager.c:72: for( idx = 0; idx < DATA_LONG; ++idx )
	inc	b
	ld	a,b
	sub	a, #0x04
	jr	C,00102$
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
