#include "storage_manager.h"
#include "..\devkit\_sms_manager.h"

#define MAGIC			0xACE0B002

// Global variable.
//struct_savegame_object global_savegame_object;

struct my_savegame
{
	unsigned long Magic;   // this is here to check if the SRAM contains a savegame or not
	unsigned char lives;   // your hero lives counter
	unsigned int points;   // your hero points
};

static unsigned char lives = 3;
static unsigned int points = 0;

bool isSaveGamePresent()
{
	//struct_savegame_object *savegame = &global_savegame_object;
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );

	bool foundMagic;
	devkit_SMS_enableSRAM();
	foundMagic = ( MAGIC == savegame->Magic );
	devkit_SMS_disableSRAM();
	return foundMagic;
}

void readSaveGame()
{
	//struct_savegame_object *savegame = &global_savegame_object;
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	devkit_SMS_enableSRAM();
	lives = savegame->lives;
	points = savegame->points;
	devkit_SMS_disableSRAM();
}

void writeSaveGame()
{
	//struct_savegame_object *savegame = &global_savegame_object;
	struct_savegame_object *savegame = ( struct_savegame_object* ) ( devkit_SMS_SRAM() );
	devkit_SMS_enableSRAM();
	savegame->Magic = MAGIC;
	savegame->lives = lives;
	savegame->points = points;
	devkit_SMS_disableSRAM();
}

unsigned int getPoints()
{
	return points;
}

void incPoints()
{
	points++;
}

//void engine_storage_manager_init()
//{
//}
//
//void engine_storage_manager_update()
//{
//}