#include "storage_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\command_manager.h"

#define MAGIC			0xACE0B004

// Global variable.
struct_savegame_object global_savegame_object;

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
	engine_command_manager_set_save_frames( savegame->commands );
	devkit_SMS_disableSRAM();
}

void engine_storage_manager_write()
{
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	struct_board_object *bo = &global_board_object;
	struct_command_master *co = &global_command_master;
	unsigned int idx;

	devkit_SMS_enableSRAM();
	savegame->Magic = MAGIC;
	savegame->save_tree_type = bo->save_tree_type;
	savegame->save_exit_type = bo->save_exit_type;

	for( idx = 0; idx < 3; idx++ )
	{
		savegame->commands[ idx ] = co->save_frames[ idx ];
	}

	devkit_SMS_disableSRAM();
}