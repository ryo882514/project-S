#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"
#include "keyboard.h"

/*---�ϐ����`����ꏊ---*/

// �v���C���[�̈ʒu
extern float PlayerX, PlayerY;
extern int Player_Size;
extern float bx[13], by[13];

static float vx[13], vy[13];
static float s;
static int limit;
extern bool bflag[13];
static bool Player_Initflg = false;

/*---�֐����`����ꏊ---*/
 void Player_Init();
 void Player_Update();
 void GraphDraw();
 void Bullet();

#endif // !_PLAYER_H_