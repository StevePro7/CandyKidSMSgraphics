#ifndef _TILE_MANAGER_H_
#define _TILE_MANAGER_H_

void engine_tile_manager_load_tile( unsigned char *tile_type, unsigned char tile_data );
void engine_tile_manager_load_coll( unsigned char *coll_type, unsigned char tile_data );

// TODO rename this as is too generic!
void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y );

void engine_tile_manager_draw_blank( unsigned char x, unsigned char y );
void engine_tile_manager_draw_tree( unsigned char type, unsigned char x, unsigned char y );
void engine_tile_manager_draw_candy( unsigned char type, unsigned char x, unsigned char y );
void engine_tile_manager_draw_bonus( unsigned char type, unsigned char multiplier, unsigned char x, unsigned char y );

#endif//_TILE_MANAGER_H_