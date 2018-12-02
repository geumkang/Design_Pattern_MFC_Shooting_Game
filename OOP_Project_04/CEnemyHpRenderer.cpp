#include "CEnemyHpRenderer.h"



CEnemyHpRenderer::CEnemyHpRenderer(CTransform* transform)
{
	this->transform = transform;
	NormalBrush = CreateSolidBrush(RGB(255, 0, 0));
	DangerBrush = CreateSolidBrush(RGB(180, 225, 45));
	BlankBrush = CreateSolidBrush(RGB(128, 128, 128));
	NullPen = (HPEN)GetStockObject(NULL_PEN);
}


CEnemyHpRenderer::~CEnemyHpRenderer()
{
}

void CEnemyHpRenderer::render(HDC hdc)
{
	HBRUSH OldBrush;
	HBRUSH OldPen = (HBRUSH)SelectObject(hdc, NullPen);
	int status = (int)((double)*HP / (double)MAX_HP * 250);

	OldBrush = (HBRUSH)SelectObject(hdc, NormalBrush);
	Rectangle(hdc, transform->getX() + 250 - status, transform->getY(), transform->getX() + 250, transform->getY() + 15);
	SelectObject(hdc, BlankBrush);
	Rectangle(hdc, transform->getX(), transform->getY(), transform->getX() + 250 - status, transform->getY() + 15);
	SelectObject(hdc, OldBrush);

	SelectObject(hdc, OldPen);
}

void CEnemyHpRenderer::setHp(int* hp)
{
	this->HP = hp;
}
