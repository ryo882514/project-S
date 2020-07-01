#include"Player.h"
#include"math.h"
#include"Global.h"
void Player_Init()
{
	Player_Size = 6;
	PlayerX = 0;
	PlayerY = 0;
	for (int i = 0; i < 13; i++)
	{
		bx[i] = 0;
		by[i] = 0;
		vx[i] = 0;
		vy[i] = 0;
		bflag[i] = false;
	}
	s = 5;
	limit = 0;
}

void Player_Update()
{
	if (Player_Initflg == false)
	{
		Player_Init();
		Player_Initflg = true;
	}
	Bullet();
	GraphDraw();
	UpdateKey();
}

void Bullet()
{
	limit++;
	for (int i = 0; i < 13; i++)
	{
		if (bflag[i])
		{
			bx[i] = bx[i] + vx[i] * s;
			by[i] = by[i] + vy[i] * s;
			if (bx[i]< 5 || bx[i]>795 || by[i] < 5 || by[i]>695)
			{
				bflag[i] = false;
			}
		}
	}
	if (Key(KEY_INPUT_2) >= 1&&limit>=8)
	{
		for (int i = 0; i < 13; i++)
		{
			if (!bflag[i])
			{
				float theta;
				theta = atan2(MouseY, MouseX);
				vx[i] = cos(theta);
				vy[i] = sin(theta);
				bx[i] = PlayerX - MapDrawPointX;
				by[i] = PlayerY - MapDrawPointY;
				bflag[i] = true;
				limit = 0;
				break;
			}
		}
	}

	for (int i = 0; i < 13; i++)
	{
		if (bflag[i])
		{
		// 弾の描画
		DrawBox(bx[i], by[i],bx[i] + 5 + 1, by[i] + 5 + 1,GetColor(0, 255, 0), TRUE);

		DrawFormatString(0, 500+i*10, GetColor(255, 255, 255), "弾の座標:%f,%f", bx[i], by[i]);

		}
	}
}

void GraphDraw()
{
    // キー入力に応じてプレイヤーの座標を移動
	if (Key(KEY_INPUT_A) <= 1) PlayerX += 1;
	if (Key(KEY_INPUT_D) <= 1) PlayerX -= 1;
	if (Key(KEY_INPUT_W) <= 1) PlayerY += 1;
	if (Key(KEY_INPUT_S) <= 1) PlayerY -= 1;
	// マウスを追いかけるように移動
	if (Mouse && MOUSE_INPUT_LEFT)
	{
		if (MouseX+400 >= 400 - Player_Size) PlayerX += 1;
		if (MouseX+400 <= 400 + Player_Size) PlayerX -= 1;
		if (MouseY+350 >= 350 - Player_Size) PlayerY += 1;
		if (MouseY+350 <= 350 + Player_Size) PlayerY -= 1;
	}

	// プレイヤーの描画
	DrawBox(PlayerX - MapDrawPointX, PlayerY - MapDrawPointY,
		    PlayerX + Player_Size - MapDrawPointX + 1,PlayerY + Player_Size - MapDrawPointY + 1,
		    GetColor(0, 255, 0), TRUE);
}