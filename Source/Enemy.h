#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "DxLib.h"
#include "keyboard.h"

/*---�ϐ����`����ꏊ---*/
extern int EnemyX,EnemyY;
extern int Enemy_Size;
static int cnt;
static bool EnemyInitFlg = false;

/*---�֐����`����ꏊ---*/
void Enemy_Init();
void Enemy_Update();
void Enemy_Move();
void Enemy_Draw();

#endif // !_ENEMY_H_