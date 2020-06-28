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
		// ’e‚Ì•`‰æ
		DrawBox(bx[i], by[i],bx[i] + 5 + 1, by[i] + 5 + 1,GetColor(0, 255, 0), TRUE);

		DrawFormatString(0, 500+i*10, GetColor(255, 255, 255), "’e‚ÌÀ•W:%f,%f", bx[i], by[i]);

		}
	}
}

void GraphDraw()
{
    // ƒL[“ü—Í‚É‰ž‚¶‚ÄƒvƒŒƒCƒ„[‚ÌÀ•W‚ðˆÚ“®
	if (Key(KEY_INPUT_A) <= 1)PlayerX += 1;
	if (Key(KEY_INPUT_D) <= 1) PlayerX -= 1;
	if (Key(KEY_INPUT_W) <= 1) PlayerY += 1;
	if (Key(KEY_INPUT_S) <= 1) PlayerY -= 1;
	// ƒ}ƒEƒX‚ð’Ç‚¢‚©‚¯‚é‚æ‚¤‚ÉˆÚ“®
	if (Mouse && MOUSE_INPUT_LEFT)
	{
		if (MouseX+400 >= 400 - Player_Size) PlayerX += 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "‰E");
		if (MouseX+400 <= 400 + Player_Size) PlayerX -= 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "¶");
		if (MouseY+350 >= 350 - Player_Size) PlayerY += 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "‰º");
		if (MouseY+350 <= 350 + Player_Size) PlayerY -= 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "ã");
	}

	// ƒQ[ƒ€‰æ–Ê‹«ŠEü‚Ì•`‰æ
	DrawBox(0, 0, 800, 700,GetColor(255, 0, 0), FALSE);

	// ‹«ŠEü‚Ì•`‰æ
	DrawBox(-1000 - MapDrawPointX, -1000 - MapDrawPointY,
		     1000 - MapDrawPointX + 1, 1000 - MapDrawPointY + 1,
		     GetColor(255, 0, 0), FALSE);
	
	// ƒvƒŒƒCƒ„[‚Ì•`‰æ
	DrawBox(PlayerX - MapDrawPointX, PlayerY - MapDrawPointY,
		    PlayerX + Player_Size - MapDrawPointX + 1,PlayerY + Player_Size - MapDrawPointY + 1,
		    GetColor(0, 255, 0), TRUE);

	DrawFormatString(0, 400, GetColor(255, 255, 255), "PlayerMAP:%d,%d", MapDrawPointX, MapDrawPointY);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "Player:%d,%d", PlayerX, PlayerY);
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Mouse:%d,%d", MouseX, MouseY);
}