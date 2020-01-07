#include "main.h"

void main( void )
{
	engine_command_manager_init();

	engine_command_manager_add();
	engine_command_manager_execute();
	engine_command_manager_undo();
}
