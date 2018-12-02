#include "CPlayer.h"
#include "Resource.h"
#include "CBulletMaker.h"
#include "CGameHost.h"
#include "CPlayerRenderer.h"
#include "CPlayerUpdater.h"

#pragma comment(lib,"msimg32.lib")

int special_count = 3;

CPlayer::CPlayer(HINSTANCE hInstance) {
	hPlayerBit = LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_CHARACTER));

	this->transform = new CTransform(300, 400);
	this->transform->setSize(23);
	this->renderer = new CPlayerRenderer(this->transform);
	((CPlayerRenderer*)renderer)->setBitmap(hPlayerBit);
	this->updater = new CPlayerUpdater(transform);
	

	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
	CGameHost::updaters.push_back(updater);

	AlphaSpeed = 0, PreKey = 0;
	//Bullet = new CBulletMaker(FALSE);
	BulletMode = NON_UPGRADE;
}

CPlayer::~CPlayer() {
	DeleteObject(hPlayerBit);
	//delete Bullet;
}

//void CPlayer::DrawPlayer(HDC hdc) {
//	HDC hMemDC = CreateCompatibleDC(hdc);
//	HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC,hPlayerBit);
//	TransparentBlt(hdc,GetX(),GetY(),Size,Size,hMemDC,0,0,Size,Size,RGB(0,255,0));
//	SelectObject(hMemDC,OldBit);
//	DeleteDC(hMemDC);
//}

void CPlayer::KeyUpdate(SHORT wParam, CCombo *Combo) {
	if(wParam==VK_LEFT) { //Pressed Left Key
		//updater->pushLeft();
	} else if(wParam==VK_RIGHT) { //Pressed Right Key
		//updater->pushRight();
	} else if(wParam==VK_UP) { //Pressed Up Key
		//updater->pushUp();
	} else if(wParam==VK_DOWN) { //Pressed Down Key
		//updater->pushDown();
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
		int X = (*Iter)->GetPosX();
		int Y = (*Iter)->GetPosY();
		SetPixel(hdc,X,Y,RGB(255,(int)color,(int)color));
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
	this->BulletMode = true;
	//Bullet->PushBody(new CTransform(GetX() + GetSize() / 2 - 1, GetY()), Combo->GetCombo());
}

// �ʻ��� �ɷ� ����
void CPlayer::Special_Attack(CCombo* Combo) {
	if(special_count > 0)
		while(true)
		{
			/*Combo->IncCombo();
			if(Combo->GetCombo() > 10)
				break;*/
		}
	special_count--;
}

int CPlayer::Update(CEnemy *Enemy, CHp *Hp, CCombo *Combo) {
	PopBody();
	//Bullet->Update();
	if((Enemy->CheckHit(GetX(),GetY(),ENEMY_SIZE))) {
		Hp->MovHp(-3);
	}

	/*if(Combo->GetCombo() > 10) {
		BulletMode = UPGRADE;
		return 1;
	}*/
	BulletMode = NON_UPGRADE;
	return 0;
}

void CPlayer::Render(HDC hdc) {

	this->renderer->Render(hdc);
	//Bullet->Render(hdc);
}

BOOL CPlayer::CheckHit(int _X, int _Y, int _Size) {
	//return (Bullet->CheckHit(new CTransform(_X, _Y), _Size));
	return false;
}

BOOL CPlayer::IsBullet() {
	//return (Bullet->GetBulletMode());
	return this->BulletMode;
}

void CPlayer::setIsBullet(bool IsBullet)
{
	this->BulletMode = IsBullet;
}

CPlayerBody::CPlayerBody(int PosX, int PosY) {
	m_PosX = PosX, m_PosY = PosY;
}

CPlayerBody::~CPlayerBody() {
}

void CPlayerBody::Update() {
}
