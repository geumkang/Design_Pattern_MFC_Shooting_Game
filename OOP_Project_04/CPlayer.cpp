#include "CPlayer.h"
#include "Resource.h"
#pragma comment(lib,"msimg32.lib")

int special_count = 3 ;

CPlayer::CPlayer(HINSTANCE hInstance) : Size(23) {
	hPlayerBit = LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_CHARACTER));
	X = 300, Y = 400;
	AlphaSpeed = 0, PreKey = 0;
	Bullet = new CBullet(FALSE);
	BulletMode = NON_UPGRADE;
}

CPlayer::~CPlayer() {
	DeleteObject(hPlayerBit);
	delete Bullet;
}

void CPlayer::DrawPlayer(HDC hdc) {
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC,hPlayerBit);
	TransparentBlt(hdc,X,Y,Size,Size,hMemDC,0,0,Size,Size,RGB(0,255,0));
	SelectObject(hMemDC,OldBit);
	DeleteDC(hMemDC);
}

void CPlayer::KeyUpdate(SHORT wParam, CCombo *Combo) {
	int i;
	if(wParam==VK_LEFT) { //Pressed Left Key
		if(PreKey!=wParam) AlphaSpeed = 0; //Check Last Key
		for(i=0;i<AlphaSpeed+1;i++) { //Push Body
			PushBody(X+i+12,Y+12);
			PushBody(X+i+12,Y+13);
			PushBody(X+i+12,Y+14);
		}
		if(X-AlphaSpeed+1>0)
			X-=(AlphaSpeed+1);
		if(AlphaSpeed<MAX_SPEED) AlphaSpeed++;
		PreKey = wParam;
	} else if(wParam==VK_RIGHT) { //Pressed Right Key
		if(PreKey!=wParam) AlphaSpeed = 0; //Check Last Key
		for(i=0;i<AlphaSpeed+1;i++) { //Push Body
			PushBody(X+i+12,Y+12);
			PushBody(X+i+12,Y+13);
			PushBody(X+i+12,Y+14);
		}
		if(X+AlphaSpeed+1<580)
			X+=(AlphaSpeed+1);
		if(AlphaSpeed<MAX_SPEED) AlphaSpeed++;
		PreKey = wParam;
	} else if(wParam==VK_UP) { //Pressed Up Key
		if(PreKey!=wParam) AlphaSpeed = 0; //Check Last Key
		for(i=0;i<AlphaSpeed+1;i++) { //Push Body
			PushBody(X+12,Y+i+12);
			PushBody(X+13,Y+i+12);
			PushBody(X+14,Y+i+12);
		}
		if(Y-AlphaSpeed+1>120)
			Y-=(AlphaSpeed+1);
		if(AlphaSpeed<MAX_SPEED) AlphaSpeed++;
		PreKey = wParam;
	} else if(wParam==VK_DOWN) { //Pressed Down Key
		if(PreKey!=wParam) AlphaSpeed = 0; //Check Last Key
		for(i=0;i<AlphaSpeed+1;i++) { //Push Body
			PushBody(X+12,Y+i+12);
			PushBody(X+13,Y+i+12);
			PushBody(X+14,Y+i+12);
		}
		if(Y+AlphaSpeed+1<440)
			Y+=(AlphaSpeed+1);
		if(AlphaSpeed<MAX_SPEED) AlphaSpeed++;
		PreKey = wParam;
	} else if(wParam == 'Z') { //Pressed Z (Attack)
		Attack(Combo);
	} else if(wParam == 'X') { //Pressed Z (Special Attack)
		Special_Attack(Combo);
	}
}

void CPlayer::DrawPlayerBody(HDC hdc) {
	int i;
	double color = 0;

	vector<CPlayerBody*>::size_type Count = Body.size();
	color = i = 255;
	for(vector<CPlayerBody*>::iterator Iter=Body.begin();Iter!=Body.end();++Iter) {
		int x = (*Iter)->GetPosX(), y = (*Iter)->GetPosY();
		SetPixel(hdc,x,y,RGB(255,(int)color,(int)color));
		if(i%2==0)
			color -= (double)(255.0/Count);
		i++;
	}
}

void CPlayer::PushBody(int PosX, int PosY) {
	CPlayerBody* Body = new CPlayerBody(PosX,PosY);
	this->Body.push_back(Body);
}

void CPlayer::PopBody() {
	vector<CPlayerBody*>::size_type Count = Body.size();
		if(Count>AlphaSpeed*3) {
		for(int i=0;i<AlphaSpeed*3;i++)
			this->Body.erase(this->Body.begin());
	} else if(Count>AlphaSpeed*2) {
		for(int i=0;i<AlphaSpeed*2;i++)
			this->Body.erase(this->Body.begin());
	}
}

void CPlayer::Attack(CCombo* Combo) {
	Bullet->PushBody(X+Size/2-1,Y,Combo->GetCombo());
}

// 필살기 능력 설정
void CPlayer::Special_Attack(CCombo* Combo) {
	if(special_count > 0)
		while(true)
		{
			Combo->IncCombo();
			if(Combo->GetCombo() > 10)
				break;
		}
	special_count--;
}

int CPlayer::Update(CEnemy *Enemy, CHp *Hp, CCombo *Combo) {
	PopBody();
	Bullet->Update();
	if((Enemy->CheckHit(X,Y,ENEMY_SIZE))) {
		Hp->MovHp(-3);
	}

	if(Combo->GetCombo() > 10) {
		BulletMode = UPGRADE;
		return 1;
	}
	BulletMode = NON_UPGRADE;
	return 0;
}

void CPlayer::Render(HDC hdc) {
	DrawPlayerBody(hdc);
	DrawPlayer(hdc);
	Bullet->Render(hdc);
}

BOOL CPlayer::CheckHit(int _X, int _Y, int _Size) {
	return (Bullet->CheckHit(_X,_Y,_Size));
}

BOOL CPlayer::IsBullet() {
	return (Bullet->GetBulletMode());
}

CPlayerBody::CPlayerBody(int PosX, int PosY) {
	m_PosX = PosX, m_PosY = PosY;
}

CPlayerBody::~CPlayerBody() {
}

void CPlayerBody::Update() {
}