#pragma once

#include <Windows.h>
#include "CRenderer.h"

class CTransform;

class CEnemyRenderer : public CRenderer
{
public:
	HBRUSH EnemyBrush1;
	HBRUSH EnemyBrush2;
	HPEN EnemyPen;

	CTransform *transform;

	CEnemyRenderer(CTransform *transform);
	~CEnemyRenderer();
	void Render(HDC);
};

