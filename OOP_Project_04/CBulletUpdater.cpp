#include "CBulletUpdater.h"
#include "CTransform.h"


CBulletUpdater::CBulletUpdater(CTransform* transform)
{
	this->transform = transform;
}


CBulletUpdater::~CBulletUpdater()
{
}

void CBulletUpdater::Update()
{
	if (isEnemy) {
		this->transform->setY( this->transform->getY() + BULLET_SPEED);
	}
	else {
		this->transform->setY(this->transform->getY() - BULLET_SPEED);
	}
}

void CBulletUpdater::reverse_direction() 
{
	isEnemy = !isEnemy;
}

bool CBulletUpdater::getIsEnemy()
{
	return isEnemy;
}
