#include "CTimeRenderer.h"
#include "CTransform.h"


CTimeRenderer::CTimeRenderer(CTransform *transform)
{
	this->transform = transform;
	int color = 0;
	for (int i = 0; i < MAX_TIME_COLOR; i++) {
		TimeColor[i] = RGB(255, color, color);
		color += 256 / MAX_TIME_COLOR;
	}
	hTimeFont = CreateFont(30, 0, 0, 0, 1000, 1, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("¸¼Àº °íµñ"));
}


CTimeRenderer::~CTimeRenderer()
{
	DeleteObject(hTimeFont);
}

void CTimeRenderer::Render(HDC hdc)
{
	TCHAR szTimeString[32];

	wsprintf(szTimeString, TEXT("%-5d Time!"), *nTime);
	HFONT OldFont = (HFONT)SelectObject(hdc, hTimeFont);
	SetBkMode(hdc, TRANSPARENT);
	for (int i = MAX_TIME_COLOR - 1; i >= 0; i--) {
		SetTextColor(hdc, TimeColor[i]);
		TextOut(hdc, transform->getX() + i, transform->getY() + i, szTimeString, lstrlen(szTimeString));
	}
	SelectObject(hdc, OldFont);
}

void CTimeRenderer::setTime(int* nTime)
{
	this->nTime = nTime;
}
