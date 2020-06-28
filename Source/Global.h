#ifndef _GLOBAL_H_
#define _GLOBAL_H_

/*---変数を定義する場所---*/

extern int Mouse;
extern int MouseX, MouseY;
extern int MapDrawPointX, MapDrawPointY;		// 描画するマップ座標値
extern int DrawMapChipNumX, DrawMapChipNumY;	// 描画サイズ

/*---関数を定義する場所---*/

void Global_Update();

#endif // !_GLOBAL_H_