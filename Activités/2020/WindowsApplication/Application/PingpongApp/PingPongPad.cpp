#include "PingPongPad.h"

#include <stdlib.h>     
#include <time.h>       
#include <math.h>

PingPongPad::PingPongPad()
{
}



void PingPongPad::setAsLeft(HDC ihdc, RECT& iPaintArea)
{
	int mCoorX= 230;
	int mCoorY = 300;
	char iChar1 = 'a';
	char iChar2 = 'z';
	int mSpeed = 10;
}

void PingPongPad::setAsRight(HDC ihdc, RECT& iPaintArea)
{
	int mCoorX = 900;
	int mCoorY = 300;
}


void PingPongPad::paint(HDC ihdc, RECT& iPaintArea)
{

	::SelectObject(ihdc, mBrush);
	RECT wPadRect;
	wPadRect.left = mCoorX - mWidth / 2,
		wPadRect.top = mCoorY - mHeight / 2,
		wPadRect.right = mCoorX + mWidth / 2,
		wPadRect.bottom = mCoorY + mHeight / 2;


	::Rectangle(
		ihdc,
		wPadRect.left,
		wPadRect.top,
		wPadRect.right,
		wPadRect.bottom);
}
void PingPongPad::moovePad(char iChar)
{
	if (iChar == iChar1)
	{
		mCoorY -= mSpeed;
	}
	else if (iChar == iChar2)
	{
		mCoorY += mSpeed;
	}
}