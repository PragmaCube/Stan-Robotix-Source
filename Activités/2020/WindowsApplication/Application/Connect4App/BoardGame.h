#pragma once
#include <windows.h>
#include "Token.h"
class BoardGame
{
public:
	
	void paint(HDC ihdc, RECT& iPaintArea);
	void AddRedToken(int iPosX, int iPosY);
	void AddBlueToken(int iPosX, int iPosY);

	Token mRed;
	Token mBlue;
};

