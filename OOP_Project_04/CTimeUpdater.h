#pragma once

class CTransform;

class CTimeUpdater
{
	CTransform* transform;
public:
	CTimeUpdater(CTransform* transform);
	~CTimeUpdater();
};

