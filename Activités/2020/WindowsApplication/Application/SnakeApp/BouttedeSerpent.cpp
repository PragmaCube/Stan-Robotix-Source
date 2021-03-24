
#include "BoutteDeSerpent.h"
#include <stdlib.h>     
#include <time.h>       
#include <math.h>
#include <string>

BoutteDeSerpent::BoutteDeSerpent()
{

	COLORREF wColor = RGB(255, 0, 0);
	mBrush = CreateSolidBrush(wColor);

}

void BoutteDeSerpent::updateDrawingArea(RECT iWindowRect)
{

	if (!mIsInit)
	{
		mCoorX = iWindowRect.left + (double)(rand() % (iWindowRect.right - iWindowRect.left));
		mCoorY = iWindowRect.top + (double)(rand() % (iWindowRect.bottom - iWindowRect.top));
		mSpeedX = (double)(rand() % 5 - 10);
		mSpeedY = (double)(rand() % 5 - 10);

		mIsInit = true;
	}
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

void BoutteDeSerpent::paint(HDC ihdc) {
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush);



	::Ellipse(ihdc,
		(int)(mCoorX)-mRadius,
		(int)(mCoorY)-mRadius,
		(int)(mCoorX)+mRadius,
		(int)(mCoorY)+mRadius);



	::SelectObject(ihdc, wOldBrush);

}