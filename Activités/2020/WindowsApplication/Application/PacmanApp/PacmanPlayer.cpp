#include "PacmanPlayer.h"
#include "PacmanGameEngine.h"
#include "Constants.h"

extern HINSTANCE hInst;

PacmanPlayer::PacmanPlayer() :
	mIsInit(false)
{
	int wRed = 255;
	int wGreen = 255;
	int wBlue = 0;
	COLORREF wColor = RGB(wRed, wGreen, wBlue);
	mBrush = CreateSolidBrush(wColor);
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

void PacmanPlayer::initialise(RECT iWindowRect)
{
	if (!mIsInit)
	{
		mCoorX = 350 + 5 * 40; // coordonées du 5e bloc 
		mCoorY = 100 + 9 * 40 - 5; // de la 2e rangée 

		mCoorYMin = iWindowRect.bottom;  // + et - 2 car lors de création des carrés/ronds, il y a 1 pixel de bordure dans laquelle est dessinée la forme. 
		mCoorYMax = iWindowRect.top;      // il faut donc compensser en enlevant/ajoutant 2 (pixel du carré + pixel de pacman)
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;

		wSideX = (iWindowRect.right - iWindowRect.left) / mNbRows;
		wSideY = (iWindowRect.bottom - iWindowRect.top) / mNbColumns;

		mIsInit = true;
	}
	else
	{
		mCoorYMin = iWindowRect.bottom;
		mCoorYMax = iWindowRect.top;
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;

		wSideX = (iWindowRect.right - iWindowRect.left) / mNbRows;
		wSideY = (iWindowRect.bottom - iWindowRect.top) / mNbColumns;
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
	if (mCoorY - kSpeed > mCoorYMax)
	{
		mCoorY -= kSpeed;
	}
	mWay = 'u';
}

void PacmanPlayer::movePacmanDown()
{
	if (mCoorY + kSpeed < mCoorYMin)
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

void PacmanPlayer::move(char way)
{
	mCoorBlocX = (mCoorX - mCoorXMin + (wSideX / 2)) / wSideX;
	mCoorBlocY = (mCoorY - mCoorYMax + (wSideY / 2)) / wSideY;

	if (way == 'l' && !mGameBoard.isWall(((mCoorX - 18 - mCoorXMin + (wSideX / 2)) - kSpeed) / wSideX, (mCoorY + (wSideY / 2) - 18 - mCoorYMax) / wSideY)
		&& !mGameBoard.isWall(((mCoorX - 18 - mCoorXMin + (wSideX / 2)) - kSpeed) / wSideX, (mCoorY - mCoorYMax + (wSideY / 2) + 18) / wSideY))
	{
		mDir = 'l';
	}
	else if (way == 'r' && !mGameBoard.isWall(((mCoorX + 18 - mCoorXMin + (wSideX / 2)) + kSpeed) / wSideX, (mCoorY + (wSideY / 2) - 18 - mCoorYMax) / wSideY)
		&& !mGameBoard.isWall(((mCoorX - 18 - mCoorXMin + (wSideX / 2)) + kSpeed) / wSideX, (mCoorY + (wSideY / 2) + 18 - mCoorYMax) / wSideY))
	{
		mDir = 'r';
	}
	else if (way == 'u' && !mGameBoard.isWall(((mCoorX + 18 - mCoorXMin + (wSideX / 2)) - kSpeed) / wSideX, (mCoorY - mCoorYMax + (wSideY / 2) - 18) / wSideY)
		&& !mGameBoard.isWall(((mCoorX - 18 - mCoorXMin + (wSideX / 2)) - kSpeed) / wSideX, (mCoorY + (wSideY / 2) + 18) / wSideY))
	{
		mDir = 'u';
	}
	else if (way == 'd' && !mGameBoard.isWall(((mCoorX + 18 - mCoorXMin + (wSideX / 2)) + kSpeed) / wSideX, (mCoorY - mCoorYMax + (wSideY / 2) + 18) / wSideY)
		&& !mGameBoard.isWall(((mCoorX - 18 - mCoorXMin + (wSideX / 2)) + kSpeed) / wSideX, (mCoorY - mCoorYMax + (wSideY / 2) + 18) / wSideY))
	{
		mDir = 'd';
	}

	if (mDir == 'l' && !mGameBoard.isWall(((mCoorX - 18 - mCoorXMin + (wSideX / 2)) - kSpeed) / wSideX, mCoorBlocY))
	{
		movePacmanLeft();
		/*mBlinky.moveMonsterLeft(1);
		mPinky.moveMonsterLeft(2);
		mInky.moveMonsterLeft(3);
		mClyde.moveMonsterLeft(4);*/
	}
	else if (mDir == 'u' && !mGameBoard.isWall(mCoorBlocX, ((mCoorY - 18 - mCoorYMax + (wSideY / 2)) - kSpeed) / wSideY))
	{
		movePacmanUp();
		/*mBlinky.moveMonsterUp(1);
		mPinky.moveMonsterUp(2);
		mInky.moveMonsterUp(3);
		mClyde.moveMonsterUp(4);*/
	}
	else if (mDir == 'r' && !mGameBoard.isWall(((mCoorX + 18 - mCoorXMin + (wSideX / 2)) + kSpeed) / wSideX, mCoorBlocY))
	{
		movePacmanRight();
		/*mBlinky.moveMonsterRight(1);
		mPinky.moveMonsterRight(2);
		mInky.moveMonsterRight(3);
		mClyde.moveMonsterRight(4);*/
	}
	else if (mDir == 'd' && !mGameBoard.isWall(mCoorBlocX, ((mCoorY + 18 - mCoorYMax + (wSideY / 2)) + kSpeed) / wSideY))
	{
		movePacmanDown();
		/*mBlinky.moveMonsterDown(1);
		mPinky.moveMonsterDown(2);
		mInky.moveMonsterDown(3);
		mClyde.moveMonsterDown(4);*/
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

	mPacmanGameEngine->setPacmanPos(mCoorX, mCoorY);

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
