;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW64)
;--------------------------------------------------------
	.module screen_manager
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _devkit_SMS_addSprite
	.globl _engine_font_manager_draw_text
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
;screen_manager.c:11: void engine_screen_manager_init()
;	---------------------------------
; Function engine_screen_manager_init
; ---------------------------------
_engine_screen_manager_init::
;screen_manager.c:13: engine_font_manager_draw_text( SPRITE_TILES_TEXT, 2, 0 );
	ld	hl,#0x0002
	push	hl
	ld	hl,#___str_0
	push	hl
	call	_engine_font_manager_draw_text
	pop	af
	pop	af
	ret
___str_0:
	.ascii "SPRITE TILES LOADED..."
	.db 0x00
;screen_manager.c:16: void engine_screen_manager_update()
;	---------------------------------
; Function engine_screen_manager_update
; ---------------------------------
_engine_screen_manager_update::
;screen_manager.c:18: draw_sprites();
	call	_draw_sprites
;screen_manager.c:19: draw_adriana();
	jp  _draw_adriana
;screen_manager.c:22: static void draw_sprites()
;	---------------------------------
; Function draw_sprites
; ---------------------------------
_draw_sprites:
;screen_manager.c:28: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl,#0x0100
	push	hl
	ld	hl,#0x2040
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:29: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0101
	ex	(sp),hl
	ld	hl,#0x2048
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:30: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	hl, #0x0102
	ex	(sp),hl
	ld	hl,#0x2840
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:31: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
	ld	hl, #0x0103
	ex	(sp),hl
	ld	hl,#0x2848
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
;screen_manager.c:53: static void draw_adriana()
;	---------------------------------
; Function draw_adriana
; ---------------------------------
_draw_adriana:
;screen_manager.c:59: devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	ld	hl,#0x0140
	push	hl
	ld	hl,#0x20b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:60: devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	ld	hl, #0x0141
	ex	(sp),hl
	ld	hl,#0x20b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:61: devkit_SMS_addSprite( x + 0, y + 8, tile + 2 );
	ld	hl, #0x0142
	ex	(sp),hl
	ld	hl,#0x28b0
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
;screen_manager.c:62: devkit_SMS_addSprite( x + 8, y + 8, tile + 3 );
	ld	hl, #0x0143
	ex	(sp),hl
	ld	hl,#0x28b8
	push	hl
	call	_devkit_SMS_addSprite
	pop	af
	pop	af
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
