
#include "DxLib.h"
#include "keyboard.h"
#include"Global.h"
int Mouse;
int MouseX, MouseY;
int MapDrawPointX, MapDrawPointY;		// �`�悷��}�b�v���W�l
int DrawMapChipNumX, DrawMapChipNumY;	// �`��T�C�Y

float PlayerX, PlayerY;
int Player_Size;
float bx[13], by[13];
bool bflag[13];
int EnemyX, EnemyY;
int Enemy_Size;

void Global_Update()
{
	//�`�悷��}�b�v�T�C�Y
	DrawMapChipNumX = 800;
	DrawMapChipNumY = 700;

	// ��ʒ����ɍ��W���Z�b�g
	MapDrawPointX = PlayerX - (DrawMapChipNumX - Player_Size) / 2;
	MapDrawPointY = PlayerY - (DrawMapChipNumY - Player_Size) / 2;

	Mouse = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	// �}�E�X�̈ʒu���擾
	GetMousePoint(&MouseX, &MouseY);
	MouseX -= 400;
	MouseY -= 350;
}