#include "PacmanMonster.h"

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

		mCoorX = ((iWindowRect.left + iWindowRect.right) / 4) + 107;
		mCoorY = iWindowRect.bottom / 4 + 9;

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

void PacmanMonster::moveMonsterUp()
{
	if (mCoorY - kSpeed >= mCoorYMax)
	{
		mCoorY -= kSpeed;
		mBoardCoordY--;
	}
}

void PacmanMonster::moveMonsterDown()
{
	if (mCoorY + kSpeed <= mCoorYMin)
	{
		mCoorY += kSpeed;
		mBoardCoordY++;
	}
}

void PacmanMonster::moveMonsterRight()
{
	if (mCoorX + kSpeed <= mCoorXMax)
	{
		mCoorX += kSpeed;
		mBoardCoordX++;
	}
}

void PacmanMonster::moveMonsterLeft()
{
	if (mCoorX - kSpeed >= mCoorXMin)
	{
		mCoorX -= kSpeed;
		mBoardCoordX--;
	}
}

void PacmanMonster::move()
{
	if (1 == mBoardCoordX && 1 == mBoardCoordY)
	{
		mWay = 'd';
	}

	else if (1 == mBoardCoordX && 9 == mBoardCoordY)
	{
		mWay = 'r';
	}

	else if (9 == mBoardCoordX && 1 == mBoardCoordY)
	{
		mWay = 'l';
	}

	else if (9 == mBoardCoordX && 9 == mBoardCoordY)
	{
		mWay = 'u';
	}

	switch (mWay)
	{
	case 'u':
		moveMonsterUp();
		break;
	case 'd':
		moveMonsterDown();
		break;
	case 'l':
		moveMonsterLeft();
		break;
	case 'r':
		moveMonsterRight();
		break;
	}	
}

void PacmanMonster::paint(HDC ihdc)
{
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush);

	::Ellipse(ihdc,
		(int)(mCoorX)-mRadius,
		(int)(mCoorY)-mRadius,
		(int)(mCoorX)+mRadius,
		(int)(mCoorY)+mRadius);

	::SelectObject(ihdc, wOldBrush);
}

void PacmanMonster::updatePlayer(PacmanPlayer* iPlayer)
{
	mPlayer = iPlayer;
}