#include "DxLib.h"
#include "game.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	int SetUse3DFlag(int Flag);
	ChangeWindowMode(TRUE); // ウィンドウモードに設定
	SetGraphMode(700, 600, 32); // ウィンドウサイズ指定
	SetDrawScreen(DX_SCREEN_BACK);

	// DxLib初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}
	//メインループ
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
	{

		game_test();
		Keyboard_Draw();
	}

	DxLib_End();    // DXライブラリ終了処理
	return 0;
}