#include "storage_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\engine\board_manager.h"

#define MAGIC			0xACE0B004

// Global variable.
struct_savegame_object global_savegame_object;

//struct my_savegame
//{
//	unsigned long Magic;   // this is here to check if the SRAM contains a savegame or not
//	unsigned char lives;   // your hero lives counter
//	unsigned int points;   // your hero points
//};

//static unsigned char save_exit_type = 5;
//static unsigned char save_tree_type = 0;


unsigned char engine_storage_manager_available()
{
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );

	unsigned char foundMagic;
	devkit_SMS_enableSRAM();
	foundMagic = MAGIC == savegame->Magic;
	devkit_SMS_disableSRAM();
	return foundMagic;
}

void engine_storage_manager_read()
{
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	struct_board_object *bo = &global_board_object;

	devkit_SMS_enableSRAM();
	engine_board_manager_set_tree_type( savegame->save_tree_type );
	engine_board_manager_set_exit_type( savegame->save_exit_type );
	devkit_SMS_disableSRAM();
}

void engine_storage_manager_write()
{
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	struct_board_object *bo = &global_board_object;

	devkit_SMS_enableSRAM();
	savegame->Magic = MAGIC;
	savegame->save_tree_type = bo->save_tree_type;
	savegame->save_exit_type = bo->save_exit_type;
	devkit_SMS_disableSRAM();
}

//unsigned char getPoints()
//{
//	return save_tree_type;
//}
//
//void incPoints()
//{
//	save_tree_type++;
//}