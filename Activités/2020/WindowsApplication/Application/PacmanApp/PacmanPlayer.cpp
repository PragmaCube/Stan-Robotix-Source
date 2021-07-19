#include "PacmanPlayer.h"

PacmanPlayer::PacmanPlayer():
mIsInit(false)
{
	int wRed = 255;
	int wGreen = 255;
	int wBlue = 0;
	COLORREF wColor = RGB(wRed, wGreen, wBlue);
	mBrush = CreateSolidBrush(wColor);
}

void PacmanPlayer::initialise(RECT iWindowRect)
{
	if (!mIsInit)
	{
		mCoorX = 350 + 5 * 40; // coordonées du 5e bloc 
		mCoorY = 100 + 9 * 40; // de la 2e rangée 

		mCoorYMin = 100 + 9 * 40 + 2;  // + et - 2 car lors de création des carrés/ronds, il y a 1 pixel de bordure dans laquelle est dessinée la forme. 
		mCoorYMax = 100 + 40 - 2;      // il faut donc compensser en enlevant/ajoutant 2 (pixel du carré + pixel de pacman)
		mCoorXMin = 350 + 40 - 2;
		mCoorXMax = 350 + 9 * 40 + 2;

		mIsInit = true;
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
}

void PacmanPlayer::movePacmanDown()
{
	if (mCoorY + kSpeed < mCoorYMin)
	{
		mCoorY += kSpeed;
	}
}

void PacmanPlayer::movePacmanRight()
{
	if (mCoorX + kSpeed < mCoorXMax)
	{
		mCoorX += kSpeed;
	}
}

void PacmanPlayer::movePacmanLeft()
{
	if (mCoorX - kSpeed > mCoorXMin)
	{
		mCoorX -= kSpeed;
	}
}

void PacmanPlayer::paint(HDC ihdc)
{
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush);

	::Ellipse(ihdc,
		(int)(mCoorX)-mRadius,
		(int)(mCoorY)-mRadius,
		(int)(mCoorX)+mRadius,
		(int)(mCoorY)+mRadius);

	::SelectObject(ihdc, wOldBrush);
}

void PacmanPlayer::setBoard(PacmanGameBoard* iGameBoard)
{
	mGameBoard = iGameBoard;
}