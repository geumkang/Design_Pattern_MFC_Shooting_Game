#pragma once

class CTransform;

class CHitUpdater
{
	CTransform* transform;
public:
	CHitUpdater(CTransform* transform);
	~CHitUpdater();
};

