#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_

#define MAX_COMMANDS	10

// Global variable.
//extern struct_command_master global_command_master;
//extern struct_command_object global_command_objects[ MAX_COMMANDS ];

// Public methods.
void engine_command_manager_init();
void engine_command_manager_add( unsigned int frame, unsigned char command_type, unsigned int args );

//void engine_command_manager_execute();
void engine_command_manager_execute( unsigned int frame );

//void engine_command_manager_undo();
void engine_command_manager_undo( unsigned int frame );

//void engine_command_manager_setframes( unsigned int* input );
//void engine_command_manager_set_save_frames( unsigned int* frames );

void engine_command_manager_set_playback( unsigned char* frames, unsigned char* counts, unsigned char* commands, unsigned char* args );
unsigned char engine_command_manager_align_undo();

#endif//_COMMAND_MANAGER_H_