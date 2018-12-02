#pragma once

#include <Windows.h>
#include "CRenderer.h"

class CTransform;

class CPlayerRenderer : public CRenderer
{
public:
	CTransform *transform;

	HBITMAP hPlayerBit;

	CPlayerRenderer(CTransform* transform);
	~CPlayerRenderer();

	void Render(HDC);
	void setBitmap(HBITMAP hplayerBit);
};

