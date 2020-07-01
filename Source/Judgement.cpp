#include "Judgement.h"

void Judgement()
{

	for (int i = 0; i < 100; i++)
	{
		if (PlayerX + Player_Size >= EnemyX[i] &&
			PlayerX + 1 <= EnemyX[i] + Enemy_Size[i] &&
			PlayerY + Player_Size >= EnemyY[i] &&
			PlayerY + 1 <= EnemyY[i] + Enemy_Size[i])
		{
			DrawFormatString(0, 150, GetColor(255, 255, 255), "Mouswedwqerfhgwd");
		}
		for (int j = 0; j < 13; j++)
		{

			if (bx[j] + 5 >= EnemyX[i] - MapDrawPointX &&
				bx[j] + 1 <= EnemyX[i] + Enemy_Size[i] - MapDrawPointX &&
				by[j] + 5 >= EnemyY[i] - MapDrawPointY &&
				by[j] + 1 <= EnemyY[i] + Enemy_Size[i] - MapDrawPointY &&
				bflag[j] == true && E_Flg[i] == true)
			{
				Enemy_Size[i] -= 10;
				bflag[j] = false;
				if (Enemy_Size[i] <= 0 )
				{
					E_Flg[i] = false;
					Enemy_Size[i] = -1;
				}
				DrawFormatString(0, j * 20 + 150, GetColor(255, 255, 255), "%d‚ª“–‚½‚Á‚½", j);
			}
			if (Rest_E_Flg[i] == true && Enemy_Size[i] <= 0)
			{
				Rest_E_Flg[i] = false;
				Rest_E -= 1;
			}
		}
	}
}