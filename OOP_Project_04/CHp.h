#ifndef _CHP_H_
#define _CHP_H_

#include <windows.h>

#define CHP_NORMAL 1
#define CHP_DANGER 2

#define CHP_PLAYER 1
#define CHP_ENEMY  2

class CHp {
	const int MaxHp;
	const int User;
	int Hp;
	int Mode;

	HBRUSH NormalBrush, DangerBrush;
	HBRUSH BlankBrush;
	HPEN NullPen;
	int X, Y;

public:
	CHp(int,int,int);
	~CHp();

	int GetMaxHp();
	int GetHp();
	void SetHp(int Hp);
	void MovHp(int Hp);
	void SetMode(int Mode);

	void Update();
	void Render(HDC);
};

#endif