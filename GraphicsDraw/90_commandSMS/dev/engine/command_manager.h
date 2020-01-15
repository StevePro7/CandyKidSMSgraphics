#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_


#include "..\object\command_object.h"

// Global variable.
extern struct_command_object global_command_object;

// Public methods.
void engine_command_manager_init();
void engine_command_manager_add( unsigned char frame, unsigned char command_type, unsigned int args );

void engine_command_manager_execute( unsigned int frame );

//void engine_command_manager_undo();
void engine_command_manager_undo( unsigned int frame );

void engine_command_manager_load( unsigned char* frames, unsigned char* commands, unsigned int* args );
void engine_command_manager_save();

unsigned char engine_command_manager_align_undo();

#endif//_COMMAND_MANAGER_H_