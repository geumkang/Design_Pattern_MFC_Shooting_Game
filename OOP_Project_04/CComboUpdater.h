#pragma once
#include "CUpdater.h"
class CTransform;

class CComboUpdater : public CUpdater
{
	int* nCombo;
	int comboCount;
	CTransform* transform;
public:
	CComboUpdater(CTransform* transform);
	~CComboUpdater();
	void Update();
	void Pause();
	void setCombo(int* nCombo);
	void InitCombo();
	void IncCombo();
	int GetCombo();
	void decComboCount();
};
