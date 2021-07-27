#include <windows.h>

#pragma once
class PacmanGameEngine
{
public:
	void setPacmanPos(int iX, int iY);
	POINT & getPacmanPos();

private:
	POINT mPacmanPos;
};

