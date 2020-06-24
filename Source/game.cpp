#include "DxLib.h"
#include "game.h"
#include "Player.h"
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
	Player_Update();
}

void game_init()
{

}