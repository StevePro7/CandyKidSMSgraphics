#ifndef _SAVEGAME_OBJECT_H_
#define _SAVEGAME_OBJECT_H_

#include "..\engine\global_manager.h"

// Reference: http://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures#91899
typedef struct tag_struct_savegame_object
{
	unsigned long Magic;
	unsigned char save_tree_type;
	unsigned char save_exit_type;
	unsigned int frames[ MAX_COMMANDS ];
	unsigned int counts[ MAX_COMMANDS ];
	unsigned int commands[ MAX_COMMANDS ];
	unsigned int args[ MAX_COMMANDS ];

} struct_savegame_object;

#endif//_SAVEGAME_OBJECT_H_