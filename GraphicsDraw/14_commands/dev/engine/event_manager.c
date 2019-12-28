#include "event_manager.h"
#include "enum_manager.h"
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
	if( MOVEMENT_KID_RGHT_MASK == ( theMove & MOVEMENT_KID_RGHT_MASK ) )
	{
		engine_gamer_manager_move( direction_type_rght );
	}
}