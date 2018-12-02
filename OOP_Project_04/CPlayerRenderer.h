#pragma once

#include <Windows.h>

class CTransform;

class CPlayerRenderer
{
public:
	CTransform *transform;

	HBITMAP hPlayerBit;

	CPlayerRenderer(CTransform* transform);
	~CPlayerRenderer();

	void Render(HDC);
	void setBitmap(HBITMAP hplayerBit);
};

