#include "Inky.h"
#include "Constants.h"

Inky::Inky()
{

}

void Inky::initializeBitmap(HDC ihdc)
{

}

void Inky::path()
{
	if (mInBox)
	{
		mWay = mExitPath[mExitPos];
		mExitPos++;
	}

	else
	{
		mWay = mLoopPath[mLoopPos];
		mLoopPos++;

		if (mLoopPos > 140)
		{
			mLoopPos = 0;
		}
	}
}

void Inky::move()
{
	if (mExitPos == 16)
	{
		mInBox = false;
	}

	switch (mWay)
	{
	case 'u':
		if (4 < mStepY)
		{
			mStepY = 1;

			mBoardCoordY--;
			mYFix++;

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
			mYFix++;

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
	default:
		path();
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
	default:
		break;
	}
}