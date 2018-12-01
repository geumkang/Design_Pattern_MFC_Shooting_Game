#pragma once

class CTransform;

class CComboUpdater
{
	CTransform* transform;
public:
	CComboUpdater(CTransform* transform);
	~CComboUpdater();
};

