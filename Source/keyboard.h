#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

/*---�ϐ����`����ꏊ---*/
static int key[256];
static char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����

/*---�֐����`����ꏊ---*/
 int UpdateKey();
 int Key(int KeyCode);
#endif // !_KEYBORAD_H_
