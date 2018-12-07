#ifndef _CPLAYER_H_
#define _CPLAYER_H_

#include <windows.h>
#include <vector>
#include <iostream>
#include "CEnemy_Player.h"
#include "CCombo.h"
/*KCH*/
#include "CGameObject.h"
#include "CTransform.h"
#include "CRenderer.h"
#include "CUpdater.h"

using namespace std;
#define MAX_SPEED 5

#define UPGRADE 0
#define NON_UPGRADE 1

class CPlayer : public CGameObject{
	HBITMAP hPlayerBit;

	int AlphaSpeed;
	int PreKey;
	bool BulletMode;

	void Attack(CCombo*);
	void Special_Attack(CCombo*);
public:
	/*KCH*/
	CTransform* transform;
	CRenderer* renderer;
	CUpdater* updater;

	CPlayer(HINSTANCE);
	virtual ~CPlayer();

	void KeyUpdate(SHORT,CCombo*);
	int Update(CEnemy*, CHp*, CCombo*);
	void Render(HDC);

	BOOL CheckHit(int,int,int);
	BOOL IsBullet();
	void setIsBullet(bool IsBullet);

	int GetX() { return this->transform->getX();}
	int GetY() { return this->transform->getY();}
	int GetSize() { return this->transform->getSize(); }
	void SetX(int value) { this->transform->setX(value); }
	void SetY(int value) { this->transform->setY(value); }
};

#endif