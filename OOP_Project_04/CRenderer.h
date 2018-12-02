#pragma once
#include <Windows.h>

class CRenderer
{
public:
	CRenderer();
	~CRenderer();

	virtual void Render(HDC hdc) = 0;
};

