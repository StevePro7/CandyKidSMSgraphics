;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW64)
;--------------------------------------------------------
	.module input_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_PORT_A_KEY_2
	.globl _devkit_PORT_A_KEY_1
	.globl _devkit_PORT_A_KEY_RIGHT
	.globl _devkit_PORT_A_KEY_LEFT
	.globl _devkit_PORT_A_KEY_DOWN
	.globl _devkit_PORT_A_KEY_UP
	.globl _devkit_SMS_getKeysStatus
	.globl _engine_input_manager_update
	.globl _engine_input_manager_hold_up
	.globl _engine_input_manager_hold_down
	.globl _engine_input_manager_hold_left
	.globl _engine_input_manager_hold_right
	.globl _engine_input_manager_hold_fire1
	.globl _engine_input_manager_hold_fire2
	.globl _engine_input_manager_move_up
	.globl _engine_input_manager_move_down
	.globl _engine_input_manager_move_left
	.globl _engine_input_manager_move_right
	.globl _engine_input_manager_move_fire1
	.globl _engine_input_manager_move_fire2
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
;input_manager.c:13: void engine_input_manager_update()
;	---------------------------------
; Function engine_input_manager_update
; ---------------------------------
_engine_input_manager_update::
;input_manager.c:15: prev_joypad1 = curr_joypad1;
	ld	hl,(_curr_joypad1)
	ld	(_prev_joypad1),hl
;input_manager.c:16: curr_joypad1 = devkit_SMS_getKeysStatus();
	call	_devkit_SMS_getKeysStatus
	ld	(_curr_joypad1),hl
	ret
;input_manager.c:20: unsigned char engine_input_manager_hold_up()
;	---------------------------------
; Function engine_input_manager_hold_up
; ---------------------------------
_engine_input_manager_hold_up::
;input_manager.c:22: return engine_input_manager_hold( devkit_PORT_A_KEY_UP() );
	call	_devkit_PORT_A_KEY_UP
	push	hl
	call	_engine_input_manager_hold
	pop	af
	ret
;input_manager.c:24: unsigned char engine_input_manager_hold_down()
;	---------------------------------
; Function engine_input_manager_hold_down
; ---------------------------------
_engine_input_manager_hold_down::
;input_manager.c:26: return engine_input_manager_hold( devkit_PORT_A_KEY_DOWN() );
	call	_devkit_PORT_A_KEY_DOWN
	push	hl
	call	_engine_input_manager_hold
	pop	af
	ret
;input_manager.c:28: unsigned char engine_input_manager_hold_left()
;	---------------------------------
; Function engine_input_manager_hold_left
; ---------------------------------
_engine_input_manager_hold_left::
;input_manager.c:30: return engine_input_manager_hold( devkit_PORT_A_KEY_LEFT() );
	call	_devkit_PORT_A_KEY_LEFT
	push	hl
	call	_engine_input_manager_hold
	pop	af
	ret
;input_manager.c:32: unsigned char engine_input_manager_hold_right()
;	---------------------------------
; Function engine_input_manager_hold_right
; ---------------------------------
_engine_input_manager_hold_right::
;input_manager.c:34: return engine_input_manager_hold( devkit_PORT_A_KEY_RIGHT() );
	call	_devkit_PORT_A_KEY_RIGHT
	push	hl
	call	_engine_input_manager_hold
	pop	af
	ret
;input_manager.c:36: unsigned char engine_input_manager_hold_fire1()
;	---------------------------------
; Function engine_input_manager_hold_fire1
; ---------------------------------
_engine_input_manager_hold_fire1::
;input_manager.c:38: return engine_input_manager_hold( devkit_PORT_A_KEY_1() );
	call	_devkit_PORT_A_KEY_1
	push	hl
	call	_engine_input_manager_hold
	pop	af
	ret
;input_manager.c:40: unsigned char engine_input_manager_hold_fire2()
;	---------------------------------
; Function engine_input_manager_hold_fire2
; ---------------------------------
_engine_input_manager_hold_fire2::
;input_manager.c:42: return engine_input_manager_hold( devkit_PORT_A_KEY_2() );
	call	_devkit_PORT_A_KEY_2
	push	hl
	call	_engine_input_manager_hold
	pop	af
	ret
