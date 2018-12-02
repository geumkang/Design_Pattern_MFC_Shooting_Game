#pragma once

#include "CRenderer.h"
#include <Windows.h>

#define MAX_Hit_COLOR 4

class CTransform;

class CHitRenderer : public CRenderer
{
	int* nHit;
public:

	COLORREF HitColor[MAX_Hit_COLOR];
	HFONT hHitFont;

	CTransform *transform;

	CHitRenderer(CTransform *transform);
	~CHitRenderer();
	void Render(HDC);
	void setHit(int*);
};

