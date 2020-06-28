#include "game.h"
#include "DxLib.h"
#include "keyboard.h"
#include "Judgement.h"

#define SIZE_X 700
#define SIZE_Y 600

void game_test() 
{
	// ‰Šú‰»
	if (!flg)
	{
		game_init();
		flg = true;
	}
	Global_Update();
	Player_Update();
	Enemy_Update();
	Judgement();
	DrawBox(0, 700,
		1000, 800,
		GetColor(10, 25, 10), TRUE);
}

void game_init()
{

}