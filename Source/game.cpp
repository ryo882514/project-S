#include "game.h"
#include "DxLib.h"
#include "keyboard.h"
#include "Judgement.h"
#include "UI.h"
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
	UI_Update();
}

void game_init()
{

}