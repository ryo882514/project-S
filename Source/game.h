#ifndef _GAME_H_
#define _GAME_H_

#include "keyboard.h"

/*---�ϐ����`����ꏊ---*/
static int x,y,r;   // �v���C���[�̍��W
static int ex, ey, er;   // �v���C���[�̍��W
static int image; // �摜�i�[�p�ϐ�
static bool flg;  // �������t���O�p

/*---�֐����`����ꏊ---*/

void game_init();
void game_test();

#endif // !_GAME_H_