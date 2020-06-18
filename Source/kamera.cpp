// �}�b�v�X�N���[����{
#include "DxLib.h"

#define MAP_SIZE	64			// �}�b�v�`�b�v��̃h�b�g�T�C�Y

#define MAP_WIDTH	20			// �}�b�v�̕�
#define MAP_HEIGHT	16			// �}�b�v�̏c����

// �}�b�v�̃f�[�^
int MapData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } ,
	{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 ,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 ,  1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 0, 0, 0, 1, 0, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 1, 1, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 ,  0, 0, 1, 0, 0, 1, 1, 0, 1, 0 } ,

	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 0, 0, 1, 1, 0, 0, 1, 0, 0 ,  0, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 ,  1, 1, 1, 0, 0, 1, 1, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } ,
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } ,
};

// �v���C���[�̈ʒu
int PlayerX, PlayerY;

// �}�b�v�ƃv���C���[�̕`��֐�
void GraphDraw(void)
{
	int j, i;
	int MapDrawPointX, MapDrawPointY;		// �`�悷��}�b�v���W�l
	int DrawMapChipNumX, DrawMapChipNumY;	// �`�悷��}�b�v�`�b�v�̐�

	// �`�悷��}�b�v�`�b�v�̐����Z�b�g
	DrawMapChipNumX = 640 / MAP_SIZE + 1;
	DrawMapChipNumY = 480 / MAP_SIZE + 1;

	// ��ʍ���ɕ`�悷��}�b�v���W���Z�b�g
	MapDrawPointX = PlayerX - DrawMapChipNumX / 2;
	MapDrawPointY = PlayerY - DrawMapChipNumY / 2;

	// �}�b�v��`��
	for (i = 0; i < DrawMapChipNumY; i++)
	{
		for (j = 0; j < DrawMapChipNumX; j++)
		{
			// ��ʂ���͂ݏo���ʒu�Ȃ�`�悵�Ȃ�
			if (j + MapDrawPointX < 0 || i + MapDrawPointY < 0 ||
				j + MapDrawPointX >= MAP_WIDTH || i + MapDrawPointY >= MAP_HEIGHT) continue;

			// �}�b�v�f�[�^���O��������l�p��`�悷��
			if (MapData[i + MapDrawPointY][j + MapDrawPointX] == 0)
			{
				DrawBox(j * MAP_SIZE, i * MAP_SIZE,
					j * MAP_SIZE + MAP_SIZE, i * MAP_SIZE + MAP_SIZE,
					GetColor(255, 0, 0), TRUE);
			}
		}
	}

	// �v���C���[�̕`��
	DrawBox((PlayerX - MapDrawPointX) * MAP_SIZE, (PlayerY - MapDrawPointY) * MAP_SIZE,
		(PlayerX - MapDrawPointX + 1) * MAP_SIZE, (PlayerY - MapDrawPointY + 1) * MAP_SIZE,
		GetColor(255, 255, 255), TRUE);
}

// �v�����l�������֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int Key;
	int OldX, OldY;	// �ړ�����O�̃v���C���[�̈ʒu��ۑ�����ϐ�

	SetGraphMode(640, 480, 16);
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	// �`����ʂ𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �v���C���[�̏����ʒu���Z�b�g
	PlayerX = 2;
	PlayerY = 2;

	// ���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ��ʂ�������
		ClearDrawScreen();

		// �L�[���͂𓾂�
		Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		// �ړ�����O�̃v���C���[�̈ʒu��ۑ�
		OldX = PlayerX;
		OldY = PlayerY;

		// �L�[���͂ɉ����ăv���C���[�̍��W���ړ�
		if (Key & PAD_INPUT_LEFT) PlayerX -= 1;
		if (Key & PAD_INPUT_RIGHT) PlayerX += 1;
		if (Key & PAD_INPUT_UP) PlayerY -= 1;
		if (Key & PAD_INPUT_DOWN) PlayerY += 1;

		// �i���s�\�ȃ}�b�v�������ꍇ�͈ړ��ł��Ȃ�
		if (MapData[PlayerY][PlayerX] == 0)
		{
			PlayerX = OldX;
			PlayerY = OldY;
		}

		// �}�b�v�ƃv���C���[��`��
		GraphDraw();

		// ����ʂ̓��e��\��ʂɉf��
		ScreenFlip();

		// �E�G�C�g
		WaitTimer(100);
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}