#include "CHitRenderer.h"
#include "CTransform.h"


CHitRenderer::CHitRenderer(CTransform *transform)
{
	this->transform = transform;
	int color = 0;
	for (int i = 0; i < MAX_Hit_COLOR; i++) {
		HitColor[i] = RGB(255, color, color);
		color += 256 / MAX_Hit_COLOR;
	}
	hHitFont = CreateFont(30, 0, 0, 0, 1000, 1, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("¸¼Àº °íµñ"));
}

CHitRenderer::~CHitRenderer()
{
	DeleteObject(hHitFont);
}

void CHitRenderer::render(HDC hdc)
{
	TCHAR szHitString[32];

	wsprintf(szHitString, TEXT("%-3d Hit!"), *nHit);
	HFONT OldFont = (HFONT)SelectObject(hdc, hHitFont);
	SetBkMode(hdc, TRANSPARENT);
	for (int i = MAX_Hit_COLOR - 1; i >= 0; i--) {
		SetTextColor(hdc, HitColor[i]);
		TextOut(hdc, transform->getX() + i, transform->getY() + i, szHitString, lstrlen(szHitString));
	}
	SelectObject(hdc, OldFont);
}

void CHitRenderer::setHit(int* nHit)
{
	this->nHit = nHit;
}
