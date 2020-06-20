#include "DxLib.h"
#include "keyboard.h"

// キーの入力状態を更新する
int UpdateKey()
{
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++) 
	{
		if (tmpKey[i] != 0) // i番のキーコードに対応するキーが入力されているなら
		{ 
			key[i]++;       // 加算
			// 描画
		}
		else                // 押されていなければ
		{                 
			key[i] = 0;     // 0にする
		}
	}
	return 0;
}

int Key(int KeyCode) {

	return key[KeyCode];
}