#include "DxLib.h"
#include "keyboard.h"

// �L�[�̓��͏�Ԃ��X�V����
int UpdateKey()
{
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++) 
	{
		if (tmpKey[i] != 0) // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[�����͂���Ă���Ȃ�
		{ 
			key[i]++;       // ���Z
			// �`��
		}
		else                // ������Ă��Ȃ����
		{                 
			key[i] = 0;     // 0�ɂ���
		}
	}
	return 0;
}

int Key(int KeyCode) {

	return key[KeyCode];
}