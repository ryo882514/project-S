#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

/*---�ϐ����`����ꏊ---*/
static int Key[256];
static char String[2];
static char InputChar;

/*---�֐����`����ꏊ---*/
 int Keyboard_Draw();
 int UpdateKey();
 int Draw_Input_Char();

#endif // !_KEYBORAD_H_
