#ifndef _SCENE_H_
#define _SCENE_H_

/*---変数を定義する場所---*/
static int Scene;

static bool Scene_InitFlg = false;  // 初期化フラグ用

/*---関数を定義する場所---*/

void Scene_init();
void Scene_Update();
void Scene_Change();

void Scene_1();
void Scene_2();
void Scene_3();

#endif // !_SCENE_H_