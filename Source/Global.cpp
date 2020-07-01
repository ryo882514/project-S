#include "DxLib.h"
#include "keyboard.h"
#include"Global.h"
/*他のソースでもこの変数が使いたい！ってやつはここに定義してね*/
/*(やり方はとしてはあまりよろしくないけど)--------------------*/
//マウス
int Mouse;
int MouseX, MouseY;
//画面表示サイズ
int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
int DrawMapChipNumX, DrawMapChipNumY;	// 描画サイズ
//プレイヤー
float PlayerX, PlayerY;
int Player_Size;
//弾
float bx[13], by[13];
bool bflag[13];
//敵
float EnemyX[100], EnemyY[100];
int Enemy_Size[100];
int E_HP[100];
bool E_Flg[100];
bool Rest_E_Flg[100];
int Rest_E;
/*-ここまで----------------------------------------------------*/
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