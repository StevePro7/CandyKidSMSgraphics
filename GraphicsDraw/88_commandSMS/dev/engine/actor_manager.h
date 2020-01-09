#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

// Public method.
void engine_actor_manager_update();

// Execute commands.
void engine_actor_manager_exec_fire( unsigned int index );
void engine_actor_manager_exec_jump( unsigned int index );
void engine_actor_manager_exec_move( unsigned int index );

// Undo commands.
void engine_actor_manager_undo_fire( unsigned int index );
void engine_actor_manager_undo_jump( unsigned int index );
void engine_actor_manager_undo_move( unsigned int index );

#endif//_ACTOR_MANAGER_H_