#include "PingPongPad.h"

#include <stdlib.h>     
#include <time.h>       
#include <math.h>

PingPongPad::PingPongPad(int iId) :
	mBallPtr(nullptr), 
	mCoorX(0),
	mCoorY(0),
	mKeyUp(0),
	mKeyDown(0),
	mIsInit(false),
	mBrush(0),
	mSpeed(0),
	mCoorXMin(0),
	mCoorXMax(0),
	mCoorYMin(0),
	mCoorYMax(0),
	mCoorYPadMax(0),
	mCoorYPadMin(0)
{
	COLORREF wColor = 0;

	if (iId == PingPongPad::eLeftPadId)
	{
		mCoorX = mCoorXMin + 230; 
		mCoorY = mCoorYMin + 300;
		mKeyUp = 'q';
		mKeyDown = 'a';
	    mSpeed = 30;

		wColor = RGB(0/*Red*/, 0/*wGreen*/, 255 /*wBlue*/);
	}
	else
	{
		mCoorX = 900;
		mCoorY = mCoorYMin + 300;

		wColor = RGB(0/*Red*/, 255/*wGreen*/, 0 /*wBlue*/);
	}
	
	mBrush = CreateSolidBrush(wColor);
}

void PingPongPad::UpdatePosition()
{
	if (mBallPtr != nullptr)
	{
		mCoorY = mBallPtr->getY();
	}
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
	wPadRect.left = mCoorX - mWidth / 2;
	wPadRect.top = mCoorY - mHeight / 2;
	wPadRect.right = mCoorX + mWidth / 2;
	wPadRect.bottom = mCoorY + mHeight / 2;

	::Rectangle(
		ihdc,
		wPadRect.left,
		wPadRect.top,
		wPadRect.right,
		wPadRect.bottom);
}

void PingPongPad::initialiser(RECT iWindowRect)
{
	mCoorYPadMax = iWindowRect.top + mHeight / 2;
	mCoorYPadMin = iWindowRect.bottom - mHeight / 2;
	mCoorYMin = iWindowRect.bottom;
	mCoorYMax = iWindowRect.top;
	mCoorXMin = iWindowRect.left;
	mCoorXMax = iWindowRect.right;
}

void PingPongPad::movePadUp()
{
	if (mCoorY > mCoorYPadMax)
	{
		mCoorY -= mSpeed;
	}
}

void PingPongPad::movePadDown()
{
	if (mCoorY < mCoorYPadMin)
	{
		mCoorY += mSpeed;
	}
}

