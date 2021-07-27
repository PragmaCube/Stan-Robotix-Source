#include "PacmanApplication.h"
#include "PacmanGameEngine.h"

#include <string>

PacmanApplication::PacmanApplication()
{
	mPacmanGameBoard.initializeMap();

	mPacmanGameEngine = new PacmanGameEngine();

	mPacmanGameBoard.initializeGameEngine(mPacmanGameEngine);
	mPacman.initializeGameEngine(mPacmanGameEngine);
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


	mPacmanGameBoard.drawMap(ihdc, iPaintArea);

	mBlinky.initialise(iPaintArea, eBlinky, &mPacmanGameBoard, &mPacman);
	
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
	case ' ': 
		mPacmanGameBoard.toggleDebugging(); // drawMemorie(ihdc, iPaintArea);
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

	mCoorPacX = mPacman.getX();
	mCoorPacY = mPacman.getY();

	mCoorBlocX = (mCoorPacX - 350 + 20) / 40;
	mCoorBlocY = (mCoorPacY - 100 + 20) / 40;

	if (mNextDir == 'l' && !mPacmanGameBoard.isWall(((mCoorPacX - 18 - 350 + 20) - 5) / 40, (mCoorPacY - 100 + 20 - 18) / 40) 
		&& !mPacmanGameBoard.isWall(((mCoorPacX - 18 - 350 + 20) - 5) / 40, (mCoorPacY - 100 + 20 + 18) / 40))
	{
		mDir = 'l';
	}
	else if (mNextDir == 'r' && !mPacmanGameBoard.isWall(((mCoorPacX + 18 - 350 + 20) + 5) / 40, (mCoorPacY - 100 + 20 - 18) / 40) 
		&& !mPacmanGameBoard.isWall(((mCoorPacX + 18 - 350 + 20) + 5) / 40, (mCoorPacY - 100 + 20 + 18) / 40))
	{
		mDir = 'r';
	}
	else if (mNextDir == 'u' && !mPacmanGameBoard.isWall((mCoorPacX - 350 + 20 - 18) / 40, ((mCoorPacY - 18 - 100 + 20) - 5) / 40) 
		&& !mPacmanGameBoard.isWall((mCoorPacX - 350 + 20 + 18) / 40, ((mCoorPacY - 18 - 100 + 20) - 5) / 40))
	{
		mDir = 'u';
	}
	else if (mNextDir == 'd' && !mPacmanGameBoard.isWall((mCoorPacX - 350 + 20 - 18) / 40, ((mCoorPacY + 18 - 100 + 20) + 5) / 40) 
		&& !mPacmanGameBoard.isWall((mCoorPacX - 350 + 20 + 18) / 40, ((mCoorPacY + 18 - 100 + 20) + 5) / 40))
	{
		mDir = 'd';
	}

	if (mDir == 'l' && !mPacmanGameBoard.isWall(((mCoorPacX - 18 - 350 + 20) - 5) / 40, mCoorBlocY))
	{
		mPacman.movePacmanLeft();
	}
	else if (mDir == 'u' && !mPacmanGameBoard.isWall(mCoorBlocX, ((mCoorPacY - 18 - 100 + 20) - 5) / 40))
	{
		mPacman.movePacmanUp();
	}
	else if (mDir == 'r' && !mPacmanGameBoard.isWall(((mCoorPacX + 18 - 350 + 20) + 5) / 40, mCoorBlocY))
	{
		mPacman.movePacmanRight();
	}
	else if (mDir == 'd' && !mPacmanGameBoard.isWall(mCoorBlocX, ((mCoorPacY + 18 - 100 + 20) + 5) / 40))
	{
		mPacman.movePacmanDown();
	}

	IApplication::onTimer(); // Pour redessiner l'ecran
}
