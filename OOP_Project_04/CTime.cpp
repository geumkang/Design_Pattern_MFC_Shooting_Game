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
}