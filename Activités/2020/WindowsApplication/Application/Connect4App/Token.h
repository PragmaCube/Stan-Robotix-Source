#pragma once
#include <windows.h>



class Token
{
public:
	int mPosX, mPosY;

	Token();
	void drawTokenRed(HDC ihdc, RECT& iPaintArea);
	void drawTokenBlue(HDC ihdc, RECT& iPaintArea);


	
	HBRUSH mRedBrush, mBlueBrush;

	
};

