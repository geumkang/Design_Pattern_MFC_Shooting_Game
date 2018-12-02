#include "CCombo.h"

CCombo::CCombo() {

	this->transform = new CTransform(430, 420);
	this->renderer = new CHitRenderer(this->transform);
	this->updater = new CHitUpdater(transform);
	this->renderer->setHit(&nCombo);

	nCombo = 0;
}

CCombo::~CCombo() {
	
}

void CCombo::Update() {
}

void CCombo::Render(HDC hdc) {
	this->renderer->Render(hdc);
}

void CCombo::InitCombo() {
	nCombo = 0;
}

void CCombo::IncCombo() {
	nCombo++;
}

int CCombo::GetCombo() {
	return nCombo;
}
