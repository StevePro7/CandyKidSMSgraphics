#include "actor_manager.h"
#include <stdio.h>

// Public method.
void engine_actor_manager_update()
{
}

// Execute commands.
void engine_actor_manager_exec_fire()
{
	printf( "EXEC fire\n" );
}
void engine_actor_manager_exec_jump()
{
	printf( "EXEC jump\n" );
}
void engine_actor_manager_exec_move()
{
	printf( "EXEC move\n" );
}

// Undo commands.
void engine_actor_manager_undo_fire()
{
	printf( "UNDO fire\n" );
}
void engine_actor_manager_undo_jump()
{
	printf( "UNDO jump\n" );
}
void engine_actor_manager_undo_move()
{
	printf( "UNDO move\n" );
}