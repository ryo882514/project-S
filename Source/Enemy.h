#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "DxLib.h"
#include "keyboard.h"

/*---変数を定義する場所---*/
extern int EnemyX,EnemyY;
extern int Enemy_Size;
static int cnt;
static bool EnemyInitFlg = false;

/*---関数を定義する場所---*/
void Enemy_Init();
void Enemy_Update();
void Enemy_Move();
void Enemy_Draw();

#endif // !_ENEMY_H_