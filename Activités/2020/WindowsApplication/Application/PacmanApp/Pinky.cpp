#include "Pinky.h"
#include "Constants.h"

#include <cmath>
#include <ctime>

Pinky::Pinky()
{
	std::srand(std::time(0));
}

void Pinky::path()
{
	mWay = mExitPath[mExitPos];
	mExitPos++;
}

void Pinky::exSwitch()
{
	switch (mWay)
	{
	case 'u':
		if (4 < mStepY)
		{
			mStepY = 1;

			mBoardCoordY--;

			mCoorY -= kDeltaY;

			if (mYFix == 31)
			{
				mCoorY += 9;
				mYFix = 0;
			}

			path();
		}

		break;
	case 'd':
		if (4 < mStepY)
		{
			mStepY = 1;

			mBoardCoordY++;

			mCoorY += kDeltaY;

			if (mYFix == 31)
			{
				mCoorY += 9;
				mYFix = 0;
			}

			path();
		}

		break;
	case 'l':
		if (8 <= mStepX)
		{
			mStepX = 1;

			mBoardCoordX--;

			mCoorX -= kDeltaX;

			path();
		}

		break;
	case 'r':
		if (8 <= mStepX)
		{
			mStepX = 1;

			mBoardCoordX++;

			mCoorX += kDeltaX;

			path();
		}

		break;
	}
}

void Pinky::initializeBitmap(HDC ihdc)
{

}

char Pinky::randomMove()
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

void Pinky::randomKeepWay()
{
	int wRandomMove = std::rand() % 2;

	if (0 == wRandomMove)
	{
		mKeepWay = false;
	}
}

void Pinky::updateMovement()
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

void Pinky::move()
{
	if (mInBox)
	{
		exSwitch();

		if (mExitPos == 17)
		{
			mInBox = false;
			mWay = randomMove();
		}
	}

	else
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