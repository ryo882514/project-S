#include "DxLib.h"
#include "game.h"
#include "keyboard.h"
#define SIZE_X 1000
#define SIZE_Y 800

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); // ウィンドウモードに設定
	SetGraphMode(SIZE_X,SIZE_Y, 32); // ウィンドウサイズ指定
	SetDrawScreen(DX_SCREEN_BACK);

	// DxLib初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}
	//メインループ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0&& UpdateKey() == 0)
	{
		game_test();
	}

	DxLib_End();    // DXライブラリ終了処理
	return 0;
}