#include "CHit.h"
#include "CGameHost.h"
#include "CHitRenderer.h"
#include "CHitUpdater.h"

CHit::CHit() {

	this->transform = new CTransform(430, 370);
	this->renderer = new CHitRenderer(this->transform);
	this->updater = new CHitUpdater(transform);
	((CHitRenderer*)this->renderer)->setHit(&nHit);

	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
	CGameHost::updaters.push_back(updater);

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
