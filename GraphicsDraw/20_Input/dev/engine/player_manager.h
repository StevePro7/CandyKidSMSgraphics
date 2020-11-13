#ifndef _PLAYER_MANAGER_H_
#define _PLAYER_MANAGER_H_

#include "..\object\player_object.h"

// Global variable.
extern struct_player_object global_player_object;

// Methods.
void engine_player_manager_init( unsigned char px, unsigned char py );
void engine_player_manager_update( char dx, char dy );
void engine_player_manager_draw();

unsigned char engine_player_getX();
unsigned char engine_player_getY();

#endif//_PLAYER_MANAGER_H_