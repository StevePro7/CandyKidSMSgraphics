#ifndef _COMMAND_OBJECT_H_
#define _COMMAND_OBJECT_H_

#include "..\engine\global_manager.h"

typedef struct tag_struct_command_object
{
	unsigned char no_frames;
	unsigned char no_commands;
	unsigned int frames[ MAX_COMMANDS ];
	unsigned int counts[ MAX_COMMANDS ];
	unsigned int commands[ MAX_COMMANDS ];
	unsigned int args[ MAX_COMMANDS ];

} struct_command_object;

#endif//_COMMAND_OBJECT_H_