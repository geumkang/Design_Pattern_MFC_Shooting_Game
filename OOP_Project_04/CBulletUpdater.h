#pragma once
#include "CUpdater.h"
#define BULLET_SPEED 6

class CTransform;

class CBulletUpdater : public CUpdater
{

	bool isEnemy = false;

public:

	CTransform* transform;

	CBulletUpdater(CTransform* transform);
	~CBulletUpdater();

	void Update();
	void reverse_direction();
	bool getIsEnemy();
};


