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
	if ((iChar == 'n') || (iChar == 'N'))
	{
		mBoardGame.resetGame();
	}
}

void ConnectFourApplication::onKeyDown(char iChar, short iDetail)
{

}

void ConnectFourApplication::onMouseMove(int iPosX, int iPosY)
{

}

void ConnectFourApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void ConnectFourApplication::onMouseLeftClick(int iPosX, int iPosY)
{ 
	
}

void ConnectFourApplication::onMouseRightClick(int iPosX, int iPosY)
{ 

}

void ConnectFourApplication::onTimer()
{
	IApplication::onTimer(); // Pour redessiner l'ecran
}

