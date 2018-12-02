#include "CGameObject.h"

CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
	delete(transform);
}

