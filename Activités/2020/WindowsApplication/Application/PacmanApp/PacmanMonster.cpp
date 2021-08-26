#include "PacmanMonster.h"
#include "PacmanPlayer.h"
#include "Constants.h"

extern HINSTANCE hInst;                                // instance actuelle;

PacmanMonster::PacmanMonster(): mIsInit(false)
{
	
}

void PacmanMonster::initialise(RECT iWindowRect, Monster iMonsterType, PacmanGameBoard* iGameBoard, PacmanPlayer* iPlayer)
{
	mGameBoard = iGameBoard;
	mPlayer = iPlayer;

	int wRed = 0;
	int wGreen = 0;
	int wBlue = 0;

	mMonsterType = iMonsterType;

	switch (iMonsterType)
	{
	case eBlinky:
		wRed = 255;
		break;
	case ePinky:
		wRed = 255;
		wBlue = 255;
		break;
	case eInky:
		wBlue = 255;
		break;
	case eClyde:
		wGreen = 255;
		wBlue = 255;
		break;
	default:
		break;
	}
	
	COLORREF wColor = RGB(wRed, wGreen, wBlue);
	mBrush = CreateSolidBrush(wColor);

	if (!mIsInit)
	{
		// Valeurs arbitraires pour que le monstre s'affiche à
		// un endroit en particulier

		mCoorX = ((iWindowRect.left + iWindowRect.right) / 2) - 20;
		mCoorY = iWindowRect.bottom / 2 - 20;

		mCoorYMin = iWindowRect.bottom;
		mCoorYMax = iWindowRect.top;
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;

		mIsInit = true;
	}
	else                             // ce else permet de résoudre le pb de redimensionnement de l'écran
	{
		mCoorYMin = iWindowRect.bottom;
		mCoorYMax = iWindowRect.top;
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;
	}
}

bool PacmanMonster::isWallByWay(char iWay)
{
	switch (iWay)
	{
	case 'u':
		if (mGameBoard->isWall(mBoardCoordX, mBoardCoordY - 1))
		{
			return true;
		}

		return false;
	case 'd':
		if (mGameBoard->isWall(mBoardCoordX, mBoardCoordY + 1))
		{
			return true;
		}

		return false;
	case 'l':
		if (mGameBoard->isWall(mBoardCoordX - 1, mBoardCoordY))
		{
			return true;
		}

		return false;
	case 'r':
		if (mGameBoard->isWall(mBoardCoordX + 1, mBoardCoordY))
		{
			return true;
		}

		return false;
	default:
		return false;
	}
}

bool PacmanMonster::checkPlayerPos()
{
	if ((mPlayer->getX() == mBoardCoordX) && (mPlayer->getY() == mBoardCoordY))
	{
		return true;
	}

	else
	{
		return false;
	}
}

void PacmanMonster::tpMonster()
{
	mCoorX = ((mCoorXMin + mCoorXMax) / 2) - 20;
	mCoorY = mCoorYMin / 2 - 20;

	mBoardCoordX = 13;
	mBoardCoordY = 14;

	mStepX = 1; // 1 ---> 7
	mStepY = 1; // 1 ---> 8

	mXFix = 1; // 1 ---> 28
	mYFix = 1; // 1 ---> 31
}

void PacmanMonster::moveMonsterUp()
{
	if (mCoorY - kSpeedY >= mCoorYMax)
	{
		mCoorY -= kSpeedY;
	}
}

void PacmanMonster::moveMonsterDown()
{
	if (mCoorY + kSpeedY <= mCoorYMin)
	{
		mCoorY += kSpeedY;
	}
}

void PacmanMonster::moveMonsterRight()
{
	if (mCoorX + kSpeedX <= mCoorXMax)
	{
		mCoorX += kSpeedX;
	}
}

void PacmanMonster::moveMonsterLeft()
{
	if (mCoorX - kSpeedX >= mCoorXMin)
	{
		mCoorX -= kSpeedX;
	}
}

HDC PacmanMonster::createBitmap(HDC ihdc, const LPCWSTR lpBitmapName)
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

void PacmanMonster::paint(HDC ihdc)
{
	HDC wCurrentWay = 0;

	switch(mWay)
	{ 
	case 'u': wCurrentWay = mMonsterUpDC;
		break;
	case 'd': wCurrentWay = mMonsterDownDC;
		break;
	case 'l': wCurrentWay = mMonsterLeftDC;
		break;
	case 'r': wCurrentWay = mMonsterRightDC;
	}

	BitBlt(ihdc,
		(int)(mCoorX)-kRadius,
		(int)(mCoorY)-kRadius,
		2 * kRadius,
		2 * kRadius,
		wCurrentWay, 0, 0, SRCCOPY);
}

void PacmanMonster::updatePlayer(PacmanPlayer* iPlayer)
{
	mPlayer = iPlayer;
}