#pragma once
#include <Windows.h>

class IApplication
{
public:
	void setHwnd(HWND ihwnd) { mHwnd = ihwnd; }

	virtual void paint(HDC ihdc, RECT& iPaintArea) = 0;

	virtual void onChar(char iChar, short iDetail) = 0;
	virtual void onKeyDown(char iChar, short iDetail) = 0;

	virtual void onMouseLeftDoubleClick(int iPosX, int iPosY) = 0;
	virtual void onMouseLeftClick(int iPosX, int iPosY) = 0;
	virtual void onMouseRightClick(int iPosX, int iPosY) = 0;

	virtual void onTimer()
	{
		::InvalidateRect(mHwnd, nullptr, true);
	}

	void setFrequencyTimer(int iTimerinMs)
	{
		if (NULL != mHwnd)
		{
			SetTimer(mHwnd, 1 /* TimerEvent*/, iTimerinMs, nullptr);
		}
	}

protected:
	IApplication() : mHwnd(NULL) { }

private:
	HWND mHwnd;
};