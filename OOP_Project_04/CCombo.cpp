#include "CCombo.h"
#include "CComboRenderer.h"
#include "CComboUpdater.h"
#include "CGameHost.h"

CCombo::CCombo() {

	this->transform = new CTransform(430, 420);
	this->renderer = new CComboRenderer(this->transform);
	this->updater = new CComboUpdater(transform);
	((CComboRenderer*)this->renderer)->setCombo(&nCombo);
	((CComboUpdater*)this->updater)->setCombo(&nCombo);
	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
	CGameHost::updaters.push_back(updater);

	nCombo = 0;
}

CCombo::~CCombo() {
	
}

void CCombo::Update() {
}

void CCombo::Render(HDC hdc) {
	this->renderer->Render(hdc);
}
