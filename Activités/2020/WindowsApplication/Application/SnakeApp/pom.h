#pragma once
#include <Windows.h>
class pom
{
	public:
		pom();

		void updateDrawingArea(RECT iWindowRect);
		void paint(HDC ihdc);
	private:
		bool mIsInit = false;
		int mCoorY;
		int mCoorX;
		int mRadius = 20;
		RECT mDrawingArea;
		HBRUSH mBrush;
};

