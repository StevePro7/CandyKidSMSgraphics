#include "main.h"

void main( void )
{
	unsigned char input;
	engine_command_manager_init();

	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_command_manager_add( 0, 0, 10, 20 );
	}

	engine_command_manager_execute();
	
	engine_command_manager_undo();
}
