#ifndef _UI_H_
#define _UI_H_

#include "DxLib.h"
#include "keyboard.h"
#include "Global.h"
#include "Enemy.h"

/*---�ϐ����`����ꏊ---*/
static bool UI_InitFlg = false;
/*---�֐����`����ꏊ---*/
void UI_Init();
void UI_Update();
void UI_System();
void Text_Size64();
void Text_Size32();
void Text_Size16();
#endif // !_JUDGEMENT_H_