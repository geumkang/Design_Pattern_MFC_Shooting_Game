#include "CHit.h"

CHit::CHit() {

	this->transform = new CTransform(430, 370);
	this->renderer = new CHitRenderer(this->transform);
	this->updater = new CHitUpdater(transform);
	this->renderer->setHit(&nHit);

	nHit = 0;
	/*int color = 0;
	for(int i=0;i<MAX_Hit_COLOR;i++) {
		HitColor[i] = RGB(255,color,color);
		color += 256/MAX_Hit_COLOR;
	}
	hHitFont = CreateFont(30,0,0,0,1000,1,0,0,HANGEUL_CHARSET,0,0,0,VARIABLE_PITCH | FF_ROMAN,TEXT("¸¼Àº °íµñ"));*/
}

CHit::~CHit() {
	/*DeleteObject(hHitFont);*/
}

void CHit::Update() {
}

void CHit::Render(HDC hdc) {
	this->renderer->Render(hdc);
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
