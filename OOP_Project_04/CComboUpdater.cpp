#include "CComboUpdater.h"
#include "CTransform.h"

CComboUpdater::CComboUpdater(CTransform* transform)
{
	this->transform = transform;
	comboCount = 0;
}


CComboUpdater::~CComboUpdater()
{
}

void CComboUpdater::Update()
{
	if (comboCount < 0) {
		(*nCombo) = 0;
	}
	comboCount--;
}

void CComboUpdater::Pause()
{
}

void CComboUpdater::setCombo(int *nCombo)
{
	this->nCombo = nCombo;
}

void CComboUpdater::InitCombo() {
	(*nCombo) = 0;
}

void CComboUpdater::IncCombo() {
	if (comboCount > 0) (*nCombo)++;
	comboCount = 40;
}

int CComboUpdater::GetCombo() {
	return *nCombo;
}

void CComboUpdater::decComboCount()
{
	comboCount--;
}

