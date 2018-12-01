#include "CHit.h"

CHit::CHit() {
	nHit = 0;
	int color = 0;
	for(int i=0;i<MAX_Hit_COLOR;i++) {
		HitColor[i] = RGB(255,color,color);
		color += 256/MAX_Hit_COLOR;
	}
	hHitFont = CreateFont(30,0,0,0,1000,1,0,0,HANGEUL_CHARSET,0,0,0,VARIABLE_PITCH | FF_ROMAN,TEXT("¸¼Àº °íµñ"));
}

CHit::~CHit() {
	DeleteObject(hHitFont);
}

void CHit::Update() {
}

void CHit::Render(HDC hdc) {
	TCHAR szHitString[32];

	wsprintf(szHitString,TEXT("%-3d Hit!"),nHit);
	HFONT OldFont = (HFONT)SelectObject(hdc,hHitFont);
	SetBkMode(hdc,TRANSPARENT);
	for(int i=MAX_Hit_COLOR-1;i>=0;i--) {
		SetTextColor(hdc,HitColor[i]);
		TextOut(hdc,430+i,370+i,szHitString,lstrlen(szHitString));
	}
	SelectObject(hdc,OldFont);
}

void CHit::InitHit() {
	nHit = 0;
}

void CHit::IncHit() {
	nHit++;
}

int CHit::GetHit() {
	return nHit;
}
