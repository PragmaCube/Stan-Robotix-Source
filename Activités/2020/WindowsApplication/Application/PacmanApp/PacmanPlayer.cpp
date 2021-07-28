#include "PacmanPlayer.h"
#include "PacmanGameEngine.h"

PacmanPlayer::PacmanPlayer() :
	mIsInit(false)
{
	int wRed = 255;
	int wGreen = 255;
	int wBlue = 0;
	COLORREF wColor = RGB(wRed, wGreen, wBlue);
	mBrush = CreateSolidBrush(wColor);
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

void PacmanPlayer::paint(HDC ihdc)
{
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush);

	::Ellipse(ihdc,
		(int)(mCoorX)-mRadius,
		(int)(mCoorY)-mRadius,
		(int)(mCoorX)+mRadius,
		(int)(mCoorY)+mRadius);

	::SelectObject(ihdc, wOldBrush);

	mPacmanGameEngine->setPacmanPos(mCoorX, mCoorY);
}
