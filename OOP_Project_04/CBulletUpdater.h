#pragma once

#define BULLET_SPEED 6

class CTransform;

class CBulletUpdater
{

	bool isEnemy = false;

public:

	CTransform* transform;

	CBulletUpdater(CTransform* transform);
	~CBulletUpdater();

	void update();
	void reverse_direction();
};


