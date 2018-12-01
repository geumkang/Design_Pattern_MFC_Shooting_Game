#pragma once

#include <Windows.h>

#define MAX_Hit_COLOR 4

class CTransform;

class CHitRenderer
{
	int* nHit;
public:

	COLORREF HitColor[MAX_Hit_COLOR];
	HFONT hHitFont;

	CTransform *transform;

	CHitRenderer(CTransform *transform);
	~CHitRenderer();
	void render(HDC);
	void setHit(int*);
};

