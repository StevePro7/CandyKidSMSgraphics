#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_

#include "..\object\command_object.h"

#define MAX_COMMANDS	10

// Global variable.
//extern struct_command_object global_command_object;
extern struct_command_object global_command_objects[ MAX_COMMANDS ];

// Public methods.
void engine_command_manager_init();
void engine_command_manager_add( unsigned int frame, unsigned char command_type, unsigned char delta, unsigned char timer );
//void engine_command_manager_execute( unsigned int frame )
void engine_command_manager_execute();
//void engine_command_manager_undo( unsigned int frame )
void engine_command_manager_undo();

void engine_command_manager_setframes( unsigned int* input );

#endif//_COMMAND_MANAGER_H_