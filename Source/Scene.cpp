#include "Scene.h"
#include "game.h"
#include "keyboard.h"
#include "DxLib.h"
void Scene_Update()
{
	// 初期化
	if (!Scene_InitFlg)
	{
		Scene_init();
		Scene_InitFlg = true;
	}
	Scene_Change();
}

void Scene_init()
{
	Scene = 0;
}

void Scene_Change()
{
	switch (Scene)
	{
	case 0://タイトル
		DrawFormatString(0, 500, GetColor(255, 255, 255), "タイトル");
		if (Key(KEY_INPUT_RETURN) == 1)
		{
			Scene = 1;
		}
		break;
	case 1://ゲーム
		Scene_1();
		if (Key(KEY_INPUT_RETURN) == 1)
		{
			Scene = 2;
		}
		game_test();
		break;
	case 2://リザルト
		Scene_2();
		if (Key(KEY_INPUT_RETURN) == 1)
		{
			Scene = 3;
		}
		break;
	case 3://メニュー
		Scene_3();
		if (Key(KEY_INPUT_RETURN) == 1)
		{
			Scene = 1;
		}
		break;
	default:
		break;
	}
}

void Scene_1()
{
	DrawFormatString(10, 100 , GetColor(255, 255, 255), "ゲーム");
}
void Scene_2()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "リザルト");
}
void Scene_3()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "メニュー");
}