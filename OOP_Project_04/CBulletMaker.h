#pragma once
#include "CBullet.h"
#include <Windows.h>
#include <vector>

class CTransform;

class CBulletMaker
{
public:

	int Delay;
	bool isEnemy;

	std::vector<CBullet*> bullets;

	CBulletMaker(bool isEnemy);
	~CBulletMaker();

	void Render(HDC hdc);
	void Update();
	bool CheckHit(CTransform* transform, int Size);
	void PushBody(CTransform* transform, int Combo);
	bool GetBulletMode();
};

