#ifndef _SAVEGAME_OBJECT_H_
#define _SAVEGAME_OBJECT_H_

// Reference: http://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures#91899
typedef struct tag_struct_savegame_object
{
	unsigned long Magic;
	unsigned char save_tree_type;
	unsigned char save_exit_type;
	unsigned char commands[ 10 ];

} struct_savegame_object;

#endif//_SAVEGAME_OBJECT_H_