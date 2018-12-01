#pragma once

#define MAX_SPEED 5
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4


class CTransform;

class CPlayerUpdater
{
	CTransform* transform;
	int PreKey;
	int AlphaSpeed;
public:
	CPlayerUpdater(CTransform* transform);
	~CPlayerUpdater();

	void pushRight();
	void pushLeft();
	void pushUp();
	void pushDown();

	void pushAttack();
	void pushSpecial();
};

