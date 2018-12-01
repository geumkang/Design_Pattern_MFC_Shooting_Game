#include "CEnemy.h"

CEnemy::CEnemy() {
	X = 300;
	Y = 40;
	MoveMode = LEFT;
	Delay = 0;
	AlphaSpeed = 0, PreKey = 0;
	ComboDelay = 20;
	BulletMode = NON_UPGRADE;

	EnemyBrush1 = CreateSolidBrush(RGB(0,0,255));
	EnemyBrush2 = CreateSolidBrush(RGB(0,0,128));
	EnemyPen = (HPEN)GetStockObject(NULL_PEN);

	Bullet = new CBullet(TRUE);
}

CEnemy::~CEnemy() {
	DeleteObject(EnemyBrush1);
	DeleteObject(EnemyBrush2);
	DeleteObject(EnemyPen);
	delete Bullet;
}

BOOL CEnemy::CheckHit(int _X, int _Y, int _Size) {
	return (Bullet->CheckHit(_X,_Y,_Size));
}

void CEnemy::Update(CPlayer *User, CHp *Hp, CCombo *Combo, CHit *Hit) {
	int n;

	srand(GetTickCount());
	if((User->CheckHit(X,Y,ENEMY_SIZE))) {
		Hp->MovHp(-3);
		Hit->IncHit();
		if(ComboDelay) Combo->IncCombo();
		ComboDelay = 40;
	} else {
		if(!ComboDelay) Combo->InitCombo();
	}
	if((User->IsBullet())) {
		if(!Delay)	{
			if(!(rand()%10)) {
				BulletMode = UPGRADE;
			} else {
				BulletMode = NON_UPGRADE;
			}
			if(X-200>User->GetX()) {
				n = rand()%7;
				if(n<6) MoveMode = LEFT;
				else MoveMode = RIGHT;
				goto AFTER_MOVE_CAL;
			} else if(X+200<User->GetX()) {
				n = rand()%7;
				if(n<6) MoveMode = RIGHT;
				else MoveMode = LEFT;
				goto AFTER_MOVE_CAL;
			}
			if(X>User->GetX()) {
				n = rand()%7;
				if(n<3) MoveMode = LEFT;
				else MoveMode = RIGHT;
			} else if(X<User->GetX()) {
				n = rand()%7;
				if(n<3) MoveMode = RIGHT;
				else MoveMode = LEFT;
			}
		}
AFTER_MOVE_CAL:
		if(MoveMode == LEFT) {
			if(PreKey!=LEFT) AlphaSpeed = 0; //Check Last Key
			if(X-AlphaSpeed+1>0)
				X-=(AlphaSpeed+1);
			if(AlphaSpeed<MAX_ENEMY_SPEED) AlphaSpeed++;
			PreKey = LEFT;
		} else if(MoveMode == RIGHT) {
			if(PreKey!=RIGHT) AlphaSpeed = 0; //Check Last Key
			if(X+AlphaSpeed+1<580)
				X+=(AlphaSpeed+1);
			if(AlphaSpeed<MAX_SPEED) AlphaSpeed++;
			PreKey = RIGHT;
		}
		Delay++;
		if(Delay==6) Delay=0;
	} else {
		if(X>User->GetX()) {
			if(PreKey!=LEFT) AlphaSpeed = 0; //Check Last Key
			if(X-AlphaSpeed+1>0)
				X-=(AlphaSpeed+1);
			if(AlphaSpeed<MAX_ENEMY_SPEED) AlphaSpeed++;
			PreKey = LEFT;
			X--;
		} else if(X<User->GetX()) {
			if(PreKey!=RIGHT) AlphaSpeed = 0; //Check Last Key
			if(X+AlphaSpeed+1<580)
				X+=(AlphaSpeed+1);
			if(AlphaSpeed<MAX_SPEED) AlphaSpeed++;
			PreKey = RIGHT;
			X++;
		}
	}
	if(BulletMode == NON_UPGRADE)
		Bullet->PushBody(X+ENEMY_SIZE/2-1,Y,0);
	else if(BulletMode == UPGRADE)
		Bullet->PushBody(X+ENEMY_SIZE/2,Y,10);
	Bullet->Update();
	if(ComboDelay>0) ComboDelay--;
}

void CEnemy::Render(HDC hdc) {
	HBRUSH OldBrush = (HBRUSH)SelectObject(hdc,EnemyBrush1);
	HPEN OldPen = (HPEN)SelectObject(hdc,EnemyPen);
	Ellipse(hdc,X,Y,X+ENEMY_SIZE,Y+ENEMY_SIZE);
	SelectObject(hdc,EnemyBrush2);
	Ellipse(hdc,(int)(X+ENEMY_SIZE*1.0/5),(int)(Y+ENEMY_SIZE*1.0/5),(int)(X+ENEMY_SIZE*4.0/5),(int)(Y+ENEMY_SIZE*4.0/5));
	SelectObject(hdc,OldBrush);
	SelectObject(hdc,OldPen);

	Bullet->Render(hdc);
}