#ifndef _COMMAND_OBJECT_H_
#define _COMMAND_OBJECT_H_

typedef struct tag_struct_command_object
{
	unsigned char frame;
	unsigned char command_type;
	unsigned char delta;
	unsigned char timer;

} struct_command_object;

#endif//_COMMAND_OBJECT_H_