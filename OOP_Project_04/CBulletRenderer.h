#pragma once
#include <Windows.h>
#include "CRenderer.h"

#define BULLET_WIDTH 5
#define BULLET_HEIGHT 10

class CTransform;

class CBulletRenderer : public CRenderer
{
public:
	
	bool* isAlive;

	CTransform* transform;

	HBRUSH hBrush;
	HBRUSH hEnemyBrush;
	HPEN hPen;
	BOOL bEnemy;


	CBulletRenderer(CTransform* transform);
	~CBulletRenderer();

	void Render(HDC hdc);
	void set_bullet_color(int r, int g, int b);
	void setAlive(bool* isAlive);
};

