#include "Token.h"

Token::Token(): mPosX(0), mPosY(0)
{
	mRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	mBlueBrush = CreateSolidBrush(RGB(0,0,255));
}

void Token::draw(HDC ihdc)
{	
	int wRadius = 30;
	while (wRadius > 15)
	{
		::Ellipse(ihdc,
			(int)(mPosX)-wRadius,
			(int)(mPosY)-wRadius,
			(int)(mPosX)+wRadius,
			(int)(mPosY)+wRadius);

		wRadius -= 5;
	}

	HGDIOBJ wOldBrush;
	if (mType == eRed)
	{
	  	wOldBrush = ::SelectObject(ihdc, mRedBrush);
	}
	else
	{
		wOldBrush = ::SelectObject(ihdc, mBlueBrush);
	}
		
	::FloodFill(ihdc, mPosX, mPosY, RGB(0, 0, 0));

	::SelectObject(ihdc, wOldBrush);
}

void Token::setPosition(int iPosX, int iPosY)
{
	mPosX = iPosX;
	mPosY = iPosY;
}

void Token::setType(int iColor)
{
	mType = iColor;
}
