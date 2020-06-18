#include "DxLib.h"
#include "game.h"
void game_test() 
{
	// 初期化
	if (!flg)
	{
		game_init();
		flg = true;
	}

	// 円を描画
	DrawOval(x, y, r, r, RGB(11, 45, 14), TRUE);

	// 楕円を描画
	DrawOval(ex, ey, er, er, RGB(36, 43, 64), TRUE);

	if (CheckHitKey(KEY_INPUT_W))
	{
		// Wキーが押されている
		y-=3;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		// Aキーが押されている
		x-=3;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		// Sキーが押されている
		y+=3;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		// Dキーが押されている
		x+=3;
	}

	if ((x - ex) * (x - ex) + (y - ey) * (y - ey) <= (r + er) * (r + er)) 
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "検知中");
	}

}

void game_init()
{
	x = 0;
	y = 0;
	r = 50;

	ex = 200;
	ey = 200;
	er = 100;
}