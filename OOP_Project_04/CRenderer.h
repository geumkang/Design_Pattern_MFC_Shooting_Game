#pragma once
#include <Windows.h>

class CRenderer
{
public:

	virtual void Render(HDC hdc) = 0;
};

