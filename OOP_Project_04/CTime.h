#ifndef _CTime_H_
#define _CTime_H_

#include <windows.h>
#include "CGameObject.h"

class CTransform;
class CRenderer;
class CUpdater;

class CTime : public CGameObject{
	int nTime;

public:

	CTransform* transform;
	CRenderer* renderer;
	CUpdater* updater;

	CTime();
	virtual ~CTime();

	void Update();
	void Render(HDC);
};

#endif