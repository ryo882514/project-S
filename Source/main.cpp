#include "DxLib.h"
#include "game.h"
#include "keyboard.h"
#include "Scene.h"
#define SIZE_X 1000
#define SIZE_Y 800

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
	SetGraphMode(SIZE_X,SIZE_Y, 32); // �E�B���h�E�T�C�Y�w��
	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	// ����ʂ̓��e��\��ʂɔ��f������
	ScreenFlip();
	// DxLib����������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}
	//���C�����[�v
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0&& UpdateKey() == 0)
	{
		Scene_Update();
		SetDrawScreen(DX_SCREEN_BACK);
		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}

	DxLib_End();    // DX���C�u�����I������
	return 0;
}