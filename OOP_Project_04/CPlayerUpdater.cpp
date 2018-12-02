#include "CPlayerUpdater.h"
#include "CTransform.h"
#include "CBullet.h"

CPlayerUpdater::CPlayerUpdater(CTransform * transform)
{
	this->transform = transform;
	delay = 0;
	PreKey = 0;
	AlphaSpeed = 0;
}

CPlayerUpdater::~CPlayerUpdater()
{
}

void CPlayerUpdater::pushRight()
{
	if (PreKey != RIGHT) {
		AlphaSpeed = 0; //Check Last Key
	}
	if (transform->getX() + AlphaSpeed + 1 < 580) {
		transform->setX(transform->getX() + AlphaSpeed + 1);
	}
	if (AlphaSpeed < MAX_SPEED) AlphaSpeed++;
	PreKey = RIGHT;
}

void CPlayerUpdater::pushLeft()
{
	if (PreKey != LEFT) {
		AlphaSpeed = 0; //Check Last Key
	}
	if (transform->getX() - AlphaSpeed + 1 > 0) {
		transform->setX(transform->getX() - AlphaSpeed + 1);
	}
	if (AlphaSpeed < MAX_SPEED) AlphaSpeed++;
	PreKey = LEFT;
}

void CPlayerUpdater::pushUp()
{
	if (PreKey != UP) {
		AlphaSpeed = 0; //Check Last Key
	}
	if (transform->getY() - AlphaSpeed + 1 > 120) {
		transform->setY(transform->getY() - AlphaSpeed + 1);
	}
	if (AlphaSpeed < MAX_SPEED) AlphaSpeed++;
	PreKey = UP;
}

void CPlayerUpdater::pushDown()
{
	if (PreKey != DOWN) {
		AlphaSpeed = 0; //Check Last Key
	}
	if (transform->getY() + AlphaSpeed + 1 < 440) {
		transform->setY(transform->getY() + AlphaSpeed + 1);
	}
	if (AlphaSpeed < MAX_SPEED) AlphaSpeed++;
	PreKey = DOWN;
}

void CPlayerUpdater::pushAttack()
{
	if (delay > 5) {
		CBullet* bullet = new CBullet(this->transform, false);
		delay = 0;
	}
	delay++;
}

void CPlayerUpdater::pushSpecial()
{
}

void CPlayerUpdater::Update()
{
}
