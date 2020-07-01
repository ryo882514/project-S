#ifndef _UI_H_
#define _UI_H_

#include "DxLib.h"
#include "keyboard.h"
#include "Global.h"
#include "Enemy.h"

/*---変数を定義する場所---*/
static bool UI_InitFlg = false;
/*---関数を定義する場所---*/
void UI_Init();
void UI_Update();
void UI_System();
void Text_Size64();
void Text_Size32();
void Text_Size16();
#endif // !_JUDGEMENT_H_