#pragma once

#include <Windows.h>
#include "CRenderer.h"
#define MAX_COMBO_COLOR 4

class CTransform;

class CComboRenderer : public CRenderer
{
	int* nCombo;
public:
	COLORREF ComboColor[MAX_COMBO_COLOR];
	HFONT hComboFont;

	CTransform *transform;

	CComboRenderer(CTransform *transform);
	~CComboRenderer();
	void Render(HDC);
	void setCombo(int*);
};

