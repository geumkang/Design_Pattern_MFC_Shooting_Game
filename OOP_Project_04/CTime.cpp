#include "CTime.h"

CTime::CTime() {
	nTime = 0;
	int color = 0;
	for(int i=0;i<MAX_TIME_COLOR;i++) {
		TimeColor[i] = RGB(255,color,color);
		color += 256/MAX_TIME_COLOR;
	}
	hTimeFont = CreateFont(30,0,0,0,1000,1,0,0,HANGEUL_CHARSET,0,0,0,VARIABLE_PITCH | FF_ROMAN,TEXT("¸¼Àº °íµñ"));
}

CTime::~CTime() {
	DeleteObject(hTimeFont);
}

void CTime::Update() {
}

void CTime::Render(HDC hdc) {
	TCHAR szTimeString[32];

	wsprintf(szTimeString,TEXT("%-5d Time!"),nTime);
	HFONT OldFont = (HFONT)SelectObject(hdc,hTimeFont);
	SetBkMode(hdc,TRANSPARENT);
	for(int i=MAX_TIME_COLOR-1;i>=0;i--) {
		SetTextColor(hdc,TimeColor[i]);
		TextOut(hdc,430+i,395+i,szTimeString,lstrlen(szTimeString));
	}
	SelectObject(hdc,OldFont);
}

void CTime::InitTime() {
	nTime = 0;
}

void CTime::IncTime() {
	nTime++;
}

int CTime::GetTime() {
	return nTime;
}
