#include "CEnemyUpdater.h"
#include "CTransform.h"


CEnemyUpdater::CEnemyUpdater(CTransform* transform)
{
	this->transform = transform;
	PreKey = 0;
	AlphaSpeed = 0;
}


CEnemyUpdater::~CEnemyUpdater()
{
}

void CEnemyUpdater::moveRight()
{
	if (PreKey != RIGHT) AlphaSpeed = 0; //Check Last Key
	if (transform->getX() + AlphaSpeed + 1 < 580)
		transform->setX(transform->getX() + (AlphaSpeed + 1));
	if (AlphaSpeed < MAX_SPEED) AlphaSpeed++;
	PreKey = RIGHT;
}

void CEnemyUpdater::moveLeft()
{
	if (PreKey != LEFT) AlphaSpeed = 0; //Check Last Key
	if (transform->getX() - AlphaSpeed + 1 > 0)
		transform->setX(transform->getX() - (AlphaSpeed + 1));
	if (AlphaSpeed < MAX_ENEMY_SPEED) AlphaSpeed++;
	PreKey = LEFT;
}
