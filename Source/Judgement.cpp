#include "Judgement.h"

void Judgement()
{
	if (PlayerX +Player_Size    >= EnemyX &&
		PlayerX + 1 <= EnemyX + Enemy_Size &&
		PlayerY + Player_Size >= EnemyY  &&
		PlayerY + 1 <= EnemyY + Enemy_Size )
	{
		DrawFormatString(0, 150, GetColor(255, 255, 255), "Mouswedwqerfhgwd");
	}
	for (int i = 0; i < 13; i++)
	{

		if (bx[i] + 5 >= EnemyX - MapDrawPointX &&
			bx[i] + 1 <= EnemyX + Enemy_Size - MapDrawPointX &&
			by[i] + 5 >= EnemyY - MapDrawPointY &&
			by[i] + 1 <= EnemyY + Enemy_Size - MapDrawPointY &&
			bflag[i] == true)
		{
			Enemy_Size -= 1;
			if (Enemy_Size == 0)
			{
				Enemy_Size = -1;
			}
			DrawFormatString(0, i * 20 + 150, GetColor(255, 255, 255), "%d‚ª“–‚½‚Á‚½", i);
		}
		DrawFormatString(0, 550+i*20, GetColor(255, 255, 255), "tama%f", bx[i]);
	}
	DrawFormatString(0, 350, GetColor(255, 255, 255), "zibun%d", PlayerX - MapDrawPointX);
	DrawFormatString(0, 450, GetColor(255, 255, 255), "teki%d", EnemyX - MapDrawPointX);
}