#ifndef _SAVEGAME_OBJECT_H_
#define _SAVEGAME_OBJECT_H_

// Reference: http://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures#91899
typedef struct tag_struct_savegame_object
{
	unsigned long Magic;   // this is here to check if the SRAM contains a savegame or not
	unsigned char lives;   // your hero lives counter
	unsigned int points;   // your hero points

						   //unsigned long magic;   // this is here to check if the SRAM contains a savegame or not
						   //unsigned char mx;
						   //unsigned char my;
						   //unsigned char lives;   // your hero lives counter
						   //unsigned int points;   // your hero points

} struct_savegame_object;

#endif//_SAVEGAME_OBJECT_H_