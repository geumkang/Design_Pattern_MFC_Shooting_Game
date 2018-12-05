#pragma once

#include "CUpdater.h"

class CTransform;

class CTimeUpdater : public CUpdater
{
	int* nTime;
	CTransform* transform;
public:
	CTimeUpdater(CTransform* transform);
	~CTimeUpdater();

	void Update();
	void Pause();
	void InitTime();
	void IncTime();
	int GetTime();
	void setTime(int *nTime);
};

