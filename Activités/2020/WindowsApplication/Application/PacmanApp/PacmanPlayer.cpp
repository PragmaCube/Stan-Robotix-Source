#include "PacmanPlayer.h"
#include "PacmanGameEngine.h"
#include "Constants.h"
#include "PacmanApplication.h"

extern HINSTANCE hInst;

PacmanPlayer::PacmanPlayer() :
	mIsInit(false)
{

}

void PacmanPlayer::initializeBitmap(HDC ihdc)
{
	mPacmanUpDC = createBitmap(ihdc, L"IDB_PACMAN_PLAYER_UP");
	mPacmanDownDC = createBitmap(ihdc, L"IDB_PACMAN_PLAYER_DOWN");
	mPacmanLeftDC = createBitmap(ihdc, L"IDB_PACMAN_PLAYER_LEFT");
	mPacmanRightDC = createBitmap(ihdc, L"IDB_PACMAN_PLAYER_RIGHT");
	mPacmanPointDC = createBitmap(ihdc, L"IDB_PACMAN_PLAYER_CLOSE");
}

void PacmanPlayer::initializeGameEngine(PacmanGameEngine* iPacmanGameEngine)
{
	mPacmanGameEngine = iPacmanGameEngine;
}

void PacmanPlayer::initialise(RECT iWindowRect, PacmanGameBoard* iPacmanGameBoard)
{
	if (!mIsInit)
	{
		mGameBoard = iPacmanGameBoard;
		mSideX = (iWindowRect.right - iWindowRect.left) / mNbColumns;
		mSideY = (iWindowRect.bottom - iWindowRect.top) / mNbRows;

		mCoorX = iWindowRect.left + 14 * mSideX + mSideX / 2; //14
		mCoorY = 23 * mSideY + mSideY /2 ; //23

		mCoorYMin = iWindowRect.top;  // + et - 2 car lors de création des carrés/ronds, il y a 1 pixel de bordure dans laquelle est dessinée la forme. 
		mCoorYMax = iWindowRect.bottom;      // il faut donc compensser en enlevant/ajoutant 2 (pixel du carré + pixel de pacman)
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;

		mIsInit = true;
	}
	else
	{
		mCoorYMin = iWindowRect.bottom;
		mCoorYMax = iWindowRect.top;
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;

		mSideX = (iWindowRect.right - iWindowRect.left) / mNbRows;
		mSideY = (iWindowRect.bottom - iWindowRect.top) / mNbColumns;
	}
}

int PacmanPlayer::getX()
{
	return mCoorX;
}

int PacmanPlayer::getY()
{
	return mCoorY;
}

void PacmanPlayer::movePacmanUp()
{
	if (mCoorY - kSpeed > mCoorYMin)
	{
		mCoorY -= kSpeed;
	}
	mWay = 'u';
}

void PacmanPlayer::movePacmanDown()
{
	if (mCoorY + kSpeed < mCoorYMax)
	{
		mCoorY += kSpeed;
	}
	mWay = 'd';
}

void PacmanPlayer::movePacmanRight()
{
	if (mCoorX + kSpeed < mCoorXMax)
	{
		mCoorX += kSpeed;
	}
	mWay = 'r';
}

void PacmanPlayer::movePacmanLeft()
{
	if (mCoorX - kSpeed > mCoorXMin)
	{
		mCoorX -= kSpeed;
	}
	mWay = 'l';
}

