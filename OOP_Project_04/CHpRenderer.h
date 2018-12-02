#pragma once
#include <windows.h>
#include "CTransform.h"

#define MAX_HP 300

class CHpRenderer
{
protected:
	CTransform* transform = NULL;
	int* HP;
public:

	virtual void render(HDC) = 0;
	virtual void setHp(int* hp) = 0;
};

