#include "PingPongPad.h"

#include <stdlib.h>     
#include <time.h>       
#include <math.h>

PingPongPad::PingPongPad(int iId) : 
	mBallPtr(nullptr), 
	mCoorX(0),
	mCoorY(0),
	iChar1(0),
	iChar2(0),
	mIsInit(false),
	mBrush(0),
	mSpeed(0)
{
	COLORREF wColor = 0;

	if (iId == PingPongPad::eLeftPadId)
	{
		int mCoorX = 230; // Mauvaise intention. mCoorX est une variable locale a ta fonction.
		int mCoorY = 300; // Je pense que tu veux modifier les proprietes de l objet lui meme.
		char iChar1 = 'a';// Si oui enleve int, char.... comme cela. 
		char iChar2 = 'z';
		int mSpeed = 10;

		wColor = RGB(0, 0/*wGreen*/, 255 /*wBlue*/);
	}
	else
	{
		int mCoorX = 900;
		int mCoorY = 300;

		wColor = RGB(0, 255/*wGreen*/, 0 /*wBlue*/);
	}

	
	mBrush = CreateSolidBrush(wColor);
}

void PingPongPad::setBall(PingPongBall* iBall)
{
	mBallPtr = iBall;
}

int PingPongPad::getY()
{
	return mCoorY;
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