#include "Enemy.h"
#include"Player.h"
#include"Global.h"
#include"math.h"
float deg, rad;

void Enemy_Init()
{
	for (int i = 0; i < 100; i++)
	{
		EnemyX[i] = GetRand(1800)-900;
		EnemyY[i] = GetRand(1800)-900;
		Enemy_Size[i] = GetRand(50)+10;
		E_HP[i]= Enemy_Size[i]/10;
		E_Flg[i] = true;
		Rest_E_Flg[i] = true;
	}
	Rest_E = 100;
	cnt = 0;
	rad = 0;
}

void Enemy_Update()
{
	if (EnemyInitFlg == false)
	{
		Enemy_Init();
		EnemyInitFlg = true;
	}

	Enemy_Move();
	Enemy_Draw();

}

void Enemy_Move()
{
	cnt++;
	/*if (cnt >= 1)
	{
		deg += 15;
		if (deg >= 360)deg = 0;
		rad = deg * 3.14 / 180;
		for (int i = 0; i < 100; i++)
		{
			EnemyX[i] += 10 * cos(rad);
			EnemyY[i] += 10 * sin(rad);
		}
		cnt = 0;
	}*/
}

void Enemy_Draw()
{
	for (int i = 0; i < 100; i++)
	{
		E_HP[i] = Enemy_Size[i] / 10;
		// ŽlŠp‚Ì•`‰æ
		if (PlayerX - MapDrawPointX - 450 <= EnemyX[i] - MapDrawPointX &&
			PlayerX - MapDrawPointX + 405 >= EnemyX[i] - MapDrawPointX &&
			PlayerY - MapDrawPointY - 400 <= EnemyY[i] - MapDrawPointY &&
			PlayerY - MapDrawPointY + 355 >= EnemyY[i] - MapDrawPointY &&
			E_Flg[i] == true )
		{
			DrawBox(EnemyX[i] - MapDrawPointX, EnemyY[i] - MapDrawPointY,
				EnemyX[i] + Enemy_Size[i] - MapDrawPointX + 1, EnemyY[i] + Enemy_Size[i] - MapDrawPointY + 1,
				GetColor(255, 255, 255), TRUE);
		}

	}

}