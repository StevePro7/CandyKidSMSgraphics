#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include "..\object\event_object.h"

// Global variable.
extern struct_event_object global_event_object;

// Methods.
void engine_event_manager_init();
void engine_event_manager_clear();
void engine_event_manager_add_event( unsigned char type, unsigned char args );
void engine_event_manager_process_events();
void engine_event_manager_process_event( unsigned type, unsigned args );

unsigned char engine_event_manager_kidMove();
void engine_event_manager_move1( unsigned int frameCount, unsigned char theMove );

#endif//_EVENT_MANAGER_H_