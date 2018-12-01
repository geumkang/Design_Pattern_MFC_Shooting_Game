#ifndef _CCOMBO_H_
#define _CCOMBO_H_

#include <windows.h>

#include "CTransform.h"
#include "CHitRenderer.h"
#include "CHitUpdater.h"

class CCombo {
	int nCombo;

public:

	CTransform* transform;
	CHitRenderer* renderer;
	CHitUpdater* updater;

	CCombo();
	~CCombo();

	void Update();
	void Render(HDC);

	void InitCombo();
	void IncCombo();
	int GetCombo();
};

#endif