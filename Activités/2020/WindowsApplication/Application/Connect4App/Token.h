#pragma once
#include <windows.h>



class Token
{
public:

	Token();
	void drawTokenRed(HDC ihdc, RECT& iPaintArea);
	void drawTokenBlue(HDC ihdc, RECT& iPaintArea);
	void drawToken(HDC ihdc, RECT& iPaintArea, HBRUSH & iBrush);
	void setPosition(int iPosX, int iPosY);
	void color(HDC ihdc, RECT& iPaintArea);

	HBRUSH mRedBrush, mBlueBrush;
	bool mColor;
private:

	int mPosX, mPosY;
	
	bool mPos;
	

	
};

