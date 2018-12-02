#ifndef _CTime_H_
#define _CTime_H_

#include <windows.h>
#include "CGameObject.h"
#include "CTransform.h"
#include "CHitRenderer.h"
#include "CHitUpdater.h"

class CTime : public CGameObject{
	int nTime;

public:

	CTransform* transform;
	CHitRenderer* renderer;
	CHitUpdater* updater;

	CTime();
	virtual ~CTime();

	void Update();
	void Render(HDC);

	void InitTime();
	void IncTime();
	int GetTime();
};

#endif