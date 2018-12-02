#pragma once
#include <windows.h>
#include "CRenderer.h"
#include "CTransform.h"

#define MAX_HP 300

class CHpRenderer : public CRenderer
{
protected:
	CTransform* transform = NULL;
	int* HP;
public:

	virtual void Render(HDC) = 0;
	virtual void setHp(int* hp) = 0;
};

