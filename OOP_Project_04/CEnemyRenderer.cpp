#include "CEnemyRenderer.h"
#include "CTransform.h"


CEnemyRenderer::CEnemyRenderer(CTransform *transform)
{
	this->transform = transform;
	EnemyBrush1 = CreateSolidBrush(RGB(0, 0, 255));
	EnemyBrush2 = CreateSolidBrush(RGB(0, 0, 128));
	EnemyPen = (HPEN)GetStockObject(NULL_PEN);
}


CEnemyRenderer::~CEnemyRenderer()
{
	DeleteObject(EnemyBrush1);
	DeleteObject(EnemyBrush2);
	DeleteObject(EnemyPen);
}

void CEnemyRenderer::render(HDC hdc)
{
	HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, EnemyBrush1);
	HPEN OldPen = (HPEN)SelectObject(hdc, EnemyPen);
	Ellipse(hdc, this->transform->getX(), 
		this->transform->getY(), 
		this->transform->getX() + this->transform->getSize(), 
		this->transform->getY() + this->transform->getSize());
	SelectObject(hdc, EnemyBrush2);
	Ellipse(hdc, (int)(this->transform->getX() + this->transform->getSize() * 1.0 / 5),
		(int)(this->transform->getY() + this->transform->getSize() * 1.0 / 5),
		(int)(this->transform->getX() + this->transform->getSize() * 4.0 / 5),
		(int)(this->transform->getY() + this->transform->getSize() * 4.0 / 5));
	SelectObject(hdc, OldBrush);
	SelectObject(hdc, OldPen);
}
