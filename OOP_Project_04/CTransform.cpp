#include "CTransform.h"

CTransform::CTransform() {
	int X = -1;
	int Y = -1;
}

CTransform::CTransform(int X, int Y) :X(X), Y(Y) {}

CTransform::~CTransform() {}

int CTransform::getX()
{
	return X;
}

int CTransform::getY()
{
	return Y;
}

int CTransform::getSize()
{
	return Size;
}

void CTransform::setX(int X)
{
	CTransform::X = X;
}

void CTransform::setY(int Y)
{
	CTransform::Y = Y;
}

void CTransform::setSize(int Size)
{
	this->Size = Size;
}


