#include "CGameHost.h"
#include "Resource.h"

CGameHost::CGameHost(HINSTANCE hInstance) {
	BgGround = LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_MAP)); //Init
	Player = new CPlayer(hInstance);
	PlayerHp = new CHp(10,10,CHP_PLAYER);
	EnemyHp = new CHp(335,10,CHP_ENEMY);
	Enemy = new CEnemy;
	Combo = new CCombo;
	Time = new CTime;
	Hit = new CHit;
	GameStatus = STATUS_RELEASE;
}

CGameHost::~CGameHost() {
	DeleteObject(BgGround); //DeInit
	if(Player) delete Player;
	if(PlayerHp) delete PlayerHp;
	if(EnemyHp) delete EnemyHp;
	if(Enemy) delete Enemy;
	if(Combo) delete Combo;
	if(Time) delete Time;
	if(Hit) delete Hit;
}

void CGameHost::KeyUpdate(WPARAM wParam) {
	if(GameStatus==STATUS_RELEASE) Player->KeyUpdate(wParam,Combo);
}

int CGameHost::Update() {
	if(GameStatus == STATUS_RELEASE) {
		Player->Update(Enemy,PlayerHp,Combo);
		if(PlayerHp->GetHp() <= 0) { //Win
			return 1;
		}
		if(EnemyHp->GetHp() <= 0) { //Lose
			return 2;
		}
		Enemy->Update(Player,EnemyHp,Combo,Hit);
		Time->IncTime();
	}
	return 0;
}

void CGameHost::Render(HDC hdc) {
	HBITMAP hBit = CreateCompatibleBitmap(hdc,600,500);
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC,hBit);
	Rectangle(hMemDC,0,0,600,500);
	//Draw Code Here (Double Buffering)
	this->DrawBgGround(hMemDC); //Draw BackGround
	Player->Render(hMemDC); //Draw Player
	Enemy->Render(hMemDC);
	DrawHp(hMemDC); //Draw Hp
	Combo->Render(hMemDC);
	Time->Render(hMemDC);
	Hit->Render(hMemDC);

	// Change Map BMP
	BitBlt(hdc,0,0,600,500,hMemDC,0,0,SRCCOPY);
	SelectObject(hMemDC,OldBit);
	DeleteDC(hMemDC);
	DeleteObject(hBit);
}

void CGameHost::DrawBgGround(HDC hdc) {
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC,BgGround);
	BitBlt(hdc,0,0,600,500,hMemDC,0,0,SRCCOPY);
	SelectObject(hMemDC,OldBit);
	DeleteDC(hMemDC);
}

void CGameHost::DrawHp(HDC hdc) {
	PlayerHp->Render(hdc);
	EnemyHp->Render(hdc);
}

void CGameHost::Pause() {
	GameStatus = STATUS_PAUSE;
}

void CGameHost::Release() {
	GameStatus = STATUS_RELEASE;
}