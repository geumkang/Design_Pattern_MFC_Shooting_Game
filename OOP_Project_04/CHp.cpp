#include "CHp.h"
#include "CTransform.h"
#include "CHpRenderer.h"
#include "CPlayerHpRenderer.h"
#include "CEnemyHpRenderer.h"

CHp::CHp(int X, int Y, int _User) : User(_User), MaxHp(300) {
	Hp = MaxHp;
	Hp = 200;
	this->transform = new CTransform(X, Y);
	if (User == CHP_PLAYER) {
		this->renderer = new CPlayerHpRenderer(transform);
		renderer->setHp(&Hp);
	} else if (User == CHP_ENEMY) {
		this->renderer = new CEnemyHpRenderer(transform);
		renderer->setHp(&Hp);
	}
/*
	NormalBrush = CreateSolidBrush(RGB(255,0,0));
	DangerBrush = CreateSolidBrush(RGB(180,225,45));
	BlankBrush = CreateSolidBrush(RGB(128,128,128));
	NullPen = (HPEN)GetStockObject(NULL_PEN);
	Mode = CHP_NORMAL;*/
}

CHp::~CHp() {
}

//////////////////////////////////////////////////

int CHp::GetMaxHp() {
	return MaxHp;
}

int CHp::GetHp() {
	return Hp;
}

void CHp::SetHp(int Hp) {
	this->Hp = Hp;
}

void CHp::MovHp(int Hp) {
	this->Hp += Hp;
}
//
//void CHp::SetMode(int Mode) {
//	this->Mode = Mode;
//}

/////////////////////////////////////////////////

void CHp::Update() {
}

void CHp::Render(HDC hdc) {
	this->renderer->render(hdc);
	/*HBRUSH OldBrush;
	HBRUSH OldPen = (HBRUSH)SelectObject(hdc,NullPen);
	int status = (int)((double)Hp/(double)MaxHp*250);
	if(Mode==CHP_NORMAL) {
		OldBrush = (HBRUSH)SelectObject(hdc,NormalBrush);
		if(User == CHP_PLAYER) Rectangle(hdc,X,Y,X+status,Y+15);
		if(User == CHP_ENEMY)  Rectangle(hdc,X+250-status,Y,X+250,Y+15);
		SelectObject(hdc,BlankBrush);
		if(User == CHP_PLAYER) Rectangle(hdc,X+status,Y,X+250,Y+15);
		if(User == CHP_ENEMY)  Rectangle(hdc,X,Y,X+250-status,Y+15);
		SelectObject(hdc,OldBrush);
	} else if(Mode==CHP_DANGER) {
		OldBrush = (HBRUSH)SelectObject(hdc,DangerBrush);
		if(User == CHP_PLAYER) Rectangle(hdc,X,Y,X+status,Y+15);
		if(User == CHP_ENEMY)  Rectangle(hdc,X+250-status,Y,X+250,Y+15);
		SelectObject(hdc,BlankBrush);
		if(User == CHP_PLAYER) Rectangle(hdc,X+status,Y,X+250,Y+15);
		if(User == CHP_ENEMY)  Rectangle(hdc,X,Y,X+250-status,Y+15);
		SelectObject(hdc,OldBrush);
	}
	SelectObject(hdc,OldPen);*/
}
