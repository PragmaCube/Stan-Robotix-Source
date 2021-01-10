#include "WindowsFrame.h"
#include "resource.h"
#include "DemoApplication.h"

DemoWindowsFrame::DemoWindowsFrame() : mhWnd(NULL)
{
	mCurrentApplication = new DemoApplication();
}

void DemoWindowsFrame::setHwnd(HWND ihwnd)
{
	mhWnd = ihwnd;

	mCurrentApplication->setHwnd(mhWnd);
	mCurrentApplication->setFrequencyTimer(1000/24);
}

void DemoWindowsFrame::onTimer()
{
	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->onTimer();
	}
}

void DemoWindowsFrame::paint(HDC ihdc, RECT& iPaintArea)
{
	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->paint(ihdc, iPaintArea);
	}
}

void DemoWindowsFrame::onChar(char iChar, short iDetail)
{
	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->onChar(iChar, iDetail);
	}
}

void DemoWindowsFrame::onKeyDown(char iChar, short iDetail)
{
	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->onKeyDown(iChar, iDetail);
	}
}

void DemoWindowsFrame::onMouseLeftDoubleClick(int iPosX, int iPosY)
{
	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->onMouseLeftDoubleClick(iPosX, iPosY);
	}
}

void DemoWindowsFrame::onMouseLeftClick(int iPosX, int iPosY)
{
	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->onMouseLeftClick(iPosX, iPosY);
	}
}

void DemoWindowsFrame::onMouseRightClick(int iPosX, int iPosY)
{
	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->onMouseRightClick(iPosX, iPosY);
	}
}

void DemoWindowsFrame::switchApp(int iAppId)
{
	switch (iAppId)
	{
	case ID_APPLICATION_DEMO:
		break;
	case ID_APPLICATION_BATTLESHIP:
		break;
	case ID_APPLICATION_SNAKE:
		break;
	};
}


