#ifndef _CHP_H_
#define _CHP_H_

#include <windows.h>
#include "CGameObject.h"
#define CHP_NORMAL 1
#define CHP_DANGER 2

#define CHP_PLAYER 1
#define CHP_ENEMY  2

class CTransform;
class CRenderer;

class CHp : public CGameObject{
	const int MaxHp;
	const int User;
	int Hp;
	//int Mode;
	CTransform* transform;
	CRenderer* renderer;

public:
	CHp(int,int,int);
	virtual ~CHp();

	int GetMaxHp();
	int GetHp();
	void SetHp(int Hp);
	void MovHp(int Hp);

	void Update();
	void Render(HDC);
};

#endif
