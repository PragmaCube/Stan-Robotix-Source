
#include "PingPongBall.h"

#include <stdlib.h>     
#include <time.h>       
#include <math.h>

PingPongBall::PingPongBall()
{
	mColor = 0x00000000;

	mCoorX = 0.0;
	mCoorY = 0.0;
	mSpeedX = 0.0;
	mSpeedY = 0.0;

	mIsInit = false;

	mDrawingArea = { 0,0,0,0 };

	mBrush = 0;

	mRadius = 20;
}

int PingPongBall::getX()
{
	return mCoorY;
}

int PingPongBall::getY()
{
	return mCoorX;
}

void PingPongBall::setColor(COLORREF iRef)
{
	mColor = iRef;
	mBrush = CreateSolidBrush(iRef);

	mCoorX = 0.0;
	mCoorY = 0.0;
	mSpeedX = 0.0;
	mSpeedY = 0.0;

	mIsInit = false;
}

void PingPongBall::updateDrawingArea(RECT iWindowRect)
{
	if (!mIsInit)
	{
		mCoorX = iWindowRect.left + (double)(rand() % (iWindowRect.right - iWindowRect.left));
		mCoorY = iWindowRect.top + (double)(rand() % (iWindowRect.bottom - iWindowRect.top));

		mSpeedX = (double)(rand() % 5 - 10);
		mSpeedY = (double)(rand() % 5 - 10);

		mIsInit = true;
	}

	mDrawingArea = iWindowRect;

	if (mCoorX > iWindowRect.right)
	{
		mCoorX = (double)(iWindowRect.right);
		mSpeedX = -mSpeedX;
	}
	else if (mCoorX < iWindowRect.left)
	{
		mCoorX = (double)(iWindowRect.left);
		mSpeedX = -mSpeedX;
	}

	if (mCoorY > iWindowRect.bottom)
	{
		mCoorY = (double)(iWindowRect.bottom);
		mSpeedY = -mSpeedY;
	}
	else if (mCoorY < iWindowRect.top)
	{
		mCoorY = (double)(iWindowRect.top);
		mSpeedY = -mSpeedY;
	}
}

void PingPongBall::applyTime()
{
	mCoorX += mSpeedX;
	mCoorY += mSpeedY;
}

void PingPongBall::increaseSpeed()
{
	double wSpeed = sqrt(mSpeedX * mSpeedX + mSpeedY * mSpeedY);

	if (wSpeed < 40.0)
	{
		mSpeedX = mSpeedX * 1.1;
		mSpeedY = mSpeedY * 1.1;
	}
}

void PingPongBall::decreaseSpeed()
{
	double wSpeed = sqrt(mSpeedX * mSpeedX + mSpeedY * mSpeedY);

	if (wSpeed > 1.0)
	{
		mSpeedX = mSpeedX / 1.1f;
		mSpeedY = mSpeedY / 1.1f;
	}
}

void PingPongBall::paint(HDC ihdc)
{
	::SelectObject(ihdc, mBrush);

	::Ellipse(ihdc,
		(int)(mCoorX)-mRadius,
		(int)(mCoorY)-mRadius,
		(int)(mCoorX)+mRadius,
		(int)(mCoorY)+mRadius);
}

void PingPongBall::increaseRadius()
{
	if (mRadius < 75)
	{
		mRadius += 10;
	}
}

void PingPongBall::decreaseRadius()
{
	if (mRadius > 20)
	{
		mRadius -= 10;
	}
}

