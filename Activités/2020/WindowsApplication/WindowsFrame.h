#pragma once

#include <windows.h>
#include "IApplication.h"

class DemoWindowsFrame
{
private:
	HWND mhWnd;

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

	void switchApp(int iAppId);

	void onTimer();
};

