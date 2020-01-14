#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_


#include "..\object\command_object.h"

// Global variable.
extern struct_command_object global_command_object;

// Public methods.
void engine_command_manager_init();
void engine_command_manager_add( unsigned int frame, unsigned char command_type, unsigned int args );

//void engine_command_manager_execute();
void engine_command_manager_execute( unsigned int frame );

//void engine_command_manager_undo();
void engine_command_manager_undo( unsigned int frame );

//void engine_command_manager_setframes( unsigned int* input );
//void engine_command_manager_set_save_frames( unsigned int* frames );

void engine_command_manager_set_load( unsigned char in_frames, unsigned char in_commands, unsigned int* frames, unsigned int* counts, unsigned int* commands, unsigned int* args );
void engine_command_manager_save();
unsigned char engine_command_manager_align_undo();

#endif//_COMMAND_MANAGER_H_