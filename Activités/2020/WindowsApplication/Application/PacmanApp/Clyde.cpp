#include "Clyde.h"
#include "Constants.h"

#include <cmath>
#include <ctime>

Clyde::Clyde()
{
	std::srand(std::time(0));
}

void Clyde::initializeBitmap(HDC ihdc)
{

}

char Clyde::randomMove()
{
	int wRandomMove = std::rand() % 4;

	switch (wRandomMove)
	{
	case 0:
		return 'u';
	case 1:
		return 'd';
	case 2:
		return 'l';
	case 3:
		return 'r';
	default:
		return 'u';
	}
}

void Clyde::randomKeepWay()
{
	int wRandomMove = std::rand() % 4;

	if (0 == wRandomMove)
	{
		mKeepWay = false;
	}
}

void Clyde::updateMovement()
{
	if (!mKeepWay || isWallByWay(mWay))
	{
		do
		{
			mWay = randomMove();
		}

		while (isWallByWay(mWay));
	}
}

void Clyde::move()
{
	randomKeepWay();

	switch (mWay)
	{
	case 'u':
		if (4 < mStepY)
		{
			mStepY = 1;

			mBoardCoordY--;

			mCoorY -= kDeltaY;

			updateMovement();

			if (mYFix == 31)
			{
				mCoorY += 9;
				mYFix = 0;
			}
			
		}

		break;
	case 'd':
		if (4 < mStepY)
		{
			mStepY = 1;

			mBoardCoordY++;

			mCoorY += kDeltaY;

			updateMovement();

			if (mYFix == 31)
			{
				mCoorY += 9;
				mYFix = 0;
			}
		}

		break;
	case 'l':
		if (8 <= mStepX)
		{
			mStepX = 1;

			mBoardCoordX--;

			mCoorX -= kDeltaX;

			updateMovement();
		}

		break;
	case 'r':
		if (8 <= mStepX)
		{
			mStepX = 1;

			mBoardCoordX++;

			mCoorX += kDeltaX;

			updateMovement();
		}

		break;
	}

	switch (mWay)
	{
	case 'u':
		moveMonsterUp();
		mStepY++;
		break;
	case 'd':
		moveMonsterDown();
		mStepY++;
		break;
	case 'l':
		moveMonsterLeft();
		mStepX++;
		break;
	case 'r':
		moveMonsterRight();
		mStepX++;
		break;
	}

	mKeepWay = true;
}