// マップスクロール基本
#include "DxLib.h"

#define MAP_SIZE	64			// マップチップ一つのドットサイズ

#define MAP_WIDTH	20			// マップの幅
#define MAP_HEIGHT	16			// マップの縦長さ

// マップのデータ
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
	{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 ,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 1, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 ,  1, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
};

// プレイヤーの位置
int PlayerX, PlayerY;

// マップとプレイヤーの描画関数
void GraphDraw(void)
{
	int j, i;
	int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
	int DrawMapChipNumX, DrawMapChipNumY;	// 描画するマップチップの数

	// 描画するマップチップの数をセット
	DrawMapChipNumX = 640 / MAP_SIZE + 1;
	DrawMapChipNumY = 480 / MAP_SIZE + 1;

	// 画面左上に描画するマップ座標をセット
	MapDrawPointX = PlayerX - DrawMapChipNumX / 2;
	MapDrawPointY = PlayerY - DrawMapChipNumY / 2;

	// マップを描く
	for (i = 0; i < DrawMapChipNumY; i++)
	{
		for (j = 0; j < DrawMapChipNumX; j++)
		{
			// 画面からはみ出た位置なら描画しない
			if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_WIDTH || i + MapDrawPointY >= MAP_HEIGHT) continue;

			// マップデータが０だったら四角を描画する
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 0)
			{
				DrawBox(j * MAP_SIZE, i * MAP_SIZE,
					j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
					GetColor(255, 0, 0), TRUE);
			}
		}
	}

	// プレイヤーの描画
	DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
		(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
		GetColor(255, 255, 255), TRUE);
}

// ＷｉｎＭａｉｎ関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int Key;
	int OldX, OldY;	// 移動する前のプレイヤーの位置を保存する変数

	SetGraphMode(640, 480, 16);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	// 描画先画面を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// プレイヤーの初期位置をセット
	PlayerX = 2;
	PlayerY = 2;

	// ループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 画面を初期化
		ClearDrawScreen();

		// キー入力を得る
		Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		// 移動する前のプレイヤーの位置を保存
		OldX = PlayerX;
		OldY = PlayerY;

		// キー入力に応じてプレイヤーの座標を移動
		if (Key & PAD_INPUT_LEFT) PlayerX -= 1;
		if (Key & PAD_INPUT_RIGHT) PlayerX += 1;
		if (Key & PAD_INPUT_UP) PlayerY -= 1;
		if (Key & PAD_INPUT_DOWN) PlayerY += 1;

		// 進入不可能なマップだった場合は移動できない
		if (MapData[PlayerY][PlayerX] == 0)
		{
			PlayerX = OldX;
			PlayerY = OldY;
		}

		// マップとプレイヤーを描画
		GraphDraw();

		// 裏画面の内容を表画面に映す
		ScreenFlip();

		// ウエイト
		WaitTimer(100);
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}