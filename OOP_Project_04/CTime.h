#ifndef _CTime_H_
#define _CTime_H_

#include <windows.h>

#define MAX_TIME_COLOR 4

class CTime {
	int nTime;

	COLORREF TimeColor[MAX_TIME_COLOR];
	HFONT hTimeFont;
public:
	CTime();
	~CTime();

	void Update();
	void Render(HDC);

	void InitTime();
	void IncTime();
	int GetTime();
};

#endif