#ifndef _GAME_H_
#define _GAME_H_

#include "keyboard.h"

/*---変数を定義する場所---*/
static int x,y,r;   // プレイヤーの座標
static int ex, ey, er;   // プレイヤーの座標
static int image; // 画像格納用変数
static bool flg;  // 初期化フラグ用

/*---関数を定義する場所---*/

void game_init();
void game_test();

#endif // !_GAME_H_