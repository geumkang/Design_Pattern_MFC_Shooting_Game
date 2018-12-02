#pragma once

#include "CTransform.h"
#include "CRenderer.h"
#include "CUpdater.h"

class CGameObject
{
public:
	CTransform *transform;
	CRenderer *renderer;
	CUpdater *updater;

	CGameObject();
	virtual ~CGameObject();
};

