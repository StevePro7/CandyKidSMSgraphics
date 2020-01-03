#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_

#include "..\object\command_object.h"

// Global variable.
extern struct_command_object global_command_object;

// Methods.
//void engine_command_manager_move1( unsigned int frameCount, unsigned char theMove );

void engine_command_manager_init();
void engine_command_manager_load();

void engine_command_manager_save( unsigned int frame_delta );

void engine_command_move_up();
void engine_command_move_up2();
void engine_command_move_down();
void engine_command_move_left();
void engine_command_move_right();

#endif//_COMMAND_MANAGER_H_