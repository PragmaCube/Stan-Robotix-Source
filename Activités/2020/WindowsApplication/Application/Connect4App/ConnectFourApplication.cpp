#include "ConnectFourApplication.h"

#include <string>

ConnectFourApplication::ConnectFourApplication() 
{
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

void ConnectFourApplication::onKeyDown(char iChar, short iDetail)
{
}


void ConnectFourApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void ConnectFourApplication::onMouseLeftClick(int iPosX, int iPosY)
{
	mBoardGame.AddBlueToken(iPosX);
}

void ConnectFourApplication::onMouseRightClick(int iPosX, int iPosY)
{
	mBoardGame.AddRedToken(iPosX);
}

void ConnectFourApplication::onTimer()
{
	IApplication::onTimer(); // Pour redessiner l'ecran
}

