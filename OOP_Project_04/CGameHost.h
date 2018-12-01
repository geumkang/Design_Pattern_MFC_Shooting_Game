#ifndef _CGAMEHOST_H_
#define _CGAMEHOST_H_

#include <windows.h>
#include "CPlayer.h"
#include "CHp.h"
#include "CEnemy.h"
#include "CTime.h"

#define STATUS_PAUSE 1
#define STATUS_RELEASE 0

class CGameHost {
	HBITMAP BgGround; //BgGround
	CPlayer *Player;
	CHp *PlayerHp, *EnemyHp;
	CEnemy *Enemy;
	CCombo *Combo;
	CTime *Time;
	CHit *Hit;

	BOOL GameStatus;
public:
	CGameHost(HINSTANCE);
	~CGameHost();

	void Render(HDC);
	void KeyUpdate(WPARAM);
	int Update();

	void DrawBgGround(HDC);
	void DrawHp(HDC);

	void Pause();
	void Release();
};

#endif