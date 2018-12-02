#include "CEnemy.h"
#include "CTransform.h"
#include "CEnemyRenderer.h"
#include "CEnemyUpdater.h"
#include "CBulletMaker.h"

CEnemy::CEnemy() {
	
	this->transform = new CTransform(300, 40);
	this->transform->setSize(ENEMY_SIZE);
	this->renderer = new CEnemyRenderer(this->transform);
	this->updater = new CEnemyUpdater(transform);

	MoveMode = LEFT;
	Delay = 0;
	ComboDelay = 20;
	BulletMode = NON_UPGRADE;
	
	//Bullet = new CBulletMaker(TRUE);
}

CEnemy::~CEnemy() {
	//delete Bullet;
}

BOOL CEnemy::CheckHit(int _X, int _Y, int _Size) {
	//return (Bullet->CheckHit(new CTransform(_X, _Y), _Size));
	return false;
}

void CEnemy::Update(CPlayer *User, CHp *Hp, CCombo *Combo, CHit *Hit) {
	int n;

	srand(GetTickCount());
	if((User->CheckHit(transform->getX(), transform->getY(), transform->getSize()))) {
		Hp->MovHp(-3);
		Hit->IncHit();
		if(ComboDelay) Combo->IncCombo();
		ComboDelay = 40;
	} else {
		if(!ComboDelay) Combo->InitCombo();
	}
	if((User->IsBullet())) {
		if(!Delay)	{
			if(!(rand() % 10)) {
				BulletMode = UPGRADE;
			} else {
				BulletMode = NON_UPGRADE;
			}
			if(transform->getX()-200 > User->transform->getX()) {
				n = rand() % 7;
				if(n < 6) MoveMode = LEFT;
				else MoveMode = RIGHT;
				goto AFTER_MOVE_CAL;
			} else if(transform->getX()+200 < User->transform->getX()) {
				n = rand() % 7;
				if(n < 6) MoveMode = RIGHT;
				else MoveMode = LEFT;
				goto AFTER_MOVE_CAL;
			}
			if(transform->getX() > User->transform->getX()) {
				n = rand() % 7;
				if(n < 3) MoveMode = LEFT;
				else MoveMode = RIGHT;
			} else if(transform->getX() < User->transform->getX()) {
				n = rand() % 7;
				if(n < 3) MoveMode = RIGHT;
				else MoveMode = LEFT;
			}
		}
AFTER_MOVE_CAL:
		if(MoveMode == LEFT) {
			updater->moveLeft();
		} else if(MoveMode == RIGHT) {
			updater->moveRight();
		}
		Delay++;
		if(Delay==6) Delay=0;
	} else {
		if(transform->getX() > User->transform->getX()) {
			updater->moveLeft();
			transform->setX(transform->getX() - 1);
		} else if(transform->getX() < User->transform->getX()) {
			updater->moveRight();
			transform->setX(transform->getX() + 1);
		}
	}
	if (BulletMode == NON_UPGRADE) {
		CTransform* temp = new CTransform(transform->getX() + transform->getSize() / 2 - 1, transform->getY());
		//Bullet->PushBody(temp, 0);
	}
	else if (BulletMode == UPGRADE) {
		CTransform* temp = new CTransform(transform->getX() + transform->getSize() / 2, transform->getY());
		//Bullet->PushBody(temp, 10);
	}
	//Bullet->Update();
	if(ComboDelay > 0) ComboDelay--;
}

void CEnemy::Render(HDC hdc) {
	this->renderer->render(hdc);

	//Bullet->Render(hdc);
}