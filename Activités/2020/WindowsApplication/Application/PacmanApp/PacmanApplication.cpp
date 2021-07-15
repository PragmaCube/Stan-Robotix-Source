#include "PacmanApplication.h"

#include <string>

PacmanApplication::PacmanApplication()
{
	mPacmanGameBorad.initializeMap();
}

void PacmanApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Pacman";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);


	mPacmanGameBorad.drawMap(ihdc, iPaintArea);

	mBlinky.initialise(iPaintArea, eBlinky, &mPacmanGameBorad, &mPacman);
	
	/*mPinky.initialise(iPaintArea, ePinky);
	mInky.initialise(iPaintArea, eInky);
	mClyde.initialise(iPaintArea, eClyde);*/

	mBlinky.paint(ihdc);
	
	/* Pas besoin d'eux pour le moment
	mPinky.paint(ihdc);
	mInky.paint(ihdc);
	mClyde.paint(ihdc);*/

	mPacman.initialise(iPaintArea); // initialiser les valeurs de certaines constantes
	mPacman.paint(ihdc);
}

void PacmanApplication::onChar(char iChar, short iDetail)
{
	switch (iChar)
	{
	case 'a':
	case 'A':
		mNextDir = 'l';
		break;
	case 'w':
	case 'W':
		mNextDir = 'u';
		break;
	case 'd':
	case 'D':
		mNextDir = 'r';
		break;
	case 's':
	case 'S':
		mNextDir = 'd';
		break;
	}
}

void PacmanApplication::onKeyDown(char iChar, short iDetail)
{

}

void PacmanApplication::onMouseMove(int iPosX, int iPosY)
{

}

void PacmanApplication::onMouseLeftDoubleClick(int iPosX, int iPosY)
{

}

void PacmanApplication::onMouseLeftClick(int iPosX, int iPosY)
{
	//160 59      975 540
}

void PacmanApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void PacmanApplication::onTimer()
{
	mBlinky.move();

	if (mNextDir == 'l')
	{
		mPacman.movePacmanLeft();
		/*mBlinky.moveMonsterLeft(1);
		mPinky.moveMonsterLeft(2);
		mInky.moveMonsterLeft(3);
		mClyde.moveMonsterLeft(4);*/
	}
	else if (mNextDir == 'u')
	{
		mPacman.movePacmanUp();
		/*mBlinky.moveMonsterUp(1);
		mPinky.moveMonsterUp(2);
		mInky.moveMonsterUp(3);
		mClyde.moveMonsterUp(4);*/
	}
	else if (mNextDir == 'r')
	{
		mPacman.movePacmanRight();
		/*mBlinky.moveMonsterRight(1);
		mPinky.moveMonsterRight(2);
		mInky.moveMonsterRight(3);
		mClyde.moveMonsterRight(4);*/
	}
	else if (mNextDir == 'd')
	{
		mPacman.movePacmanDown();
		/*mBlinky.moveMonsterDown(1);
		mPinky.moveMonsterDown(2);
		mInky.moveMonsterDown(3);
		mClyde.moveMonsterDown(4);*/
	}

	IApplication::onTimer(); // Pour redessiner l'ecran
}
