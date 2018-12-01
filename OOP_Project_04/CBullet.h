#ifndef _CBULLET_H_
#define _CBULLET_H_

#include <windows.h>
#include <vector>
#include <iostream>
using namespace std;

#define BULLET_SPEED 6
#define BULLET_WIDTH 5
#define BULLET_HEIGHT 10

class CBulletBody {
	int X, Y;
	HBRUSH hBrush;
	HBRUSH hEnemyBrush;
	HPEN hPen;
	BOOL bEnemy;

	void MoveBody();
public:
	CBulletBody(int,int,BOOL);
	~CBulletBody();

	int GetX();
	int GetY();

	void Update();
	void Render(HDC);
};

class CBullet {
	vector<CBulletBody*> Body;
	int Delay;
	BOOL IsBulletOn;
	BOOL bEnemy;

	void DrawBody(HDC);
public:
	CBullet(BOOL);
	~CBullet();

	void PushBody(int PosX, int PosY, int Combo);
	void PopBody();

	BOOL GetBulletMode();

	void Update();
	void Render(HDC);

	BOOL CheckHit(int,int,int);
};

#endif