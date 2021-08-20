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

void Blinky::move()
{
	switch (mWay)
	{
	case 'u':
		if (4 < mStepY)
		{
			mStepY = 1;

			mBoardCoordY--;

			mCoorY -= kDeltaY;

			if ((mGameBoard != nullptr) && isWallByWay(mWay))
			{
				mWay = 'l';
			}
		}

		break;
	case 'd':
		if (4 < mStepY)
		{
			mStepY = 1;

			mBoardCoordY++;

			mCoorY += kDeltaY;

			if ((mGameBoard != nullptr) && isWallByWay(mWay))
			{
				mWay = 'r';
			}
		}

		break;
	case 'l':
		if (8 <= mStepX)
		{
			mStepX = 1;

			mBoardCoordX--;

			mCoorX -= kDeltaX;

			if ((mGameBoard != nullptr) && isWallByWay(mWay))
			{
				mWay = 'd';
			}
		}

		break;
	case 'r':
		if (8 <= mStepX)
		{
			mStepX = 1;

			mBoardCoordX++;

			mCoorX += kDeltaX;

			if ((mGameBoard != nullptr) && isWallByWay(mWay))
			{
				mWay = 'u';

				if ((mGameBoard != nullptr) && mGameBoard->isWall(mBoardCoordX, mBoardCoordY - 1))
				{
					mWay = 'd';
				}
			}
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
}