#include "Token.h"

Token::Token(): mPosX(0), mPosY(0)
{
	for (int i = 0; i < 8; i++)
	{
		int wRed = (i & 0x1) ? 255 : 0; // Le premier bit détermine si la composante rouge.
		int wGreen = (i & 0x2) ? 255 : 0; // Le deuxieme bit détermine si la composante verte.
		int wBlue = (i & 0x4) ? 255 : 0; // Le troisieme bit détermine si la composante bleue.
		mBrush[i] = CreateSolidBrush(RGB(wRed, wGreen, wBlue));
	}
}


void Token::drawTokenRed(HDC ihdc, RECT& iPaintArea)
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
		HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush[0]);

		for (int i = 0; i < 8; i++)
		{
			::SelectObject(ihdc, mBrush[i]);
			::FloodFill(ihdc, mPosX , mPosY, RGB(0, 0, 0));
		}
		::SelectObject(ihdc, wOldBrush);
	}

void Token::drawTokenBlue(HDC ihdc, RECT& iPaintArea)
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
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush[255,0,0]);

	for (int i = 0; i < 8; i++)
	{
		
		::SelectObject(ihdc, mBrush[i]);
		::FloodFill(ihdc, mPosX+i*10, mPosY, RGB(0,0,0));
	}
	::SelectObject(ihdc, wOldBrush);
}

