#ifndef _CPLAYER_H_
#define _CPLAYER_H_

#include <windows.h>
#include <vector>
#include <iostream>
#include "CEnemy_Player.h"
#include "CCombo.h"
using namespace std;
#define MAX_SPEED 5

#define UPGRADE 0
#define NON_UPGRADE 1

class CPlayer {
	HBITMAP hPlayerBit;
	int X, Y;
	const int Size;
	int AlphaSpeed;
	int PreKey;
	vector<CPlayerBody*> Body;
	CBullet *Bullet;
	BOOL BulletMode;

	void DrawPlayerBody(HDC);
	void DrawPlayer(HDC);

	void PushBody(int PosX, int PosY);
	void PopBody();

	/////////////////////////////////////////
	void Attack(CCombo*);
	void Special_Attack(CCombo*);
public:
	CPlayer(HINSTANCE);
	~CPlayer();

	void KeyUpdate(SHORT,CCombo*);
	int Update(CEnemy*, CHp*, CCombo*);
	void Render(HDC);

	BOOL CheckHit(int,int,int);
	BOOL IsBullet();

	int GetX() { return X;}
	int GetY() { return Y;}
};

#endif