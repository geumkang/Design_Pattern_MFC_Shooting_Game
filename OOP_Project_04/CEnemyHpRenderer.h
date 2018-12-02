#pragma once
#include "CHpRenderer.h"
class CEnemyHpRenderer :
	public CHpRenderer
{
	HBRUSH NormalBrush, DangerBrush;
	HBRUSH BlankBrush;
	HPEN NullPen;
public:
	CEnemyHpRenderer(CTransform* transform);
	~CEnemyHpRenderer();

	virtual void Render(HDC hdc);
	virtual void setHp(int* hp);
};

