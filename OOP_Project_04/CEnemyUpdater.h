#pragma once
#include "CUpdater.h"
#include "CPlayerUpdater.h"

class CTransform;

#define MAX_ENEMY_SPEED 5
#define LEFT 1
#define RIGHT 2

class CEnemyUpdater : public CUpdater
{
	CTransform* transform;
	int delay;
	int PreKey;
	int AlphaSpeed;
public:
	CEnemyUpdater(CTransform* transform);
	~CEnemyUpdater();

	void move(bool isLeft);
	void moveRight();
	void moveLeft();
	void Update();
};

