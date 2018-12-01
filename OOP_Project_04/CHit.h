#ifndef _CHit_H_
#define _CHit_H_

#include <windows.h>

#define MAX_Hit_COLOR 4

class CHit {
	int nHit;

	COLORREF HitColor[MAX_Hit_COLOR];
	HFONT hHitFont;
public:
	CHit();
	~CHit();

	void Update();
	void Render(HDC);

	void InitHit();
	void IncHit();
	int GetHit();
};

#endif