#pragma once

#include <Windows.h>

class CTransform;

class CEnemyRenderer
{
public:
	HBRUSH EnemyBrush1;
	HBRUSH EnemyBrush2;
	HPEN EnemyPen;

	CTransform *transform;

	CEnemyRenderer(CTransform *transform);
	~CEnemyRenderer();
	void render(HDC);
};

