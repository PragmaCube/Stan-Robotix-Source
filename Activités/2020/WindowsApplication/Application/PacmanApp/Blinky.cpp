#include "Blinky.h"
#include "Constants.h"

Blinky::Blinky()
{
	
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

			if (isWallByWay(mWay))
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

			if (isWallByWay(mWay))
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

			if (isWallByWay(mWay))
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

			if (isWallByWay(mWay))
			{
				mWay = 'u';

				if (mGameBoard->isWall(mBoardCoordX, mBoardCoordY - 1))
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