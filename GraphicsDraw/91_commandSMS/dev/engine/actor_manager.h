#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

// Public method.
void engine_actor_manager_update();

// Execute commands.
void engine_actor_manager_exec_fire( unsigned char args );
void engine_actor_manager_exec_jump( unsigned char args );
void engine_actor_manager_exec_move( unsigned char args );
void engine_actor_manager_exec_bank4( unsigned char args );
void engine_actor_manager_exec_bank5( unsigned char args );
void engine_actor_manager_exec_bank6( unsigned char args );
void engine_actor_manager_exec_bank7( unsigned char args );
void engine_actor_manager_exec_speed( unsigned char args );
void engine_actor_manager_exec_steve( unsigned char args );

// Undo commands.
void engine_actor_manager_undo_fire( unsigned char args );
void engine_actor_manager_undo_jump( unsigned char args );
void engine_actor_manager_undo_move( unsigned char args );
void engine_actor_manager_undo_bank4( unsigned char args );
void engine_actor_manager_undo_bank5( unsigned char args );
void engine_actor_manager_undo_bank6( unsigned char args );
void engine_actor_manager_undo_bank7( unsigned char args );
void engine_actor_manager_undo_speed( unsigned char args );
void engine_actor_manager_undo_steve( unsigned char args );

#endif//_ACTOR_MANAGER_H_