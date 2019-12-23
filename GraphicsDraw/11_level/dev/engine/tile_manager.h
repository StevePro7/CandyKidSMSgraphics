#ifndef _TILE_MANAGER_H_
#define _TILE_MANAGER_H_

void engine_tile_manager_load_tile( unsigned char *tile_type, unsigned char tile_data );
void engine_tile_manager_load_coll( unsigned char *coll_type, unsigned char tile_data );
//void engine_tile_manager_draw_loop();
void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y );

#endif//_TILE_MANAGER_H_