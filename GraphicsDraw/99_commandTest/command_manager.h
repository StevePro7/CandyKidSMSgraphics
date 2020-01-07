#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_

#include "command_object.h"

// Global variable.
extern struct_command_object global_command_object;

// Public method.
void engine_command_manager_init();
void engine_command_manager_add( unsigned char index, unsigned char command, unsigned char delta, unsigned char timer );
void engine_command_manager_execute();
void engine_command_manager_undo();

#endif//_COMMAND_MANAGER_H_