#include "PacmanApplication.h"
#include "PacmanGameEngine.h"

#include <string>

PacmanApplication::PacmanApplication()
{
	mPacmanGameBoard.initializeMap();

	mPacmanGameEngine = new PacmanGameEngine();

	mPacmanGameBoard.initializeGameEngine(mPacmanGameEngine);
	mPacman.initializeGameEngine(mPacmanGameEngine);

	mPacman.setApplication(this);
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

	if (!mIsInit)
	{
		mBlinky.initialise(iPaintArea, eBlinky, &mPacmanGameBoard, &mPacman);
		mClyde.initialise(iPaintArea, eClyde, &mPacmanGameBoard, &mPacman);
		mInky.initialise(iPaintArea, eInky, &mPacmanGameBoard, &mPacman);
		mPinky.initialise(iPaintArea, ePinky, &mPacmanGameBoard, &mPacman);

		mPacman.initialise(iPaintArea, &mPacmanGameBoard);

		mBlinky.initializeBitmap(ihdc);
		mClyde.initializeBitmap(ihdc);
		mInky.initializeBitmap(ihdc);
		mPinky.initializeBitmap(ihdc);

		mPacman.initializeBitmap(ihdc);

		mIsInit = true;
	}

	mBlinky.paint(ihdc);
	mClyde.paint(ihdc);
	mInky.paint(ihdc);
	mPinky.paint(ihdc);

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
	
}

void PacmanApplication::onMouseRightClick(int iPosX, int iPosY)
{

}

void PacmanApplication::onTimer()
{
	if (!(mBlinky.checkPlayerPos() || mClyde.checkPlayerPos() || mInky.checkPlayerPos() || mPinky.checkPlayerPos()) || !mPacman.getWeak()) 
	{
		if ((float)(clock() - mClock) / CLOCKS_PER_SEC >= 8)
		{
			mPacman.setWeak(true);
		}

		mBlinky.move();
		mClyde.move();
		mInky.move();
		mPinky.move();

		mPacman.move(mNextDir);

		if (mPacmanGameBoard.isPowerUp(mPacman.getX(), mPacman.getY()))
		{
			mPacman.setWeak(false);
			mClock = clock();
		}

		if (!mPacman.getWeak())
		{
			if (mBlinky.checkPlayerPos())
			{
				mBlinky.tpMonster();
				mBlinky.reset();
			}

			if (mClyde.checkPlayerPos())
			{
				mClyde.tpMonster();
				mClyde.reset();
			}

			if (mInky.checkPlayerPos())
			{
				mInky.tpMonster();
				mInky.reset();
			}

			if (mPinky.checkPlayerPos())
			{
				mPinky.tpMonster();
				mPinky.reset();
			}
		}

		mBlinky.updatePlayer(&mPacman);
		mClyde.updatePlayer(&mPacman);
		mInky.updatePlayer(&mPacman);
		mPinky.updatePlayer(&mPacman);

		IApplication::onTimer(); // Pour redessiner l'ecran
	}
}

void PacmanApplication::setOldDirect(char iOldDirect)
{
	mOldWay = iOldDirect;
}

void PacmanApplication::resetDirect()
{
	mNextDir = mOldWay;
}
