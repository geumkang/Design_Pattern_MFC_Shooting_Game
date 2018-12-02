#pragma once
#include "CHpRenderer.h"

class CPlayerHpRenderer :
	public CHpRenderer
{
	HBRUSH NormalBrush, DangerBrush;
	HBRUSH BlankBrush;
	HPEN NullPen;

public:
	CPlayerHpRenderer(CTransform* transform);
	~CPlayerHpRenderer();

	virtual void Render(HDC hdc);
	virtual void setHp(int* hp);
};

