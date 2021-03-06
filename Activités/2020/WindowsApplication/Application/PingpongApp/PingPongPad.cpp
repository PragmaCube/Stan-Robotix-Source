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
	mSpeed(0)
{
	COLORREF wColor = 0;

	if (iId == PingPongPad::eLeftPadId)
	{
		mCoorX = 230; 
		mCoorY = 300;
		mKeyUp = 'q';
		mKeyDown = 'a';
	    mSpeed = 30;

		wColor = RGB(0, 0/*wGreen*/, 255 /*wBlue*/);

	}
	else
	{
		mCoorX = 900;
		mCoorY = 300;

		wColor = RGB(0, 255/*wGreen*/, 0 /*wBlue*/);
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

void PingPongPad::initialiser(RECT iWindowRect)
{
	mCoorYMax = iWindowRect.top + mHeight / 2;
	mCoorYMin = iWindowRect.bottom - mHeight / 2;
}

void PingPongPad::movePadUp()
{
	if (mCoorY > mCoorYMax)
	{
		mCoorY -= mSpeed;
	}
}

void PingPongPad::movePadDown()
{
	if (mCoorY < mCoorYMin)
	{
		mCoorY += mSpeed;
	}
}

