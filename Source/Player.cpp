#include"Player.h"
#include"math.h"
void Player_Init()
{
	Magnification = 8;	// ���_�̔{���@x1�`x64�܂ł�1,2,4,8,16,32,64��7�i�K
	Player_Size = 6;
	PlayerX = 0;
	PlayerY = 0;
	for (int i = 0; i < 13; i++)
	{
		bx[i] = 0;
		by[i] = 0;
		vx[i] = 0;
		vy[i] = 0;
		bflag[i] = false;
	}
	s = 5;
	limit = 0;
}
void Player_Update()
{
	Bullet();
	GraphDraw();
	UpdateKey();
	zoom();
}

void Bullet()
{
	limit++;
	for (int i = 0; i < 13; i++)
	{
		if (bflag[i])
		{
			bx[i] = bx[i] + vx[i] * s;
			by[i] = by[i] + vy[i] * s;
			if (bx[i]< 0 || bx[i]>700 || by[i] < 0 || by[i]>600)
			{
				bflag[i] = false;
			}
		}
	}
	if (Key(KEY_INPUT_2) >= 1&&limit>=13)
	{
		for (int i = 0; i < 13; i++)
		{
			if (!bflag[i])
			{
				float theta;
				theta = atan2(MouseY, MouseX);
				vx[i] = cos(theta);
				vy[i] = sin(theta);
				bx[i] = (DrawMapChipNumX / 2);
				by[i] = (DrawMapChipNumY / 2);
				bflag[i] = true;
				limit = 0;
				break;
			}
		}
	}

	for (int i = 0; i < 13; i++)
	{
		if (bflag[i])
		{
		// �v���C���[�̕`��
		DrawBox((bx[i]) * Magnification, (by[i]) * Magnification,
			(bx[i] + 5 + 1) * Magnification, (by[i] + 5 + 1) * Magnification,
			GetColor(0, 255, 0), TRUE);
		DrawFormatString(0, 500, GetColor(255, 255, 255), "%f,%f", bx[i], by[i]);
		}
	}
}

void GraphDraw()
{

	Mouse = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	if (Player_Initflg == false)
	{
		Player_Init();
		Player_Initflg = true;
	}
	if (Key(KEY_INPUT_1) == 1)
	{
		Save_Magnification = Magnification * 2;
		if (Save_Magnification > 64)Save_Magnification = 64;
		scrollflg = 1;
	}
	if (Key(KEY_INPUT_3) == 1)
	{
		Save_Magnification = Magnification / 2;
		if (Save_Magnification < 1)Save_Magnification = 1;
		scrollflg = 2;
	}
// �L�[���͂ɉ����ăv���C���[�̍��W���ړ�
	if (Key(KEY_INPUT_LEFT) <= 1)PlayerX += 1;
	if (Key(KEY_INPUT_RIGHT) <= 1) PlayerX -= 1;
	if (Key(KEY_INPUT_UP) <= 1) PlayerY += 1;
	if (Key(KEY_INPUT_DOWN) <= 1) PlayerY -= 1;
	// �}�E�X��ǂ�������悤�Ɉړ�
	if (Mouse && MOUSE_INPUT_LEFT)
	{
		if (MouseX+350 >= 350 - Player_Size * Magnification / 2) PlayerX += 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "�E");
		if (MouseX+350 <= 350 + Player_Size * Magnification / 2) PlayerX -= 1, DrawFormatString(0, 525, GetColor(255, 255, 255), "��");
		if (MouseY+300 >= 300 - Player_Size * Magnification / 2) PlayerY += 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "��");
		if (MouseY+300 <= 300 + Player_Size * Magnification / 2) PlayerY -= 1, DrawFormatString(0, 550, GetColor(255, 255, 255), "��");
	}

	//�`�悷��}�b�v�T�C�Y
	DrawMapChipNumX = 700 / Magnification;
	DrawMapChipNumY = 600 / Magnification;

	// ��ʒ����ɍ��W���Z�b�g
	MapDrawPointX = PlayerX - (DrawMapChipNumX - Player_Size) / 2;
	MapDrawPointY = PlayerY - (DrawMapChipNumY - Player_Size) / 2;

	// �}�E�X�̈ʒu���擾
	GetMousePoint(&MouseX, &MouseY);
	MouseX -=350 ;
	MouseY -=300 ;
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

	DrawFormatString(400, 200, GetColor(255, 255, 255), "%d%d", (50 - MapDrawPointX) * Magnification, (50 - MapDrawPointY) * Magnification);
	// �v���C���[�̕`��
	DrawBox((PlayerX - MapDrawPointX) * Magnification, (PlayerY - MapDrawPointY) * Magnification,
		(PlayerX + Player_Size - MapDrawPointX + 1) * Magnification, (PlayerY + Player_Size - MapDrawPointY + 1) * Magnification,
		GetColor(0, 255, 0), TRUE);
	DrawFormatString(0, 400, GetColor(255, 255, 255), "MAP:%d,%d", MapDrawPointX, MapDrawPointY);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "Player:%d,%d", PlayerX, PlayerY);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "%d", Magnification);
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Mouse:%d,%d", MouseX, MouseY);
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
