#include "screen_manager.h"
#include "font_manager.h"
#include "input_manager.h"

#define NORMAL_TILES_TEXT	"STORAGE TEST"

void engine_screen_manager_init()
{
	engine_font_manager_draw_data( 10, 10, 10 );
}

void engine_screen_manager_update()
{
	unsigned char input;
	//engine_font_manager_draw_data( 30, 20, 20 );
	
	//input = engine_input_manager_hold_up();
	input = engine_input_manager_hold( 0x04 );			// left
	if (input)
	{
		engine_font_manager_draw_data( 20, 20, 20 );
	}
}