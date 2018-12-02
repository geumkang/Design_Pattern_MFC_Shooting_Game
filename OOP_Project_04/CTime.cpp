#include "CTime.h"
#include "CGameHost.h"
#include "CTimeRenderer.h"
#include "CTimeUpdater.h"

CTime::CTime() {

	this->transform = new CTransform(430, 395);
	this->renderer = new CTimeRenderer(this->transform);
	this->updater = new CTimeUpdater(transform);
	nTime = 0;
	((CTimeRenderer*)this->renderer)->setTime(&nTime);
	((CTimeUpdater*)this->updater)->setTime(&nTime);

	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
	CGameHost::updaters.push_back(updater);
}

CTime::~CTime() {
}

void CTime::Update() {
}

void CTime::Render(HDC hdc) {
	this->renderer->Render(hdc);
	/*TCHAR szTimeString[32];

	wsprintf(szTimeString,TEXT("%-5d Time!"),nTime);
	HFONT OldFont = (HFONT)SelectObject(hdc,hTimeFont);
	SetBkMode(hdc,TRANSPARENT);
	for(int i=MAX_TIME_COLOR-1;i>=0;i--) {
		SetTextColor(hdc,TimeColor[i]);
		TextOut(hdc,430+i,395+i,szTimeString,lstrlen(szTimeString));
	}
	SelectObject(hdc,OldFont);*/
}

//void CTime::InitTime() {
//	nTime = 0;
//}
//
//void CTime::IncTime() {
//	nTime++;
//}
//
//int CTime::GetTime() {
//	return nTime;
//}
