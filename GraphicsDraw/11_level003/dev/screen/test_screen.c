#include "test_screen.h"
#include "..\engine\enum_manager.h"

void screen_test_screen_load()
{
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}