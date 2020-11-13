;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module input_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_getKeysStatus
	.globl _engine_input_manager_update
	.globl _engine_input_manager_hold
	.globl _engine_input_manager_move
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
_curr_joypad1:
	.ds 2
_prev_joypad1:
	.ds 2
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
;input_manager.c:10: void engine_input_manager_update()
;	---------------------------------
; Function engine_input_manager_update
; ---------------------------------
_engine_input_manager_update::
;input_manager.c:12: prev_joypad1 = curr_joypad1;
	ld	hl, (_curr_joypad1)
	ld	(_prev_joypad1), hl
;input_manager.c:13: curr_joypad1 = devkit_SMS_getKeysStatus();
	call	_devkit_SMS_getKeysStatus
	ld	(_curr_joypad1), hl
	ret
;input_manager.c:17: unsigned char engine_input_manager_hold( unsigned char data )
;	---------------------------------
; Function engine_input_manager_hold
; ---------------------------------
_engine_input_manager_hold::
;input_manager.c:19: return curr_joypad1 & data && !( prev_joypad1 & data );
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	b, #0x00
	ld	iy, #_curr_joypad1
	ld	a, 0 (iy)
	and	a, c
	ld	e, a
	ld	a, 1 (iy)
	and	a, b
	or	a,e
	jr	Z,00103$
	ld	a, c
	ld	iy, #_prev_joypad1
	and	a, 0 (iy)
	ld	c, a
	ld	a, b
	and	a, 1 (iy)
	or	a,c
	jr	Z,00104$
00103$:
	ld	l, #0x00
	ret
00104$:
	ld	l, #0x01
	ret
;input_manager.c:22: unsigned char engine_input_manager_move( unsigned char data )
;	---------------------------------
; Function engine_input_manager_move
; ---------------------------------
_engine_input_manager_move::
;input_manager.c:24: return curr_joypad1 & data;
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	a,(#_curr_joypad1 + 0)
	and	a, c
	ld	l, a
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__curr_joypad1:
	.dw #0x0000
__xinit__prev_joypad1:
	.dw #0x0000
	.area _CABS (ABS)
