#include "screen_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "storage_manager.h"
#include <stdbool.h>

#define NORMAL_TILES_TEXT	"STORAGE TEST"

void engine_screen_manager_init()
{
	bool test = isSaveGamePresent();
	engine_font_manager_draw_text( "HELLO", 2, 0 );
	engine_font_manager_draw_data( test, 2, 2 );
	engine_font_manager_draw_text( "THERE", 20, 2 );
	if( test )
	{
		engine_font_manager_draw_data( getPoints(), 12, 4 );
		readSaveGame();
		engine_font_manager_draw_data( getPoints(), 12, 5 );
		incPoints();
		engine_font_manager_draw_data( getPoints(), 12, 6 );
	}

	writeSaveGame();
}

void engine_screen_manager_update()
{
}