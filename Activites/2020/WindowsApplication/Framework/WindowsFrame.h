#pragma once

#include <windows.h>
#include "IApplication.h"

class DemoWindowsFrame
{
public :
	static const int DEMO_WINDOWS_SIZE_WIDTH = 800;
	static const int DEMO_WINDOWS_SIZE_HEIGHT = 600;
	static const int DEMO_WINDOWS_SIZE_MARGIN_WIDTH = 16;
	static const int DEMO_WINDOWS_SIZE_MARGIN_HEIGHT = 59;

private:
	HWND mhWnd;

	HBRUSH mWhiteBrush, mLightGrayBrush;
	HPEN   mBlackBrush;

	IApplication* mCurrentApplication;

public:
	DemoWindowsFrame();

	void setHwnd(HWND ihwnd);

	void paint(HDC ihdc, RECT & iPaintArea);

	void onChar(char iChar, short iDetail);
	void onKeyDown(char iChar, short iDetail);

	void onMouseLeftDoubleClick(int iPosX, int iPosY);
	void onMouseLeftClick(int iPosX, int iPosY); 
	void onMouseRightClick(int iPosX, int iPosY);

	void onMouseMove(int iPosX, int iPosY);

	void switchApp(int iAppId);

	void onTimer();
};

