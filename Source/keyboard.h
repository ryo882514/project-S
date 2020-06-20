#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

/*---変数を定義する場所---*/
static int key[256];
static char tmpKey[256]; // 現在のキーの入力状態を格納する

/*---関数を定義する場所---*/
 int UpdateKey();
 int Key(int KeyCode);
#endif // !_KEYBORAD_H_
