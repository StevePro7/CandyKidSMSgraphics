#include "frame_manager.h"

#define MAX_INT_VALUE	65535

// Global variable.
struct_frame_object global_frame_object;

void engine_frame_manager_init()
{
	struct_frame_object *fo = &global_frame_object;
	fo->frame_count = 0;
	fo->frame_delta = 0;
}

void engine_frame_manager_load()
{
	struct_frame_object *fo = &global_frame_object;
	fo->frame_delta = 0;
}

void engine_frame_manager_update()
{
	struct_frame_object *fo = &global_frame_object;
	fo->frame_count++;
	//if ( fo->frame_count >=  )
	fo->frame_delta++;
}