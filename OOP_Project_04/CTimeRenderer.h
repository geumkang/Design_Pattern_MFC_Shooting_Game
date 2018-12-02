#pragma once
#include "CRenderer.h"
#include <Windows.h>

#define MAX_TIME_COLOR 4

class CTransform;

class CTimeRenderer : public CRenderer
{
	int* nTime;
public:
	
	COLORREF TimeColor[MAX_TIME_COLOR];
	HFONT hTimeFont;
	
	CTransform *transform;

	CTimeRenderer(CTransform *transform);
	~CTimeRenderer();
	void Render(HDC);
	void setTime(int*);
};