;input_manager.c:46: unsigned char engine_input_manager_move_up()
;	---------------------------------
; Function engine_input_manager_move_up
; ---------------------------------
_engine_input_manager_move_up::
;input_manager.c:48: return engine_input_manager_move( devkit_PORT_A_KEY_UP() );
	call	_devkit_PORT_A_KEY_UP
	push	hl
	call	_engine_input_manager_move
	pop	af
	ret
;input_manager.c:50: unsigned char engine_input_manager_move_down()
;	---------------------------------
; Function engine_input_manager_move_down
; ---------------------------------
_engine_input_manager_move_down::
;input_manager.c:52: return engine_input_manager_move( devkit_PORT_A_KEY_DOWN() );
	call	_devkit_PORT_A_KEY_DOWN
	push	hl
	call	_engine_input_manager_move
	pop	af
	ret
;input_manager.c:54: unsigned char engine_input_manager_move_left()
;	---------------------------------
; Function engine_input_manager_move_left
; ---------------------------------
_engine_input_manager_move_left::
;input_manager.c:56: return engine_input_manager_move( devkit_PORT_A_KEY_LEFT() );
	call	_devkit_PORT_A_KEY_LEFT
	push	hl
	call	_engine_input_manager_move
	pop	af
	ret
;input_manager.c:58: unsigned char engine_input_manager_move_right()
;	---------------------------------
; Function engine_input_manager_move_right
; ---------------------------------
_engine_input_manager_move_right::
;input_manager.c:60: return engine_input_manager_move( devkit_PORT_A_KEY_RIGHT() );
	call	_devkit_PORT_A_KEY_RIGHT
	push	hl
	call	_engine_input_manager_move
	pop	af
	ret
;input_manager.c:62: unsigned char engine_input_manager_move_fire1()
;	---------------------------------
; Function engine_input_manager_move_fire1
; ---------------------------------
_engine_input_manager_move_fire1::
;input_manager.c:64: return engine_input_manager_move( devkit_PORT_A_KEY_1() );
	call	_devkit_PORT_A_KEY_1
	push	hl
	call	_engine_input_manager_move
	pop	af
	ret
;input_manager.c:66: unsigned char engine_input_manager_move_fire2()
;	---------------------------------
; Function engine_input_manager_move_fire2
; ---------------------------------
_engine_input_manager_move_fire2::
;input_manager.c:68: return engine_input_manager_move( devkit_PORT_A_KEY_2() );
	call	_devkit_PORT_A_KEY_2
	push	hl
	call	_engine_input_manager_move
	pop	af
	ret
;input_manager.c:72: static unsigned char engine_input_manager_hold( unsigned int data )
;	---------------------------------
; Function engine_input_manager_hold
; ---------------------------------
_engine_input_manager_hold:
;input_manager.c:74: return curr_joypad1 & data && !( prev_joypad1 & data );
	ld	a,(#_curr_joypad1 + 0)
	ld	iy,#2
	add	iy,sp
	and	a, 0 (iy)
	ld	c,a
	ld	a,(#_curr_joypad1 + 1)
	ld	iy,#2
	add	iy,sp
	and	a, 1 (iy)
	or	a,c
	jr	Z,00103$
	ld	a,(#_prev_joypad1 + 0)
	ld	iy,#2
	add	iy,sp
	and	a, 0 (iy)
	ld	c,a
	ld	a,(#_prev_joypad1 + 1)
	ld	iy,#2
	add	iy,sp
	and	a, 1 (iy)
	or	a,c
	jr	Z,00104$
00103$:
	ld	l,#0x00
	ret
00104$:
	ld	l,#0x01
	ret
;input_manager.c:76: static unsigned char engine_input_manager_move( unsigned int data )
;	---------------------------------
; Function engine_input_manager_move
; ---------------------------------
_engine_input_manager_move:
;input_manager.c:78: return curr_joypad1 & data;
	ld	a,(#_curr_joypad1 + 0)
	ld	iy,#2
	add	iy,sp
	and	a, 0 (iy)
	ld	l,a
	ld	a,(#_curr_joypad1 + 1)
	ld	iy,#2
	add	iy,sp
	and	a, 1 (iy)
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__curr_joypad1:
	.dw #0x0000
__xinit__prev_joypad1:
	.dw #0x0000
	.area _CABS (ABS)
