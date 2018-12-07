#include "CBullet.h"
#include "CTransform.h"
#include "CBulletRenderer.h"
#include "CBulletUpdater.h"
#include "CGameHost.h"


CBullet::CBullet(CTransform* player_transform, bool bEnemy) {
	this->bEnemy = bEnemy;
	
	this->transform = new CTransform(player_transform->getX()+player_transform->getSize()/2, player_transform->getY());
	this->renderer = new CBulletRenderer(this->transform);
	((CBulletRenderer*)this->renderer)->setAlive(&isAlive);
	this->updater = new CBulletUpdater(this->transform);
	if (bEnemy) {
		((CBulletUpdater*)this->updater)->reverse_direction();
		((CBulletRenderer*)this->renderer)->set_bullet_color(255,0,0);
	}

	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
	CGameHost::updaters.push_back(updater);
	CGameHost::bullets.push_back(this);
}

CBullet::~CBullet() {
}

void CBullet::Update() {
	this->updater->Update();
}

void CBullet::Render(HDC hdc) {
	this->renderer->Render(hdc);
}