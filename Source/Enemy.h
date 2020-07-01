#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "DxLib.h"
#include "keyboard.h"

/*---変数を定義する場所---*/
extern float EnemyX[100],EnemyY[100];
extern int Enemy_Size[100];
extern int E_HP[100];
extern bool E_Flg[100];
extern bool Rest_E_Flg[100];
extern int Rest_E;
static int cnt;
static bool EnemyInitFlg = false;

/*---関数を定義する場所---*/
void Enemy_Init();
void Enemy_Update();
void Enemy_Move();
void Enemy_Draw();

#endif // !_ENEMY_H_