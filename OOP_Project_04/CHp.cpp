#include "CHp.h"
#include "CTransform.h"
#include "CHpRenderer.h"
#include "CPlayerHpRenderer.h"
#include "CEnemyHpRenderer.h"
#include "CGameHost.h"

CHp::CHp(int X, int Y, int _User) : User(_User), MaxHp(300) {
	Hp = MaxHp;
	Hp = 200;
	this->transform = new CTransform(X, Y);
	if (User == CHP_PLAYER) {
		this->renderer = new CPlayerHpRenderer(transform);
		((CPlayerHpRenderer*)renderer)->setHp(&Hp);
	} else if (User == CHP_ENEMY) {
		this->renderer = new CEnemyHpRenderer(transform);
		((CEnemyHpRenderer*)renderer)->setHp(&Hp);
	}

	//update static vectors in CGameHost
	CGameHost::renderers.push_back(renderer);
}

CHp::~CHp() {
}

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

void CHp::Update() {
}

void CHp::Render(HDC hdc) {
	this->renderer->Render(hdc);
}
