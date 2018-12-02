#include "CPlayerRenderer.h"
#include "CTransform.h"

CPlayerRenderer::CPlayerRenderer(CTransform* transform)
{
	this->transform = transform;
}

CPlayerRenderer::~CPlayerRenderer()
{

}

void CPlayerRenderer::Render(HDC hdc)
{
	//DrawPlayerBody(hdc);

	//DrawPlayer(hdc);

	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC, hPlayerBit);
	TransparentBlt(hdc, this->transform->getX(), this->transform->getY(), 
		this->transform->getSize(), this->transform->getSize(),
		hMemDC, 0, 0, 
		this->transform->getSize(), this->transform->getSize(),
		RGB(0, 255, 0));
	SelectObject(hMemDC, OldBit);
	DeleteDC(hMemDC);

	//Bullet->Render(hdc);
}

void CPlayerRenderer::setBitmap(HBITMAP hplayerBit)
{
	this->hPlayerBit = hplayerBit;
}

