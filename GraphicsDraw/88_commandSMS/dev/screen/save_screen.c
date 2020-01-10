#include "save_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\storage_manager.h"
#include <stdbool.h>

void screen_save_screen_load()
{
	//bool test = isSaveGamePresent();
	unsigned char test = engine_storage_manager_available();

	engine_font_manager_draw_text( "HELLO", 2, 0 );
	engine_font_manager_draw_data( test, 2, 2 );
	engine_font_manager_draw_text( "THERE", 20, 2 );
	if( test )
	{
		engine_font_manager_draw_data( getPoints(), 12, 4 );
		//readSaveGame();
		engine_storage_manager_read();
		
		engine_font_manager_draw_data( getPoints(), 12, 5 );
		incPoints();
		engine_font_manager_draw_data( getPoints(), 12, 6 );
	}

	//writeSaveGame();
	engine_storage_manager_write();

	engine_font_manager_draw_text( "SAVE SCREEN...!!", 4, 1 );
}

void screen_save_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_save;
}