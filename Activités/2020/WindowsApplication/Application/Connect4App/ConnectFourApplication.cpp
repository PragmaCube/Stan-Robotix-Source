#include "ConnectFourApplication.h"

#include <string>

ConnectFourApplication::ConnectFourApplication() : mPosX(0), mPosY(0)
{
		mLastClickType = eClickNone;	
}

 void ConnectFourApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Connect4";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);

	    mBoardGame.paint(ihdc, iPaintArea);
}

void ConnectFourApplication::onChar(char iChar, short iDetail)
{
	if ((iChar == 'N') || (iChar == 'n'))
	{
		mBoardGame.InitArray();
	}
}

/*void ConnectFourApplication::onKeyDown(char iChar, short iDetail)
{
}
*/

void ConnectFourApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{
	mPosX = iPosX;
	mPosY = iPosY;

	mLastClickType = eLeftDoubleClick;
}

void ConnectFourApplication::onMouseLeftClick(int iPosX, int iPosY)
{
	mLastClickType = eLeftClick;
	mToken.mColor = true;
}

void ConnectFourApplication::onMouseRightClick(int iPosX, int iPosY)
{
    mLastClickType = eRightClick;
	mToken.mColor = false;
}

/*
void ConnectFourApplication::drawHorizontalLines()
{
}

void ConnectFourApplication::drawVerticalLines()
{
}
*/

void ConnectFourApplication::onTimer()
{
	IApplication::onTimer(); // Pour redessiner l'ecran
}

