#include "Blinky.h"
#include "Constants.h"

Blinky::Blinky()
{
	
}

void Blinky::initializeBitmap(HDC ihdc)
{
	mMonsterUpDC    = createBitmap(ihdc, L"IDB_PACMAN_BLINKY_UP");
	mMonsterDownDC  = createBitmap(ihdc, L"IDB_PACMAN_BLINKY_DOWN");
	mMonsterLeftDC  = createBitmap(ihdc, L"IDB_PACMAN_BLINKY_LEFT");
	mMonsterRightDC = createBitmap(ihdc, L"IDB_PACMAN_BLINKY_RIGHT");
	mMonsterWeakDC  = createBitmap(ihdc, L"IDB_PACMAN_WEAKMONSTER");
}

void Blinky::path()
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

		if (mLoopPos > 156)
		{
			mLoopPos = 0;
		}
	}
}

void Blinky::move()
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