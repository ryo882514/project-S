#include "DxLib.h"
#include "game.h"

#define SIZE_X 700
#define SIZE_Y 600

void game_test() 
{
	// ������
	if (!flg)
	{
		game_init();
		flg = true;
	}

	// �~��`��
	DrawOval(x-320, y, r, r, RGB(11, 45, 14), TRUE);

	// �ȉ~��`��
	DrawOval(ex, ey, er, er, RGB(36, 43, 64), TRUE);

	if (CheckHitKey(KEY_INPUT_W))
	{
		// W�L�[��������Ă���
		y-=3;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		// A�L�[��������Ă���
		x-=3;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		// S�L�[��������Ă���
		y+=3;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		// D�L�[��������Ă���
		x+=3;
	}

	if ((x - ex) * (x - ex) + (y - ey) * (y - ey) <= (r + er) * (r + er)) 
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "���m��");
	}
	DrawFormatString(0, 300, GetColor(255, 255, 255), "%d%d",x,y);
}

void game_init()
{
	x = SIZE_X/2;
	y = SIZE_Y/2;
	r = 50;

	ex = 200;
	ey = 200;
	er = 100;
}