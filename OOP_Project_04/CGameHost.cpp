#include "CGameHost.h"
#include "Resource.h"
#include "CBullet.h"
#include "CBulletUpdater.h"
#include "CComboUpdater.h"
#include "PlayerUpCommand.h"
#include "PlayerDownCommand.h"
#include "PlayerLeftCommand.h"
#include "PlayerRightCommand.h"
#include "PlayerAttackCommand.h"
#include "CEnemyUpdater.h"

CGameHost* CGameHost::gameHost;
vector<CRenderer*> CGameHost::renderers;
vector<CUpdater*>  CGameHost::updaters;
vector<CBullet*> CGameHost::bullets;

CGameHost::CGameHost(HINSTANCE hInstance) {
	BgGround = LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_MAP)); //Init
	Player = new CPlayer(hInstance);

	controller = new Controller();
	Command* upCommand = new PlayerUpCommand(Player->updater);
	controller->setUpCommand(upCommand);
	Command* downCommand = new PlayerDownCommand(Player->updater);
	controller->setDownCommand(downCommand);
	Command* leftCommand = new PlayerLeftCommand(Player->updater);
	controller->setLeftCommand(leftCommand);
	Command* rightCommand = new PlayerRightCommand(Player->updater);
	controller->setRightCommand(rightCommand);
	Command* attackCommand = new PlayerAttackCommand(Player->updater);
	controller->setAttackCommand(attackCommand);

	PlayerHp = new CHp(10,10,CHP_PLAYER);
	EnemyHp = new CHp(335,10,CHP_ENEMY);
	Enemy = new CEnemy();
	Combo = new CCombo();
	Time = new CTime();
	Hit = new CHit();
	GameStatus = STATUS_RELEASE;
}

void CGameHost::KeyUpdate(WPARAM wParam) {
	//if(GameStatus==STATUS_RELEASE) Player->KeyUpdate(wParam,Combo);
}

int CGameHost::Update() {
	if(GameStatus == STATUS_RELEASE) {
		//Player->Update(Enemy,PlayerHp,Combo);
		if(PlayerHp->GetHp() <= 0) { //Win
			return 1;
		}
		if(EnemyHp->GetHp() <= 0) { //Lose
			return 2;
		}
		//Enemy->Update(Player,EnemyHp,Combo,Hit);
		//Time->IncTime();
	}

	for (int i = 0; i < updaters.size(); i++)
	{
		updaters.at(i)->Update();
	}

	run();

	return 0;
}

void CGameHost::Render(HDC hdc) {

	/*
	renderers->renderall();
	*/
	HBITMAP hBit = CreateCompatibleBitmap(hdc,600,500);
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC,hBit);
	Rectangle(hMemDC,0,0,600,500);
	//Draw Code Here (Double Buffering)
	this->DrawBgGround(hMemDC); //Draw BackGround
	//Player->Render(hMemDC); //Draw Player
	//Enemy->Render(hMemDC);
	//DrawHp(hMemDC); //Draw Hp
	//Combo->Render(hMemDC);
	//Time->Render(hMemDC);
	//Hit->Render(hMemDC);

	//Draw Frame
	for (int i = 0; i < renderers.size(); i++)
	{
		renderers.at(i)->Render(hMemDC);
	}

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

void CGameHost::run()
{
	int playerX = this->Player->transform->getX();
	int playerY = this->Player->transform->getY();
	int playerSize = this->Player->transform->getSize();
	int enemyX = this->Enemy->transform->getX();
	int enemyY = this->Enemy->transform->getY();
	int enemySize = this->Enemy->transform->getSize();
	for (int i = CGameHost::bullets.size() - 1; i > -1; i--)
	{
		CBullet* bullet = CGameHost::bullets[i];
		int bulletX = bullet->transform->getX();
		int bulletY = bullet->transform->getY();
		int bulletSize = bullet->transform->getSize();

		if (!bullet->isAlive)
			continue;

		if (((CBulletUpdater*)bullet->updater)->getIsEnemy()) {
			if (playerX < bulletX
				&& playerX + playerSize > bulletX
				&& playerY < bulletY
				&& playerY + playerSize > bulletY) {

				this->PlayerHp->MovHp(-3);

				bullet->isAlive = false;
			}	
		}
		if (!((CBulletUpdater*)bullet->updater)->getIsEnemy()) {
			if (enemyX < bulletX
				&& enemyX + enemySize > bulletX
				&& enemyY < bulletY
				&& enemyY + enemySize > bulletY) {

				this->EnemyHp->MovHp(-3);
				this->Hit->IncHit();
				
				((CComboUpdater*)this->Combo->updater)->IncCombo();
				
				bullet->isAlive = false;
			}
		}
	}
	/* Enemy Move */

	/* LEFT? RIGHT? */
	srand(GetTickCount());
	bool MoveMode = (enemyX > playerX);
	MoveMode = MoveMode & (rand()%7 < 5);
	((CEnemyUpdater*)this->Enemy->updater)->move(MoveMode);


	/* Delaying */
	Delay++;
	if (Delay == 6) Delay = 0;
}

CGameHost* CGameHost::newGameHost(HINSTANCE hInstance)
{
	if (CGameHost::gameHost != NULL) {
		DeleteObject(CGameHost::gameHost);
		CGameHost::gameHost = new CGameHost(hInstance);
	}
	return CGameHost::gameHost;
}

CGameHost* CGameHost::getGameHost(HINSTANCE hInstance)
{
	if (CGameHost::gameHost == NULL) {
		CGameHost::gameHost = new CGameHost(hInstance);
	}
	return CGameHost::gameHost;
}