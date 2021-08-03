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
	mClyde.initialise(iPaintArea, eClyde, &mPacmanGameBoard, &mPacman);
	mInky.initialise(iPaintArea, eInky, &mPacmanGameBoard, &mPacman);

	/*mPinky.initialise(iPaintArea, ePinky);
	mInky.initialise(iPaintArea, eInky);
	*/

	mBlinky.paint(ihdc);
	mClyde.paint(ihdc);
	mInky.paint(ihdc);

	/* Pas besoin d'eux pour le moment
	mPinky.paint(ihdc);
	mInky.paint(ihdc);
	*/

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
	mClyde.move();
	mInky.move();
	mPacman.move(mNextDir);

	IApplication::onTimer(); // Pour redessiner l'ecran
}
