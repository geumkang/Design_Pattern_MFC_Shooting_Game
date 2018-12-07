#ifndef _CBULLET_H_
#define _CBULLET_H_

#include <windows.h>
#include <vector>
#include <iostream>
#include "CGameObject.h"
using namespace std;

#define BULLET_SPEED 6
#define BULLET_WIDTH 5
#define BULLET_HEIGHT 10

class CRenderer;
class CUpdater;
class CTransform;

class CBullet : public CGameObject {
	bool bEnemy;
public:

	bool isAlive = true;

	CRenderer* renderer;
	CUpdater* updater;
	CTransform* transform;

	CBullet(CTransform* player_transform, bool);
	virtual ~CBullet();

	void Update();
	void Render(HDC);
};

#endif