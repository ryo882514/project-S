// マップスクロール
#include "DxLib.h"
#include "keyboard.h"
int Magnification = 8;	// 視点の倍率　x1～x64までの1,2,4,8,16,32,64の7段階
// プレイヤーの位置
int PlayerX, PlayerY;
int Player_Size = 6;
int Save_Magnification;
int scrollflg;
int MouseX, MouseY;
int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
int DrawMapChipNumX, DrawMapChipNumY;	// 描画サイズ
int Mouse;
// マップとプレイヤーの描画関数
void GraphDraw(void)
{
	//描画するマップサイズ
	DrawMapChipNumX = 700/ Magnification;
	DrawMapChipNumY = 600/ Magnification;

	// 画面中央に座標をセット
	MapDrawPointX = PlayerX - (DrawMapChipNumX - Player_Size ) / 2;
	MapDrawPointY = PlayerY - (DrawMapChipNumY - Player_Size ) / 2;
		if (Key(KEY_INPUT_1)==1)
		{
			Save_Magnification = Magnification * 2;
			if (Save_Magnification > 64)Save_Magnification = 64;
			scrollflg = 1;
		}
		if (Key(KEY_INPUT_3)==1)
		{
			Save_Magnification = Magnification / 2;
			if (Save_Magnification < 1)Save_Magnification = 1;
			scrollflg = 2;
		}
		// マウスの位置を取得
		GetMousePoint(&MouseX, &MouseY);
		// ゲーム画面境界線の描画
		DrawBox(0, 0, 700, 600,
			GetColor(255, 0, 0), FALSE);
	// 境界線の描画
	DrawBox((-1000 - MapDrawPointX) * Magnification, (-1000 - MapDrawPointY) * Magnification,
			(1000 - MapDrawPointX + 1) * Magnification, (1000 - MapDrawPointY + 1) * Magnification,
			GetColor(255, 0, 0), FALSE);
	// 四角の描画
	if (700 >= (50 - MapDrawPointX) * Magnification && 600 >= (50 - MapDrawPointY) * Magnification)
	{
		DrawBox((50 - MapDrawPointX) * Magnification, (50 - MapDrawPointY) * Magnification,
			(100 - MapDrawPointX + 1) * Magnification, (100 - MapDrawPointY + 1) * Magnification,
			GetColor(255, 255, 255), TRUE);
	}

	DrawFormatString(400, 200, GetColor(255, 255, 255), "%d%d", (50 - MapDrawPointX) * Magnification, (50 - MapDrawPointY)* Magnification);
	// プレイヤーの描画
	DrawBox((PlayerX - MapDrawPointX)* Magnification, (PlayerY - MapDrawPointY)* Magnification,
		    (PlayerX+ Player_Size - MapDrawPointX + 1)*Magnification, (PlayerY+ Player_Size - MapDrawPointY + 1)*Magnification,
		GetColor(0, 255, 0), TRUE);
	DrawFormatString(0, 400, GetColor(255, 255, 255), "MAP:%d,%d", MapDrawPointX, MapDrawPointY);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "%d,%d", PlayerX, PlayerY);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "%d", Magnification);
}

void zoom()
{
	switch (scrollflg)
	{
	case 1:
		while (Save_Magnification > Magnification)
		{
			Magnification++;
		}
		break;
	case 2:
		while (Save_Magnification < Magnification)
		{
			Magnification--;
		}
		break;
	default:
		break;
	}
}

// ＷｉｎＭａｉｎ関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウィンドウモードに設定
	SetGraphMode(800, 700, 16);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	// 描画先画面を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// プレイヤーの初期位置をセット
	PlayerX = 2;
	PlayerY = 2;

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キーの状態更新)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0&& UpdateKey()==0) {
		Mouse = GetMouseInput();                //マウスの入力状態取得
		// キー入力に応じてプレイヤーの座標を移動
		if (Key(KEY_INPUT_LEFT) <= 1)PlayerX += 1;
		if (Key(KEY_INPUT_RIGHT) <= 1) PlayerX -= 1;
		if (Key(KEY_INPUT_UP) <= 1) PlayerY += 1;
		if (Key(KEY_INPUT_DOWN) <= 1) PlayerY -= 1;
		// マウスを追いかけるように移動
		if(Mouse&&MOUSE_INPUT_LEFT)
		{ 
			DrawFormatString(0, 500, GetColor(255, 255, 255), "%d,%d", MouseX, MouseY);
			if (MouseX >= 350 - Player_Size * Magnification / 2) PlayerX += 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "右");
			if (MouseX <= 350 + Player_Size * Magnification / 2) PlayerX -= 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "左");
			if (MouseY >= 300 - Player_Size * Magnification / 2) PlayerY += 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "下");
			if (MouseY <= 300 + Player_Size * Magnification / 2) PlayerY -= 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "上");
		}


			// マップとプレイヤーを描画
			GraphDraw();
			zoom();
			WaitTimer(10);
			// 裏画面の内容を表画面に映す
			ScreenFlip();
	}

		DxLib_End();				// ＤＸライブラリ使用の終了処理

		return 0;					// ソフトの終了
}