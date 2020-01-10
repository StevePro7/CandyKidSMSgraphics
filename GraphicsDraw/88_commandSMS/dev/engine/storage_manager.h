#ifndef _STORAGE_MANAGER_H_
#define _STORAGE_MANAGER_H_

#include "..\object\savegame_object.h"
#include <stdbool.h>

// Global variable.
//extern struct_savegame_object global_savegame_object;

bool isSaveGamePresent();
void readSaveGame();
void writeSaveGame();
unsigned int getPoints();
void incPoints();

//void engine_storage_manager_init();
//void engine_storage_manager_update();

#endif//_STORAGE_MANAGER_H_