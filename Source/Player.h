#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"
#include "keyboard.h"

/*---変数を定義する場所---*/
static int Magnification;	// 視点の倍率　x1～x64までの1,2,4,8,16,32,64の7段階
// プレイヤーの位置
static float PlayerX, PlayerY;
static int Player_Size;
static int Save_Magnification;
static int scrollflg;
static int MouseX, MouseY;
static int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
static int DrawMapChipNumX, DrawMapChipNumY;	// 描画サイズ
static float Mouse;
static float bx[13], by[13];
static float vx[13], vy[13];
static float s;
static int limit;
static bool bflag[13];
static bool Player_Initflg = false;
/*---関数を定義する場所---*/
 void Player_Init();
 void Player_Update();
 void GraphDraw();
 void zoom();
 void Bullet();
#endif // !_GAME_H_