#pragma once
#include "IApplication.h"
#include "DemoAppBall.h"
class DemoApplication : public IApplication
{
public:
	DemoApplication();

protected:
	void paint(HDC ihdc, RECT& iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);

	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY);
	void onMouseRightClick(int iPosX, int iPosY);

	void onTimer();

	DemoAppBall mDemoAppBall[8];

private:
	int mNbActiveBall;
	int mCircleRadius;
};
