#pragma once

#include "CPlayerUpdater.h"

class CTransform;

#define MAX_ENEMY_SPEED 5
#define LEFT 1
#define RIGHT 2

class CEnemyUpdater
{
	CTransform* transform;
	int PreKey;
	int AlphaSpeed;
public:
	CEnemyUpdater(CTransform* transform);
	~CEnemyUpdater();

	void moveRight();
	void moveLeft();

};

