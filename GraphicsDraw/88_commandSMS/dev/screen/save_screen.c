#include "save_screen.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\tile_manager.h"
#include <stdbool.h>

static void draw_trees();

void screen_save_screen_load()
{
	struct_board_object *bo = &global_board_object;
	struct_command_master *co = &global_command_master;
	unsigned char save_available;

	engine_board_manager_init();
	engine_command_manager_init();

	save_available = engine_storage_manager_available();
	engine_font_manager_draw_data( save_available, 2, 2 );

	if( save_available )
	{
		engine_font_manager_draw_text( "READ DATA", 12, 4 );
		engine_storage_manager_read();
	}


	engine_font_manager_draw_text( "LEFT  = EXITS", 6, 18 );
	engine_font_manager_draw_text( "RIGHT = TREES", 6, 19 );

	draw_trees();
	engine_font_manager_draw_data( co->save_frames[ 2 ], 30, 16 );
	engine_font_manager_draw_text( "SAVE SCREEN!!", 4, 1 );
}

void screen_save_screen_update( unsigned char *screen_type )
{
	struct_board_object *bo = &global_board_object;
	struct_command_master *co = &global_command_master;
	unsigned char input;
	unsigned int* frames;

	input = engine_input_manager_hold_left();
	if( input )
	{
		engine_board_manager_set_exit_type( 1 - bo->save_exit_type );
		draw_trees();
	}
	input = engine_input_manager_hold_right();
	if( input )
	{
		engine_board_manager_set_tree_type( 1 - bo->save_tree_type );
		draw_trees();
	}
	input = engine_input_manager_hold_down();
	if( input )
	{
		frames = co->save_frames;
		frames[ 2 ] += 100;
		engine_command_manager_set_save_frames( frames );
		engine_font_manager_draw_data( co->save_frames[ 2 ], 30, 16 );
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		engine_font_manager_draw_text( "SAVING....", 10, 20 );
		engine_storage_manager_write();
	}

	*screen_type = screen_type_save;
}


static void draw_trees()
{
	struct_board_object *bo = &global_board_object;

	unsigned char tree_type = bo->save_tree_type;
	unsigned char exit_type = bo->save_exit_type;

	engine_font_manager_draw_data( tree_type, 12, 12 );
	engine_font_manager_draw_data( exit_type, 12, 14 );

	engine_tile_manager_draw_tree( tree_type, 10, 8 );
	engine_tile_manager_draw_tree( tree_type, 16, 8 );

	if( exit_type_closed == exit_type )
	{
		engine_tile_manager_draw_tree( tree_type, 12, 8 );
		engine_tile_manager_draw_tree( tree_type, 14, 8 );
	}
	else
	{
		engine_tile_manager_draw_blank( 12, 8 );
		engine_tile_manager_draw_blank( 14, 8 );
	}
}