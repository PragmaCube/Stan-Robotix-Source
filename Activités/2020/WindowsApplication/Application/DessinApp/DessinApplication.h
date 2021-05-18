#pragma once
#include "../../Framework/IApplication.h"
#include <string>

#include <list>

class DessinApplication :
    public IApplication
{
private:
	class Point 
	{
	  public:
		  Point(int iX, int iY) : mX(iX), mY(iY) { }

		  int getX() { return mX; }
		  int getY() { return mY; }
		  
	  private:
		  Point() {}

		  int mX, mY;
	};

public:
	DessinApplication();

protected:
	void paint(HDC ihdc, RECT& iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);

	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY);
	void onMouseRightClick(int iPosX, int iPosY);

	void onMouseMove(int iPosX, int iPosY);

	void onTimer();

private:
	enum {eLeftDoubleClick, eLeftClick, eRightClick, eClickNone};
	int mLastClickType;

	int mPosX, mPosY;

	void drawHorizontalLines(HDC ihdc, RECT& iPaintArea);
	void drawConcentricCircle(HDC ihdc, RECT& iPaintArea);
	void drawStairs(HDC ihdc, RECT& iPaintArea);

	void drawFreeWriting(HDC ihdc, RECT& iPaintArea);

	std::wstring mTextToDraw;

	std::list<Point> mPointList;

	HBRUSH mBrush[8];

	HPEN mFreeWritingPen;


};

