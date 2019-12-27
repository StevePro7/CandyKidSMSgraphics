#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

#include "global_manager.h"
#include "..\object\enemy_object.h"

// Global variables.
extern struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

// Methods.
void engine_enemy_manager_init();

#endif//_ENEMY_MANAGER_H_