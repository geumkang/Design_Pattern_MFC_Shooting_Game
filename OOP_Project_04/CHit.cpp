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
