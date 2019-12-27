;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.9 #9960 (MINGW64)
;--------------------------------------------------------
	.module storage_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_SRAM
	.globl _devkit_SMS_disableSRAM
	.globl _devkit_SMS_enableSRAM
	.globl _isSaveGamePresent
	.globl _readSaveGame
	.globl _writeSaveGame
	.globl _getPoints
	.globl _incPoints
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
_lives:
	.ds 1
_points:
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
;storage_manager.c:19: bool isSaveGamePresent()
;	---------------------------------
; Function isSaveGamePresent
; ---------------------------------
_isSaveGamePresent::
;storage_manager.c:22: struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	call	_devkit_SMS_SRAM
;storage_manager.c:25: devkit_SMS_enableSRAM();
	push	hl
	call	_devkit_SMS_enableSRAM
	pop	hl
;storage_manager.c:26: foundMagic = ( MAGIC == savegame->Magic );
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	inc	hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	a, c
	sub	a, #0x02
	jr	NZ,00103$
	ld	a, b
	sub	a, #0xb0
	jr	NZ,00103$
	ld	a, e
	sub	a, #0xe0
	jr	NZ,00103$
	ld	a, d
	sub	a, #0xac
	jr	NZ,00103$
	ld	a,#0x01
	jr	00104$
00103$:
	xor	a,a
00104$:
	ld	l, a
;storage_manager.c:27: devkit_SMS_disableSRAM();
	push	hl
	call	_devkit_SMS_disableSRAM
	pop	hl
;storage_manager.c:28: return foundMagic;
	ret
;storage_manager.c:31: void readSaveGame()
;	---------------------------------
; Function readSaveGame
; ---------------------------------
_readSaveGame::
;storage_manager.c:34: struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	call	_devkit_SMS_SRAM
;storage_manager.c:35: devkit_SMS_enableSRAM();
	push	hl
	call	_devkit_SMS_enableSRAM
	pop	bc
;storage_manager.c:36: lives = savegame->lives;
	ld	l, c
	ld	h, b
	ld	de, #0x0004
	add	hl, de
	ld	a, (hl)
	ld	(#_lives + 0),a
;storage_manager.c:37: points = savegame->points;
	ld	l, c
	ld	h, b
	ld	de, #0x0005
	add	hl, de
	ld	a, (hl)
	ld	iy, #_points
	ld	0 (iy), a
	inc	hl
	ld	a, (hl)
	ld	1 (iy), a
;storage_manager.c:38: devkit_SMS_disableSRAM();
	jp  _devkit_SMS_disableSRAM
;storage_manager.c:41: void writeSaveGame()
;	---------------------------------
; Function writeSaveGame
; ---------------------------------
_writeSaveGame::
;storage_manager.c:44: struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	call	_devkit_SMS_SRAM
;storage_manager.c:45: devkit_SMS_enableSRAM();
	push	hl
	call	_devkit_SMS_enableSRAM
	pop	bc
;storage_manager.c:46: savegame->Magic = MAGIC;
	ld	l, c
	ld	h, b
	ld	(hl), #0x02
	inc	hl
	ld	(hl), #0xb0
	inc	hl
	ld	(hl), #0xe0
	inc	hl
	ld	(hl), #0xac
;storage_manager.c:47: savegame->lives = lives;
	ld	hl, #0x0004
	add	hl, bc
	ld	a,(#_lives + 0)
	ld	(hl), a
;storage_manager.c:48: savegame->points = points;
	ld	hl, #0x0005
	add	hl, bc
	ld	iy, #_points
	ld	a, 0 (iy)
	ld	(hl), a
	inc	hl
	ld	a, 1 (iy)
	ld	(hl), a
;storage_manager.c:49: devkit_SMS_disableSRAM();
	jp  _devkit_SMS_disableSRAM
;storage_manager.c:52: unsigned int getPoints()
;	---------------------------------
; Function getPoints
; ---------------------------------
_getPoints::
;storage_manager.c:54: return points;
	ld	hl, (_points)
	ret
;storage_manager.c:57: void incPoints()
;	---------------------------------
; Function incPoints
; ---------------------------------
_incPoints::
;storage_manager.c:59: points++;
	ld	iy, #_points
	inc	0 (iy)
	ret	NZ
	inc	1 (iy)
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__lives:
	.db #0x03	; 3
__xinit__points:
	.dw #0x0000
	.area _CABS (ABS)
