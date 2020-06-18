#include "DxLib.h"
#include "game.h"
void game_test() 
{
	// ������
	if (!flg)
	{
		game_init();
		flg = true;
	}

	// �~��`��
	DrawOval(x, y, r, r, RGB(11, 45, 14), TRUE);

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