#include "DxLib.h"
#include "keyboard.h"

// keyboard.cpp内の関数を起動させます
int Keyboard_Draw()
{
	UpdateKey();
	//Draw_Input_Char();

	return 0;
}

// キーの入力状態を更新する
int UpdateKey()
{
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++) 
	{
		if (tmpKey[i] != 0) // i番のキーコードに対応するキーが入力されているなら
		{ 
			Key[i]++;       // 加算
			// 描画
			DrawFormatString(0,20, GetColor(255, 255, 255), "入力を検知中");
			//DrawFormatString(0, 40, GetColor(255, 255, 255), "%c", String[0]);
		}
		else                // 押されていなければ
		{                 
			Key[i] = 0;     // 0にする
		}
	}
	return 0;
}

//入力された文字を表示させる
int Draw_Input_Char()
{
	// 文字入力バッファから文字を取得する
	InputChar = GetInputChar(TRUE);

	// 操作コード以外の文字入力があった場合のみ表示処理を行う
	if (InputChar != 0 && InputChar >= CTRL_CODE_CMP)
	{
		// 文字の保存
		String[0] = InputChar;
		/*文字の表示はUpdateKey関数で行うようにしてます*/
	}
	return 0;
}