;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module player_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_addSprite
	.globl _global_player_object
	.globl _engine_player_manager_init
	.globl _engine_player_manager_update
	.globl _engine_player_manager_draw
	.globl _engine_player_getX
	.globl _engine_player_getY
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_global_player_object::
	.ds 2
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
;player_manager.c:16: void engine_player_manager_init( unsigned char px, unsigned char py )
;	---------------------------------
; Function engine_player_manager_init
; ---------------------------------
_engine_player_manager_init::
;player_manager.c:18: struct_player_object *po = &global_player_object;
	ld	bc, #_global_player_object+0
;player_manager.c:19: po->px = px;
	ld	hl, #2+0
	add	hl, sp
	ld	a, (hl)
	ld	(bc), a
;player_manager.c:20: po->py = py;
	inc	bc
	ld	hl, #3+0
	add	hl, sp
	ld	a, (hl)
	ld	(bc), a
	ret
;player_manager.c:23: void engine_player_manager_update( char dx, char dy )
;	---------------------------------
; Function engine_player_manager_update
; ---------------------------------
_engine_player_manager_update::
;player_manager.c:25: struct_player_object *po = &global_player_object;
	ld	hl, #_global_player_object+0
;player_manager.c:27: po->px += dx * PLAYER_VELOCITY;
	ld	c, (hl)
	ld	iy, #2
	add	iy, sp
	ld	a, 0 (iy)
	add	a, a
	add	a,c
	ld	(hl), a
;player_manager.c:28: po->py += dy * PLAYER_VELOCITY;
	inc	hl
	ld	c, (hl)
	ld	iy, #3
	add	iy, sp
	ld	a, 0 (iy)
	add	a, a
	add	a,c
	ld	(hl), a
	ret
;player_manager.c:48: void engine_player_manager_draw()
;	---------------------------------
; Function engine_player_manager_draw
; ---------------------------------
_engine_player_manager_draw::
;player_manager.c:50: struct_player_object *po = &global_player_object;
;player_manager.c:52: devkit_SMS_addSprite( po->px + 0, po->py + 0, PLAYER_SPRITE_TILE + 0 );
	ld	hl, #(_global_player_object + 0x0001) + 0
	ld	b, (hl)
	ld	hl, #_global_player_object + 0
	ld	d, (hl)
	ld	hl, #0x0100
	push	hl
	ld	c, d
	push	bc
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
;player_manager.c:53: devkit_SMS_addSprite( po->px + 8, po->py + 0, PLAYER_SPRITE_TILE + 1 );
	ld	hl, #(_global_player_object + 0x0001) + 0
	ld	b, (hl)
	ld	a, (#_global_player_object + 0)
	add	a, #0x08
	ld	d, a
	ld	hl, #0x0101
	push	hl
	ld	c, d
	push	bc
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
;player_manager.c:54: devkit_SMS_addSprite( po->px + 0, po->py + 8, PLAYER_SPRITE_TILE + 2 );
	ld	a, (#(_global_player_object + 0x0001) + 0)
	add	a, #0x08
	ld	b, a
	ld	hl, #_global_player_object + 0
	ld	d, (hl)
	ld	hl, #0x0102
	push	hl
	ld	c, d
	push	bc
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
;player_manager.c:55: devkit_SMS_addSprite( po->px + 8, po->py + 8, PLAYER_SPRITE_TILE + 3 );
	ld	a, (#(_global_player_object + 0x0001) + 0)
	add	a, #0x08
	ld	c, a
	ld	a, (#_global_player_object + 0)
	add	a, #0x08
	ld	b, a
	ld	hl, #0x0103
	push	hl
	ld	a, c
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
;player_manager.c:58: unsigned char engine_player_getX()
;	---------------------------------
; Function engine_player_getX
; ---------------------------------
_engine_player_getX::
;player_manager.c:60: struct_player_object *po = &global_player_object;
;player_manager.c:61: return po->px;
	ld	hl, #_global_player_object + 0
	ld	l, (hl)
	ret
;player_manager.c:63: unsigned char engine_player_getY()
;	---------------------------------
; Function engine_player_getY
; ---------------------------------
_engine_player_getY::
;player_manager.c:65: struct_player_object *po = &global_player_object;
;player_manager.c:66: return po->py;
	ld	hl, #_global_player_object + 1
	ld	l, (hl)
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
