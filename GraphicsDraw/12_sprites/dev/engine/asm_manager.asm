;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module asm_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _engine_asm_manager_clear_VRAM
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
_VDPControlPort	=	0x00bf
_VDPDataPort	=	0x00be
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
;asm_manager.c:11: void engine_asm_manager_clear_VRAM()
;	---------------------------------
; Function engine_asm_manager_clear_VRAM
; ---------------------------------
_engine_asm_manager_clear_VRAM::
;asm_manager.c:30: __endasm;
	ld	a, #0x00
	out(	_VDPControlPort ), a
	ld	a, #0x40
	out(	_VDPControlPort ), a
	ld	bc, #0x4000
	  ClearVRAMLoop:
	ld	a, #0x00
	out(	_VDPDataPort ), a
	dec	bc
	ld	a, b
	or	c
	jp	nz, ClearVRAMLoop
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
