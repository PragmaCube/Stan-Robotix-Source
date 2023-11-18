#pragma once
#include <Windows.h>

class DemoAppBall
{
public:
	DemoAppBall();

	void setColor(COLORREF iRef);
	void updateDrawingArea(RECT iWindowRect);

	void increaseSpeed();
	void decreaseSpeed();

	void applyTime();

	void paint(HDC ihdc);

	void increaseRadius();
	void decreaseRadius();


private:
	double mCoorX, mCoorY;
	double mSpeedX, mSpeedY;

	bool mIsInit;

	int mRadius;

	RECT mDrawingArea;

	COLORREF mColor;
	HBRUSH mBrush;
};

