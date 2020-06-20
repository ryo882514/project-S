// �}�b�v�X�N���[��
#include "DxLib.h"
#include "keyboard.h"
int Magnification = 8;	// ���_�̔{���@x1�`x64�܂ł�1,2,4,8,16,32,64��7�i�K
// �v���C���[�̈ʒu
int PlayerX, PlayerY;
int Player_Size = 6;
int Save_Magnification;
int scrollflg;
int MouseX, MouseY;
int MapDrawPointX, MapDrawPointY;		// �`�悷��}�b�v���W�l
int DrawMapChipNumX, DrawMapChipNumY;	// �`��T�C�Y
int Mouse;
// �}�b�v�ƃv���C���[�̕`��֐�
void GraphDraw(void)
{
	//�`�悷��}�b�v�T�C�Y
	DrawMapChipNumX = 700/ Magnification;
	DrawMapChipNumY = 600/ Magnification;

	// ��ʒ����ɍ��W���Z�b�g
	MapDrawPointX = PlayerX - (DrawMapChipNumX - Player_Size ) / 2;
	MapDrawPointY = PlayerY - (DrawMapChipNumY - Player_Size ) / 2;
		if (Key(KEY_INPUT_1)==1)
		{
			Save_Magnification = Magnification * 2;
			if (Save_Magnification > 64)Save_Magnification = 64;
			scrollflg = 1;
		}
		if (Key(KEY_INPUT_3)==1)
		{
			Save_Magnification = Magnification / 2;
			if (Save_Magnification < 1)Save_Magnification = 1;
			scrollflg = 2;
		}
		// �}�E�X�̈ʒu���擾
		GetMousePoint(&MouseX, &MouseY);
		// �Q�[����ʋ��E���̕`��
		DrawBox(0, 0, 700, 600,
			GetColor(255, 0, 0), FALSE);
	// ���E���̕`��
	DrawBox((-1000 - MapDrawPointX) * Magnification, (-1000 - MapDrawPointY) * Magnification,
			(1000 - MapDrawPointX + 1) * Magnification, (1000 - MapDrawPointY + 1) * Magnification,
			GetColor(255, 0, 0), FALSE);
	// �l�p�̕`��
	if (700 >= (50 - MapDrawPointX) * Magnification && 600 >= (50 - MapDrawPointY) * Magnification)
	{
		DrawBox((50 - MapDrawPointX) * Magnification, (50 - MapDrawPointY) * Magnification,
			(100 - MapDrawPointX + 1) * Magnification, (100 - MapDrawPointY + 1) * Magnification,
			GetColor(255, 255, 255), TRUE);
	}

	DrawFormatString(400, 200, GetColor(255, 255, 255), "%d%d", (50 - MapDrawPointX) * Magnification, (50 - MapDrawPointY)* Magnification);
	// �v���C���[�̕`��
	DrawBox((PlayerX - MapDrawPointX)* Magnification, (PlayerY - MapDrawPointY)* Magnification,
		    (PlayerX+ Player_Size - MapDrawPointX + 1)*Magnification, (PlayerY+ Player_Size - MapDrawPointY + 1)*Magnification,
		GetColor(0, 255, 0), TRUE);
	DrawFormatString(0, 400, GetColor(255, 255, 255), "MAP:%d,%d", MapDrawPointX, MapDrawPointY);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "%d,%d", PlayerX, PlayerY);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "%d", Magnification);
}

void zoom()
{
	switch (scrollflg)
	{
	case 1:
		while (Save_Magnification > Magnification)
		{
			Magnification++;
		}
		break;
	case 2:
		while (Save_Magnification < Magnification)
		{
			Magnification--;
		}
		break;
	default:
		break;
	}
}

// �v�����l�������֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
	SetGraphMode(800, 700, 16);
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	// �`����ʂ𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �v���C���[�̏����ʒu���Z�b�g
	PlayerX = 2;
	PlayerY = 2;

	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�̏�ԍX�V)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0&& UpdateKey()==0) {
		Mouse = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
		// �L�[���͂ɉ����ăv���C���[�̍��W���ړ�
		if (Key(KEY_INPUT_LEFT) <= 1)PlayerX += 1;
		if (Key(KEY_INPUT_RIGHT) <= 1) PlayerX -= 1;
		if (Key(KEY_INPUT_UP) <= 1) PlayerY += 1;
		if (Key(KEY_INPUT_DOWN) <= 1) PlayerY -= 1;
		// �}�E�X��ǂ�������悤�Ɉړ�
		if(Mouse&&MOUSE_INPUT_LEFT)
		{ 
			DrawFormatString(0, 500, GetColor(255, 255, 255), "%d,%d", MouseX, MouseY);
			if (MouseX >= 350 - Player_Size * Magnification / 2) PlayerX += 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "�E");
			if (MouseX <= 350 + Player_Size * Magnification / 2) PlayerX -= 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "��");
			if (MouseY >= 300 - Player_Size * Magnification / 2) PlayerY += 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "��");
			if (MouseY <= 300 + Player_Size * Magnification / 2) PlayerY -= 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "��");
		}


			// �}�b�v�ƃv���C���[��`��
			GraphDraw();
			zoom();
			WaitTimer(10);
			// ����ʂ̓��e��\��ʂɉf��
			ScreenFlip();
	}

		DxLib_End();				// �c�w���C�u�����g�p�̏I������

		return 0;					// �\�t�g�̏I��
}