#pragma once

#include <windows.h>

#define MAX_COMBO_COLOR 4

class CTransform;

class CComboRenderer
{
	int* nCombo;
public:
	COLORREF ComboColor[MAX_COMBO_COLOR];
	HFONT hComboFont;

	CTransform *transform;

	CComboRenderer(CTransform *transform);
	~CComboRenderer();
	void render(HDC);
	void setCombo(int*);
};

