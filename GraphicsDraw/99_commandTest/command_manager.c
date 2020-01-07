#include "command_manager.h"
#include "actor_manager.h"

static void( *execute[ 3 ] )( );

static unsigned char commands[ 10 ];

// Public method.
void engine_command_manager_init()
{
	execute[ 0 ] = engine_actor_manager_fire;
	execute[ 1 ] = engine_actor_manager_jump;
	execute[ 2 ] = engine_actor_manager_move;
}

void engine_command_manager_add()
{
	commands[ 0 ] = 2;
	commands[ 1 ] = 0;
	commands[ 2 ] = 1;
}

void engine_command_manager_execute()
{
	unsigned char idx;
	unsigned char cmd;
	for( idx = 0; idx < 3; idx++ )
	{
		cmd = commands[ idx ];
		execute[ cmd ]();
	}
}