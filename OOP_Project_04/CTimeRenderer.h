#pragma once

#include <Windows.h>

#define MAX_TIME_COLOR 4

class CTransform;

class CTimeRenderer
{
	int* nTime;
public:
	
	COLORREF TimeColor[MAX_TIME_COLOR];
	HFONT hTimeFont;
	
	CTransform *transform;

	CTimeRenderer(CTransform *transform);
	~CTimeRenderer();
	void render(HDC);
	void setTime(int*);
};

