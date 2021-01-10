#include "WindowsFrame.h"
#include "resource.h"

// Les applications en cours de developpement
#include "../Application\DemoApp\DemoApplication.h"
#include "../Application\SnakeApp\SnakeApplication.h"
#include "../Application\PacmanApp\PacmanApplication.h"
#include "../Application\Connect4App\ConnectFourApplication.h"
#include "../Application\PingpongApp\PingPongApplication.h"
#include "../Application\BattleshipApp\BattleshipApplication.h"
#include "../Application\DessinApp\DessinApplication.h"

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
	if (nullptr != mCurrentApplication)
	{
		delete mCurrentApplication;
		mCurrentApplication = nullptr;
	}

	switch (iAppId)
	{
	case ID_APPLICATION_DEMO:
		mCurrentApplication = new DemoApplication();
		break;
	case ID_APPLICATION_BATTLESHIP:
		mCurrentApplication = new BattleshipApplication();
		break;
	case ID_APPLICATION_SNAKE:
		mCurrentApplication = new SnakeApplication();
		break;
	case ID_APPLICATION_CONNECTFOUR:
		mCurrentApplication = new ConnectFourApplication();
		break;
	case ID_APPLICATION_PINGPONG:
		mCurrentApplication = new PingPongApplication();
		break;
	case ID_APPLICATION_DESSIN:
		mCurrentApplication = new DessinApplication();
		break;
	};

	if (nullptr != mCurrentApplication)
	{
		mCurrentApplication->setHwnd(mhWnd);
		mCurrentApplication->setFrequencyTimer(1000 / 24);
	}
}


