
#include "DxLib.h"
#include "keyboard.h"
#include"Global.h"
int Mouse;
int MouseX, MouseY;
int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
int DrawMapChipNumX, DrawMapChipNumY;	// 描画サイズ

float PlayerX, PlayerY;
int Player_Size;
float bx[13], by[13];
bool bflag[13];
int EnemyX, EnemyY;
int Enemy_Size;

void Global_Update()
{
	//描画するマップサイズ
	DrawMapChipNumX = 800;
	DrawMapChipNumY = 700;

	// 画面中央に座標をセット
	MapDrawPointX = PlayerX - (DrawMapChipNumX - Player_Size) / 2;
	MapDrawPointY = PlayerY - (DrawMapChipNumY - Player_Size) / 2;

	Mouse = GetMouseInput();                //マウスの入力状態取得
	// マウスの位置を取得
	GetMousePoint(&MouseX, &MouseY);
	MouseX -= 400;
	MouseY -= 350;
}