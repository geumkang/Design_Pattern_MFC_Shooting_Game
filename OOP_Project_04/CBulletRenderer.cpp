#include "CBulletRenderer.h"
#include "CTransform.h"

#define PLAYER_BULLET_COLOR RGB(255,255,0)

CBulletRenderer::CBulletRenderer(CTransform* transform)
{
	this->transform = transform;
	hBrush = CreateSolidBrush(PLAYER_BULLET_COLOR);
	hPen = (HPEN)GetStockObject(NULL_PEN);
}


CBulletRenderer::~CBulletRenderer()
{
	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void CBulletRenderer::render(HDC hdc)
{
	HBRUSH OldBrush;
	if (bEnemy) OldBrush = (HBRUSH)SelectObject(hdc, hEnemyBrush);
	else OldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	HPEN OldPen = (HPEN)SelectObject(hdc, hPen);
	Rectangle(hdc, transform->getX(), transform->getY(), 
		transform->getX() + BULLET_WIDTH, transform->getY() + BULLET_HEIGHT);
	SelectObject(hdc, OldPen);
	SelectObject(hdc, OldBrush);
}

void CBulletRenderer::set_bullet_color(int r, int g, int b)
{
	hBrush = CreateSolidBrush(RGB(r, g, b));
}
