#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

// Public method.
void engine_actor_manager_update();

// Execute commands.
void engine_actor_manager_exec_fire( unsigned char args );
//void engine_actor_manager_exec_jump();
//void engine_actor_manager_exec_move();
//
//// Undo commands.
//void engine_actor_manager_undo_fire();
//void engine_actor_manager_undo_jump();
//void engine_actor_manager_undo_move();

#endif//_ACTOR_MANAGER_H_