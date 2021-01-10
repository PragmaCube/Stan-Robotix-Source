#include "DemoAppBall.h"

#include <stdlib.h>     
#include <time.h>       
#include <math.h>

DemoAppBall::DemoAppBall()
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

void DemoAppBall::setColor(COLORREF iRef)
{
	mColor = iRef;
	mBrush = CreateSolidBrush(iRef);

	mCoorX = 0.0;
	mCoorY = 0.0;
	mSpeedX = 0.0;
	mSpeedY = 0.0;

	mIsInit = false;
}

void DemoAppBall::updateDrawingArea(RECT iWindowRect)
{
	if (!mIsInit)
	{
		mCoorX = (double)(rand() % (iWindowRect.right - iWindowRect.left));
		mCoorY = (double)(rand() % (iWindowRect.bottom - iWindowRect.top));

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
	else if (mCoorX < 0)
	{
		mSpeedX = -mSpeedX;
	}

	if (mCoorY > iWindowRect.bottom)
	{
		mCoorY = (double)(iWindowRect.bottom);
		mSpeedY = -mSpeedY;
	}
	else if (mCoorY < 0)
	{
		mSpeedY = -mSpeedY;
	}
}

void DemoAppBall::applyTime()
{
	mCoorX += mSpeedX;
	mCoorY += mSpeedY;
}

void DemoAppBall::increaseSpeed()
{
	double wSpeed = sqrt(mSpeedX * mSpeedX + mSpeedY * mSpeedY);

	if (wSpeed < 40.0)
	{
		mSpeedX = mSpeedX * 1.1;
		mSpeedY = mSpeedY * 1.1;
	}
}

void DemoAppBall::decreaseSpeed()
{
	double wSpeed = sqrt(mSpeedX * mSpeedX + mSpeedY * mSpeedY);

	if (wSpeed > 1.0)
	{
		mSpeedX = mSpeedX / 1.1f;
		mSpeedY = mSpeedY / 1.1f;
	}
}

void DemoAppBall::paint(HDC ihdc)
{
	::SelectObject(ihdc, mBrush);

	::Ellipse(ihdc,
			  (int)(mCoorX) - mRadius,
		      (int)(mCoorY) - mRadius,
			  (int)(mCoorX) + mRadius,
			  (int)(mCoorY) + mRadius);
}

void DemoAppBall::increaseRadius()
{
	if (mRadius < 75)
	{
		mRadius += 10;
	}
}

void DemoAppBall::decreaseRadius()
{
	if (mRadius > 20)
	{
		mRadius -= 10;
	}
}




