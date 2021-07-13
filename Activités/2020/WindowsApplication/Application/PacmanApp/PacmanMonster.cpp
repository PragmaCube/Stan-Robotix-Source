#include "PacmanMonster.h"

PacmanMonster::PacmanMonster(): mIsInit(false)
{
	
}

void PacmanMonster::initialise(RECT iWindowRect, Monster iMonsterType)
{
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
		mCoorX = ((iWindowRect.left + iWindowRect.right) / 2);
		mCoorY = iWindowRect.top + (double)(rand() % (iWindowRect.bottom - iWindowRect.top));

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

void PacmanMonster::moveMonsterUp(int iModifier)
{
	if (mCoorY - kSpeed - iModifier > mCoorYMax)
	{
		mCoorY -= (kSpeed + iModifier);
	}
}

void PacmanMonster::moveMonsterDown(int iModifier)
{
	if (mCoorY + kSpeed + iModifier < mCoorYMin)
	{
		mCoorY += kSpeed + iModifier;
	}
}

void PacmanMonster::moveMonsterRight(int iModifier)
{
	if (mCoorX + kSpeed + iModifier < mCoorXMax)
	{
		mCoorX += kSpeed + iModifier;
	}
}

void PacmanMonster::moveMonsterLeft(int iModifier)
{
	if (mCoorX - kSpeed - iModifier > mCoorXMin)
	{
		mCoorX -= (kSpeed + iModifier);
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

void PacmanMonster::setBoard(PacmanGameBoard* iGameBoard)
{
	mGameBoard = iGameBoard;
}

void PacmanMonster::setPlayer(PacmanPlayer* iPlayer)
{
	mPlayer = iPlayer;
}