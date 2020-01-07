#include "state_manager.h"
#include "actor_manager.h"
#include "command_manager.h"

void engine_state_manager_init()
{
	engine_command_manager_init();
}