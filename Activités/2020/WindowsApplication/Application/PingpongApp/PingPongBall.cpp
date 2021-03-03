#include "PingPongBall.h"

#include <stdlib.h>     
#include <time.h>       
#include <math.h>

PingPongBall::PingPongBall() : 
	mCoorX(0.0),
    mCoorY(0.0),
    mSpeedX(0.0),
    mSpeedY(0.0),
	mIsInit(false),
	mBrush(0)
{
	int wRed   = (1 & 0x1) ? 255 : 0; // Le premier bit détermine si la composante rouge.
	int wGreen = (1 & 0x2) ? 255 : 0; // Le deuxieme bit détermine si la composante verte.
	int wBlue  = (1 & 0x4) ? 255 : 0; // Le troisieme bit détermine si la composante bleue.
	COLORREF wColor = RGB(wRed, wGreen, wBlue);
	mBrush = CreateSolidBrush(wColor);
}

int PingPongBall::getX()
{
	return mCoorX;
}

int PingPongBall::getY()
{
	return mCoorY;
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
}

void PingPongBall::flipXSpeed()
{
	mSpeedX = -mSpeedX;
}

void PingPongBall::flipYSpeed()
{
	mSpeedY = -mSpeedY;
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
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush);

	::Ellipse(ihdc,
		(int)(mCoorX)-mRadius,
		(int)(mCoorY)-mRadius,
		(int)(mCoorX)+mRadius,
		(int)(mCoorY)+mRadius);

	::SelectObject(ihdc, wOldBrush);
}
