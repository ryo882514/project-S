#include "DxLib.h"
#include "keyboard.h"

// keyboard.cpp���̊֐����N�������܂�
int Keyboard_Draw()
{
	UpdateKey();
	//Draw_Input_Char();

	return 0;
}

// �L�[�̓��͏�Ԃ��X�V����
int UpdateKey()
{
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++) 
	{
		if (tmpKey[i] != 0) // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[�����͂���Ă���Ȃ�
		{ 
			Key[i]++;       // ���Z
			// �`��
			DrawFormatString(0,20, GetColor(255, 255, 255), "���͂����m��");
			//DrawFormatString(0, 40, GetColor(255, 255, 255), "%c", String[0]);
		}
		else                // ������Ă��Ȃ����
		{                 
			Key[i] = 0;     // 0�ɂ���
		}
	}
	return 0;
}

//���͂��ꂽ������\��������
int Draw_Input_Char()
{
	// �������̓o�b�t�@���當�����擾����
	InputChar = GetInputChar(TRUE);

	// ����R�[�h�ȊO�̕������͂��������ꍇ�̂ݕ\���������s��
	if (InputChar != 0 && InputChar >= CTRL_CODE_CMP)
	{
		// �����̕ۑ�
		String[0] = InputChar;
		/*�����̕\����UpdateKey�֐��ōs���悤�ɂ��Ă܂�*/
	}
	return 0;
}