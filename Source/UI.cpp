#include "UI.h"

void UI_Init()
{
	ChangeFont("PixelMplus10");  //フォント変更
	UI_InitFlg = true;
}

void UI_Update()
{
	if (UI_InitFlg == false)
	{
		UI_Init();
	}
	UI_System();
	Text_Size64();
	Text_Size32();
	Text_Size16();
}

void UI_System()
{
	// ゲーム画面境界線の描画
	DrawBox(0, 0, 800, 700, GetColor(255, 0, 0), FALSE);

	// 境界線の描画
	DrawBox(-1000 - MapDrawPointX, -1000 - MapDrawPointY,
		1000 - MapDrawPointX + 1, 1000 - MapDrawPointY + 1,
		GetColor(255, 0, 0), FALSE);

	//UI部分の色
	DrawBox(0, 700,
		1000, 800,
		GetColor(10, 25, 10), TRUE);
	DrawBox(800, 0,
		1000, 800,
		GetColor(10, 25, 10), TRUE);

	//四角表示
	DrawBox(20, 720,
		120+1 , 780 + 1,
		GetColor(55 ,55, 55), TRUE);
}

void Text_Size64()
{
	SetFontSize(64);
	DrawFormatString(885, 20, GetColor(255, 255, 255), "W");
	DrawFormatString(825, 90, GetColor(255, 255, 255), "A");
	DrawFormatString(885, 90, GetColor(255, 255, 255), "S");
	DrawFormatString(945, 90, GetColor(255, 255, 255), "D");
}
void Text_Size32()
{
	SetFontSize(32);

}
void Text_Size16()
{
	SetFontSize(16);
}