void PacmanPlayer::move(char iWay)
{
	float wCoorBlocX = 0.0, wCoorBlocY = 0.0;
	switch (iWay)
	{
	case 'u':
		wCoorBlocX = (mCoorX - mCoorXMin) / ((mCoorXMax - mCoorXMin) / (mNbColumns));
		wCoorBlocY = (mCoorY + (mSideY / 2)) / ((mCoorYMax - mCoorYMin) / (mNbRows));
		if (mGameBoard->isWall(wCoorBlocX, (wCoorBlocY - 1)) == false)
		{
			mApplication->setOldDirect(mWay);
			movePacmanUp();
		}
		else
		{
			mApplication->resetDirect();
		}
		break;

	case 'd':
		wCoorBlocX = (mCoorX - mCoorXMin) / ((mCoorXMax - mCoorXMin) / (mNbColumns));
		wCoorBlocY = (mCoorY - mSideY / 2) / ((mCoorYMax - mCoorYMin) / (mNbRows));
		if (mGameBoard->isWall(wCoorBlocX, (wCoorBlocY + 1)) == false && mGameBoard->isSpawn(wCoorBlocX, (wCoorBlocY + 1)) == false)
		{
			mApplication->setOldDirect(mWay);
			movePacmanDown();
		}
		else
		{
			mApplication->resetDirect();
		}
		break;

	case 'l':
		wCoorBlocX = ((mCoorX + mSideX / 2) - mCoorXMin) / ((mCoorXMax - mCoorXMin) / (mNbColumns));
		wCoorBlocY = mCoorY / ((mCoorYMax - mCoorYMin) / (mNbRows));
		if (mGameBoard->isWall((wCoorBlocX - 1), wCoorBlocY) == false)
		{
			mApplication->setOldDirect(mWay);
			movePacmanLeft();
		}
		else
		{
			mApplication->resetDirect();
		}
		break;

	case 'r':
		wCoorBlocX = ((mCoorX - mSideX / 2) - mCoorXMin) / ((mCoorXMax - mCoorXMin) / (mNbColumns));
		wCoorBlocY = mCoorY / ((mCoorYMax - mCoorYMin) / (mNbRows));
		if (mGameBoard->isWall((wCoorBlocX + 1), wCoorBlocY) == false)
		{
			mApplication->setOldDirect(mWay);
			movePacmanRight();
		}
		else
		{
			mApplication->resetDirect();
		}
	};

	mPacmanGameEngine->setPacmanPos(wCoorBlocX, wCoorBlocY);

	TpPacman(iWay);
}

void PacmanPlayer::TpPacman(char iWay)
{
	switch (iWay)
	{
	case 'l':
	{
		if (mCoorX < (mCoorXMin + 5))
		{
			mCoorX = mCoorXMax;
		}
	}
		break;
	case 'r':
	{
		if (mCoorX > (mCoorXMax - 20))
		{
			mCoorX = mCoorXMin;
		}

	}
	}
}

char PacmanPlayer::getWay()
{
	return mDir;
}

HDC PacmanPlayer::createBitmap(HDC ihdc, const LPCWSTR lpBitmapName)
{
	HBITMAP wInitialMazeBitmap = LoadBitmap(hInst, lpBitmapName);

	HDC wCacheBitmapDC = ::CreateCompatibleDC(ihdc);
	HBITMAP hOldBmp = (HBITMAP)::SelectObject(wCacheBitmapDC, wInitialMazeBitmap);

	BITMAP wBitmap;
	GetObject(wInitialMazeBitmap, sizeof(BITMAP), reinterpret_cast<LPVOID>(&wBitmap));

	StretchBlt(ihdc,
		0,
		0,
		2 * kRadius,
		2 * kRadius,
		wCacheBitmapDC, 0, 0, wBitmap.bmWidth, wBitmap.bmHeight, SRCCOPY);

	BitBlt(wCacheBitmapDC,
		0,
		0,
		2 * kRadius,
		2 * kRadius,
		ihdc, 0, 0, SRCCOPY);

	return wCacheBitmapDC;
}

void PacmanPlayer::paint(HDC ihdc)
{
	mTimeSwitch++;

	

	HDC wCurrentWay = 0;
	if(mTimeSwitch > 1)
	{ 
		wCurrentWay = mPacmanPointDC;
		if (mTimeSwitch ==  2)
		{
			mTimeSwitch = 0;
		}
	}
	else
	{
		switch (mWay)
		{
		case 'u': wCurrentWay = mPacmanUpDC;
			break;
		case 'd': wCurrentWay = mPacmanDownDC;
			break;
		case 'l': wCurrentWay = mPacmanLeftDC;
			break;
		case 'r': wCurrentWay = mPacmanRightDC;
		}
	}

	BitBlt(ihdc,
		(int)(mCoorX)-kRadius,
		(int)(mCoorY)-kRadius,
		2 * kRadius,
		2 * kRadius,
		wCurrentWay, 0, 0, SRCCOPY);
}
