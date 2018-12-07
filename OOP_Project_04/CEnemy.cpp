#include "CEnemy.h"
#include "CTransform.h"
#include "CRenderer.h"
#include "CEnemyRenderer.h"
#include "CEnemyUpdater.h"
#include "CGameHost.h"

CEnemy::CEnemy() {
	
	this->transform = new CTransform(300, 40);
	this->transform->setSize(ENEMY_SIZE);
	this->renderer = new CEnemyRenderer(this->transform);
	this->updater = new CEnemyUpdater(transform);

	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
	CGameHost::updaters.push_back(updater);

	MoveMode = LEFT;
	Delay = 0;
	ComboDelay = 20;
	BulletMode = NON_UPGRADE;
}

CEnemy::~CEnemy() {
	//delete Bullet;
}

BOOL CEnemy::CheckHit(int _X, int _Y, int _Size) {
	return false;
}

void CEnemy::Render(HDC hdc) {
	this->renderer->Render(hdc);
}