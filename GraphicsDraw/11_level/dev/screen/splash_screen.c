#include "splash_screen.h"
#include "..\engine\enum_manager.h"

void screen_splash_screen_load()
{
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_splash;
}