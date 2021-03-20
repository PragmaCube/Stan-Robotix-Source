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
/*
void Token::setcolor(HDC ihdc, RECT& iPaintArea, HBRUSH & iBrush)
{
	::Ellipse(ihdc,
		(int)(150)-15,
		(int)(50)-15,
		(int)(150)+15,
		(int)(50)+15);

	if (mColor == true)
	{
		HGDIOBJ wOldBrush = ::SelectObject(ihdc, iBrush);


		::FloodFill(ihdc, 150, 50, RGB(0, 0, 0));

		::SelectObject(ihdc, mBlueBrush);
	}
	else
	{
		HGDIOBJ wOldBrush = ::SelectObject(ihdc, iBrush);


		::FloodFill(ihdc, 150, 50, RGB(0, 0, 0));

		::SelectObject(ihdc, mRedBrush);
	}

}*/

void Token::setType(int iColor)
{
	mType = iColor;
}
