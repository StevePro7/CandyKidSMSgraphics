#include "event_manager.h"
#include "command_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "gamer_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "mask_manager.h"

// Global variable.
struct_event_object global_event_object;

// Methods.
void engine_event_manager_init()
{
	struct_event_object *ev = &global_event_object;
	unsigned int idx;

	ev->move1Index = 0;
	for( idx = 0; idx < MAX_MOVES_COUNT; idx++ )
	{
		ev->move1Frame[ idx ] = 0;
		ev->move1Event[ idx ] = 0;
	}
}

void engine_event_manager_clear()
{
	struct_event_object *ev = &global_event_object;
	ev->event_index = 0;
}

void engine_event_manager_add_event( unsigned char type, unsigned char args )
{
	struct_event_object *ev = &global_event_object;
	unsigned char index = ev->event_index;
	ev->event_type[ index ] = type;
	ev->event_args[ index ] = args;
	ev->move1Index++;
}

void engine_event_manager_process_events()
{
	struct_event_object *ev = &global_event_object;
}

void engine_event_manager_process_event()
{
}

unsigned char engine_event_manager_kidMove()
{
	unsigned char kidMove = MOVEMENT_ALL_NONE_MASK;

	unsigned char input;
	input = engine_input_manager_move_up();
	if( input )
	{
		kidMove |= MOVEMENT_KID_UPXX_MASK;
	}
	else
	{
		input = engine_input_manager_move_down();
		if( input )
		{
			kidMove |= MOVEMENT_KID_DOWN_MASK;
		}
		else
		{
			input = engine_input_manager_move_left();
			if( input )
			{
				kidMove |= MOVEMENT_KID_LEFT_MASK;
			}
			else
			{
				input = engine_input_manager_move_right();
				if( input )
				{
					kidMove |= MOVEMENT_KID_RGHT_MASK;
				}
			}
		}
	}

	return kidMove;
}

void engine_event_manager_move1( unsigned int frameCount, unsigned char theMove )
{
	//Redundant check as is wrapped from caller.
	//if( MOVEMENT_ALL_NONE_MASK == ( theMove & MOVEMENT_ALL_NONE_MASK ) )
	//{
	//	return;
	//}

	engine_font_manager_draw_data( theMove, 30, 4 );

	// Must be at least one event!
	if( MOVEMENT_KID_UPXX_MASK == ( theMove & MOVEMENT_KID_UPXX_MASK ) )
	{
		engine_gamer_manager_move( direction_type_upxx );
	}
	else if( MOVEMENT_KID_DOWN_MASK == ( theMove & MOVEMENT_KID_DOWN_MASK ) )
	{
		engine_gamer_manager_move( direction_type_down );
	}
	else if( MOVEMENT_KID_LEFT_MASK == ( theMove & MOVEMENT_KID_LEFT_MASK ) )
	{
		engine_gamer_manager_move( direction_type_left );
	}
	else if( MOVEMENT_KID_RGHT_MASK == ( theMove & MOVEMENT_KID_RGHT_MASK ) )
	{
		engine_gamer_manager_move( direction_type_rght );
	}

	// TODO store command now
	frameCount *= 1;
	//engine_command_manager_move1( frameCount, theMove );
}