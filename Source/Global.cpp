#include "DxLib.h"
#include "keyboard.h"
#include"Global.h"
/*���̃\�[�X�ł����̕ϐ����g�������I���Ă�͂����ɒ�`���Ă�*/
/*(�����͂Ƃ��Ă͂��܂��낵���Ȃ�����)--------------------*/
//�}�E�X
int Mouse;
int MouseX, MouseY;
//��ʕ\���T�C�Y
int MapDrawPointX, MapDrawPointY;		// �`�悷��}�b�v���W�l
int DrawMapChipNumX, DrawMapChipNumY;	// �`��T�C�Y
//�v���C���[
float PlayerX, PlayerY;
int Player_Size;
//�e
float bx[13], by[13];
bool bflag[13];
//�G
float EnemyX[100], EnemyY[100];
int Enemy_Size[100];
int E_HP[100];
bool E_Flg[100];
bool Rest_E_Flg[100];
int Rest_E;
/*-�����܂�----------------------------------------------------*/
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