#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

/*---変数を定義する場所---*/
static int Key[256];
static char String[2];
static char InputChar;

/*---関数を定義する場所---*/
 int Keyboard_Draw();
 int UpdateKey();
 int Draw_Input_Char();

#endif // !_KEYBORAD_H_
