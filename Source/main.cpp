#include "DxLib.h"
#include "game.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	int SetUse3DFlag(int Flag);
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
	SetGraphMode(700, 600, 32); // �E�B���h�E�T�C�Y�w��
	SetDrawScreen(DX_SCREEN_BACK);

	// DxLib����������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}
	//���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
	{

		game_test();
		Keyboard_Draw();
	}

	DxLib_End();    // DX���C�u�����I������
	return 0;
}