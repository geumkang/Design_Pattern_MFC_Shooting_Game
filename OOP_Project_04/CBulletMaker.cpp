#include "CBulletMaker.h"
#include "CBullet.h"
#include "CTransform.h"
#include "CGameHost.h"

CBulletMaker::CBulletMaker(CTransform* player_transform, bool isEnemy)
{
	this->isEnemy = isEnemy;
	this->Delay = -1;
}

CBulletMaker::~CBulletMaker()
{
}

void CBulletMaker::Render(HDC hdc)
{
	for (vector<CBullet*>::iterator Iter = bullets.begin(); Iter != bullets.end(); ++Iter) {
		(*Iter)->Render(hdc);
	}
}

void CBulletMaker::Update()
{
	for(vector<CBullet*>::iterator Iter=bullets.begin();Iter!=bullets.end();++Iter) {
		if((*Iter)->transform->getY()==0 || (*Iter)->transform->getY()==600) {
			bullets.erase(Iter);
		}
		(*Iter)->Update();
	}
}

bool CBulletMaker::CheckHit(CTransform* transform, int Size)
{
	for (vector<CBullet*>::iterator Iter = bullets.begin(); Iter != bullets.end(); ++Iter) {
		int _X = (*Iter)->transform->getX();
		int _Y = (*Iter)->transform->getY();
		if (transform->getX() - BULLET_WIDTH <= _X && 
			transform->getX() - BULLET_WIDTH + Size >= _X &&
			transform->getY() - BULLET_HEIGHT <= _Y &&
			transform->getY() + Size >= _Y) {
			bullets.erase(Iter);
			goto CBULLET_CHECKHIT;
		}
	}
	return FALSE;
CBULLET_CHECKHIT:
	return TRUE;
}

void CBulletMaker::PushBody(CTransform* transform, int Combo)
{
	if(!Delay) {
		CBullet *bullet;
		//if(!bEnemy) {
		if(Combo>=10) {
			bullet = new CBullet(new CTransform(transform->getX()-7,
				transform->getY()-3),isEnemy);
			this->bullets.push_back(bullet);
			bullet = new CBullet(new CTransform(transform->getX() + 7,
				transform->getY() - 3), isEnemy);
			this->bullets.push_back(bullet);
		}
		//}
		bullet = new CBullet(transform, isEnemy);
		this->bullets.push_back(bullet);
	}
	Delay++;
	if(Delay==5) Delay=0;
}

bool CBulletMaker::GetBulletMode()
{
	return (bullets.size() != 0);
}
