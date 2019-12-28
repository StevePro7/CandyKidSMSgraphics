#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include "..\object\event_object.h"

// Global variable.
extern struct_event_object global_event_object;

// Methods.
void engine_event_manager_init();
void engine_event_manager_clear();
unsigned char engine_event_manager_kidMove();

#endif//_EVENT_MANAGER_H_