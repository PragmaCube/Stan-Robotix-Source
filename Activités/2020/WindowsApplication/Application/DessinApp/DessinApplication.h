#pragma once
#include "../../Framework/IApplication.h"
#include <string>

class DessinApplication :
    public IApplication
{
public:
	DessinApplication();

protected:
	void paint(HDC ihdc, RECT& iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);

	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY);
	void onMouseRightClick(int iPosX, int iPosY);

	void onTimer();

private:
	enum {eLeftDoubleClick, eLeftClick, eRightClick, eClickNone};
	int mLastClickType;

	int mPosX, mPosY;

	void drawHorizontalLines(HDC ihdc, RECT& iPaintArea);
	void drawConcentricCircle(HDC ihdc, RECT& iPaintArea);
	void drawStairs(HDC ihdc, RECT& iPaintArea);

	std::wstring mTextToDraw;

	HBRUSH mBrush[8];
};

