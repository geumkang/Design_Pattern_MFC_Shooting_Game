#ifndef _CGAMEHOST_H_
#define _CGAMEHOST_H_

#include <windows.h>
#include "CPlayer.h"
#include "CHp.h"
#include "CEnemy.h"
#include "CTime.h"
#include "Controller.h"

#define STATUS_PAUSE 1
#define STATUS_RELEASE 0

class CGameHost {

	CGameHost(HINSTANCE);
	static CGameHost* gameHost;

	HBITMAP BgGround; //BgGround
	CPlayer *Player;
	CHp *PlayerHp, *EnemyHp;
	CEnemy *Enemy;
	CCombo *Combo;
	CTime *Time;
	CHit *Hit;

	BOOL GameStatus;
public:
	Controller* controller;

	//CGameHost(HINSTANCE);
	~CGameHost() {
		DeleteObject(BgGround); //DeInit
		if (Player) delete Player;
		if (PlayerHp) delete PlayerHp;
		if (EnemyHp) delete EnemyHp;
		if (Enemy) delete Enemy;
		if (Combo) delete Combo;
		if (Time) delete Time;
		if (Hit) delete Hit;
		DeleteObject(gameHost);
	}

	void Render(HDC);
	void KeyUpdate(WPARAM);
	int Update();

	void DrawBgGround(HDC);
	void DrawHp(HDC);

	void Pause();
	void Release();

	static CGameHost* getGameHost(HINSTANCE hInstance);
	static CGameHost* newGameHost(HINSTANCE hInstance);
};

#endif