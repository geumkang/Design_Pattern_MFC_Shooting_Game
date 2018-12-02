#include "CTimeUpdater.h"
#include "CTransform.h"

CTimeUpdater::CTimeUpdater(CTransform* transform)
{
	this->transform = transform;
}


CTimeUpdater::~CTimeUpdater()
{
}

void CTimeUpdater::Update()
{
	this->IncTime();
}

void CTimeUpdater::InitTime() {
	(*nTime) = 0;
}

void CTimeUpdater::IncTime() {
	(*nTime)++;
}

int CTimeUpdater::GetTime() {
	return *nTime;
}

void CTimeUpdater::setTime(int * nTime)
{
	this->nTime = nTime;
}
