#pragma once

#include "CUpdater.h"
class CTransform;

class CHitUpdater : public CUpdater
{
	CTransform* transform;
public:
	CHitUpdater(CTransform* transform);
	~CHitUpdater();
	void Update();
};

