#ifndef _CCOMBO_H_
#define _CCOMBO_H_

#include <windows.h>

#define MAX_COMBO_COLOR 4

class CCombo {
	int nCombo;

	COLORREF ComboColor[MAX_COMBO_COLOR];
	HFONT hComboFont;
public:
	CCombo();
	~CCombo();

	void Update();
	void Render(HDC);

	void InitCombo();
	void IncCombo();
	int GetCombo();
};

#endif