#ifndef _SCENE_H_
#define _SCENE_H_

/*---�ϐ����`����ꏊ---*/
static int Scene;

static bool Scene_InitFlg = false;  // �������t���O�p

/*---�֐����`����ꏊ---*/

void Scene_init();
void Scene_Update();
void Scene_Change();

void Scene_1();
void Scene_2();
void Scene_3();

#endif // !_SCENE_H_