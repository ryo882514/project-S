#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"
#include "keyboard.h"

/*---�ϐ����`����ꏊ---*/
static int Magnification;	// ���_�̔{���@x1�`x64�܂ł�1,2,4,8,16,32,64��7�i�K
// �v���C���[�̈ʒu
static float PlayerX, PlayerY;
static int Player_Size;
static int Save_Magnification;
static int scrollflg;
static int MouseX, MouseY;
static int MapDrawPointX, MapDrawPointY;		// �`�悷��}�b�v���W�l
static int DrawMapChipNumX, DrawMapChipNumY;	// �`��T�C�Y
static float Mouse;
static float bx[13], by[13];
static float vx[13], vy[13];
static float s;
static int limit;
static bool bflag[13];
static bool Player_Initflg = false;
/*---�֐����`����ꏊ---*/
 void Player_Init();
 void Player_Update();
 void GraphDraw();
 void zoom();
 void Bullet();
#endif // !_GAME_H_