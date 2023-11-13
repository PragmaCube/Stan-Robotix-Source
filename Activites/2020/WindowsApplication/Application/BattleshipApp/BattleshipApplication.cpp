#include "BattleshipApplication.h"

#include <string>

BattleshipApplication::BattleshipApplication() : mGameBoard()
{
	setFrequencyTimer(200000);
}

void BattleshipApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Battleship";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		(int)(DT_CENTER | DT_TOP));

	mGameBoard.drawGameBoard(ihdc, iPaintArea);
}

void BattleshipApplication::onChar(char iChar, short iDetail)
{
	//réinisialisation du jeu en appuyant sur n ou N
	if ((iChar == 'N') || (iChar == 'n'))
	{
		mGameBoard.reset();
	}
}

void BattleshipApplication::onKeyDown(char iChar, short iDetail)
{

}

void BattleshipApplication::onMouseMove(int iPosX, int iPosY)
{

}

void BattleshipApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void BattleshipApplication::onMouseLeftClick(int iPosX, int iPosY)
{
	mGameBoard.click(iPosX, iPosY); 
}

void BattleshipApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void BattleshipApplication::onTimer()
{

	IApplication::onTimer(); // Pour redessiner l'ecran
}