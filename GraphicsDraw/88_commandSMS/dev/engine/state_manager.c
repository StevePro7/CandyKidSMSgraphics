#include "state_manager.h"
#include "enum_manager.h"

// Global variables.
struct_state_object global_state_object;

// Methods.
void engine_state_manager_init()
{
	struct_state_object *so = &global_state_object;
	so->exits_choice = exit_type_public;
	so->trees_choice = tree_type_avoid;

	// TODO remove this
	so->trees_choice = tree_type_death;
}

void engine_state_manager_set_exits( unsigned char exits )
{
	struct_state_object *so = &global_state_object;
	so->exits_choice = exits;
}

void engine_state_manager_set_trees( unsigned char trees )
{
	struct_state_object *so = &global_state_object;
	so->trees_choice = trees;
}