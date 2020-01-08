#include "move_manager.h"
#include "enum_manager.h"
#include "gamer_manager.h"
#include "level_manager.h"
#include "state_manager.h"

unsigned char engine_move_manager_check( unsigned char direction )
{
	struct_gamer_object *go = &global_gamer_object;
	struct_level_object *lo = &global_level_object;
	struct_state_object *so = &global_state_object;

	if( tree_type_death == so->trees_choice )
	{
		return direction;
	}

	// TODO complete this logic!
	return direction_type_none;
}