#include "DxLib.h"
#include "Enemy.h"
#include"Global.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"math.h"
float deg, rad;

void Enemy_Init()
{
	EnemyX = 50;
	EnemyY = 50;
	Enemy_Size =50;
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
	if (cnt >= 2)
	{
		deg += 20;
		if (deg >= 360)deg = 0;
		rad = deg * 3.14 / 180;
		EnemyX += 25 * cos(rad);
		EnemyY += 25 * sin(rad);
		cnt = 0;
	}
}

void Enemy_Draw()
{
	// éläpÇÃï`âÊ
	if (800 >= EnemyX - MapDrawPointX && 700 >= EnemyX - MapDrawPointY)
	{
		DrawBox(EnemyX - MapDrawPointX, EnemyY - MapDrawPointY,
		    	EnemyX + Enemy_Size - MapDrawPointX + 1, EnemyY + Enemy_Size - MapDrawPointY + 1,
			    GetColor(255, 255, 255), TRUE);
	}
	DrawFormatString(220, 50, GetColor(255, 255, 255), "EnemyMAPÅF%d,%d",EnemyX,EnemyY);

}