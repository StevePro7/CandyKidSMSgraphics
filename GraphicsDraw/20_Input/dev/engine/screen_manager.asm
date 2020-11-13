;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module screen_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _engine_input_manager_hold
	.globl _engine_font_manager_draw_data
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
;screen_manager.c:7: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:9: engine_font_manager_draw_data( 10, 10, 10 );
	ld	hl, #0x0a0a
	push	hl
	ld	h, #0x00
	push	hl
	call	_engine_font_manager_draw_data
	pop	af
	pop	af
	ret
;screen_manager.c:12: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:18: input = engine_input_manager_hold( 0x04 );			// left
	ld	a, #0x04
	push	af
	inc	sp
	call	_engine_input_manager_hold
	inc	sp
;screen_manager.c:19: if (input)
	ld	a, l
	or	a, a
	ret	Z
;screen_manager.c:21: engine_font_manager_draw_data( 20, 20, 20 );
	ld	hl, #0x1414
	push	hl
	ld	h, #0x00
	push	hl
	call	_engine_font_manager_draw_data
	pop	af
	pop	af
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
