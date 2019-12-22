#include "level_manager.h"

#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include "..\devkit\_sms_manager.h"
#include <stdlib.h>

// Global variable.
struct_level_object global_level_object;

#define CRLF	2				// char
#define CR		'\r'			// 0x0d
#define LF		'\n'			// 0x0a

// Private helper methods.
static void load_level( const unsigned char *data, const unsigned char bank, const unsigned char size );

void engine_level_manager_init_level()
{
	struct_level_object *lo = &global_level_object;
	unsigned char idx, row, col;

	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < MAX_COLS; col++ )
		{
			idx = row * MAX_COLS + col;
		}
	}

	engine_tile_manager_draw_tile( 0, 4, 4 );
}

void engine_level_manager_load_level( const unsigned char world, const unsigned char round )
{
	unsigned char halve;
	unsigned char level;
	unsigned char index;

	halve = TOT_WORLDS / 2 * MAX_ROUNDS;
	level = world * MAX_ROUNDS + round;
	index = 0;

	if( level < halve )
	{
		const unsigned char *data = levelAAdata[ index ];
		const unsigned char bank = levelAAbank[ index ];
		const unsigned char size = levelAAsize[ index ];
		load_level( data, bank, size );
	}
}


static void load_level( const unsigned char *data, const unsigned char bank, const unsigned char size )
{
	struct_level_object *lo = &global_level_object;

	const unsigned char *o = data;
	unsigned char row, col;// , cnt;
	unsigned char tile_data;

	unsigned int idx;
	//enum_tile_type tile_type;
	//enum_coll_type coll_type;
	unsigned char tile_type;
	unsigned char coll_type;

	lo->load_cols = size / MAX_ROWS;
	lo->draw_cols = lo->load_cols - CRLF;

	lo->candyCount = 0;
	lo->bonusCount = 0;

	devkit_SMS_mapROMBank( bank );
	for( row = 0; row < MAX_ROWS; row++ )
	{
		tile_data = *o;
		for( col = 0; col < lo->load_cols; col++ )
		{
			if( !( tile_data == CR || tile_data == LF ) )
			{
				idx = row * MAX_COLS + col;

				engine_tile_manager_load_tile( &tile_type, tile_data );
				lo->drawtiles_array[ idx ] = tile_type;

				if( tile_type_candy == tile_type )
				{
					lo->candyCount++;
				}
				if( tile_type_bonusA == tile_type || tile_type_bonusB == tile_type || tile_type_bonusC == tile_type || tile_type_bonusD == tile_type )
				{
					lo->bonusCount++;
				}

				// TODO read from game object. 
				unsigned char trees_avoid = 1;
				engine_tile_manager_load_coll( &coll_type, tile_data, trees_avoid );
			}
		}
	}
}