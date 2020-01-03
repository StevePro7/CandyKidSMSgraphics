#ifndef _COMMAND_OBJECT_H_
#define _COMMAND_OBJECT_H_

#define MAX_MOVES_COMMANDS	100
#define MAX_SPEED_COMMANDS	10

typedef struct tag_struct_command_object
{
	unsigned int frame_delta;
	unsigned char command;

	unsigned char move1_frames[ MAX_MOVES_COMMANDS ];
	unsigned char move1_events[ MAX_MOVES_COMMANDS ];
	unsigned char move2_frames[ MAX_MOVES_COMMANDS ];
	unsigned char move2_events[ MAX_MOVES_COMMANDS ];

	unsigned char speed_frames[ MAX_SPEED_COMMANDS ];
	unsigned char speed_events[ MAX_SPEED_COMMANDS ];

} struct_command_object;

#endif//_COMMAND_OBJECT_H_