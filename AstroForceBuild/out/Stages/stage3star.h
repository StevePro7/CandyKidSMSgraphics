#ifndef _STAGE3STAR_H_
#define _STAGE3STAR_H_

typedef struct stage3star;
stage3star stage3stars[ MAXSTAGE3STARS ];;
void InitStage3Star( stage3star *st, unsigned char speed );
void UpdateStarMovement( stage3star *st );
void UpdateStage3Star( stage3star *st );
void UpdateStage5Cloud( stage3star *st );

#endif//_STAGE3STAR_H_
