#pragma once
#include <Windows.h>

class PingPongBall
{
public:
	PingPongBall();

	int getX();
	int getY();

	void updateDrawingArea(RECT iWindowRect);

	void increaseSpeed();
	void decreaseSpeed();

	void flipYSpeed();
	void flipXSpeed();

	void paint(HDC ihdc);

	void applyTime();

	void restart(RECT iWindowRect);

private:

	double mCoorX, mCoorY;
	double mSpeedX, mSpeedY;

	bool mIsInit;

	const int mRadius = 20;

	HBRUSH mBrush;
};
