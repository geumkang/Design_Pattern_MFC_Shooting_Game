#pragma once

class CTransform {
	int X, Y;
	int Size;
public:
	CTransform();
	CTransform(int X, int Y);
	~CTransform();

	int getX();
	int getY();
	int getSize();
	void setX(int X);
	void setY(int Y);
	void setSize(int Size);
};

