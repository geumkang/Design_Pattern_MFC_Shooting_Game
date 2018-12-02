#ifndef _CCOMBO_H_
#define _CCOMBO_H_

#include <windows.h>
#include "CGameObject.h"

class CTransform;
class CRenderer;
class CUpdater;

class CCombo : public CGameObject {
	int nCombo;
	int comboCount;
public:

	CTransform* transform;
	CRenderer* renderer;
	CUpdater* updater;

	CCombo();
	~CCombo();

	void Update();
	void Render(HDC);
};

#endif