#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include "..\object\state_object.h"

// Global variables.
extern struct_state_object global_state_object;

// Methods.
void engine_state_manager_init();
void engine_state_manager_set_exits( unsigned char exits );
void engine_state_manager_set_trees( unsigned char trees );

#endif//_STATE_MANAGER_H_