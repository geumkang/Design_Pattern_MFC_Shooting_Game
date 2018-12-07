#ifndef _CENEMY_H_
#define _CENEMY_H_

#include <windows.h>
#include "CHp.h"
#include "CEnemy_Player.h"
#include "CCombo.h"
#include "CHit.h"
#include "CGameObject.h"

#define ENEMY_SIZE 25
#define LEFT 1
#define RIGHT 2
#define UPGRADE 0
#define NON_UPGRADE 1

//class CBulletMaker;
class CRenderer;
class CUpdater;
class CTransform;

class CEnemy : public CGameObject {
	int MoveMode;
	int Delay;

	int ComboDelay;
	BOOL BulletMode;

	//CBulletMaker *Bullet;
public:

	CTransform *transform;
	CRenderer* renderer;
	CUpdater* updater;

	CEnemy();
	virtual ~CEnemy();

	BOOL CheckHit(int,int,int);

	void Render(HDC);
};

#endif