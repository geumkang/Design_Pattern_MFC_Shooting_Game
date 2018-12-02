#ifndef _CHit_H_
#define _CHit_H_

#include <windows.h>

#include "CGameObject.h"

class CTransform;
class CRenderer;
class CUpdater;

class CHit : public CGameObject{
	int nHit;

	/*COLORREF HitColor[MAX_Hit_COLOR];
	HFONT hHitFont;*/
public:

	CTransform* transform;
	CRenderer* renderer;
	CUpdater* updater;

	CHit();
	virtual ~CHit();

	void Update();
	void Render(HDC);

	void InitHit();
	void IncHit();
	int GetHit();
};

#endif