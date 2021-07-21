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

			if (mGameBoard->isWall(mBoardCoordX, mBoardCoordY - 1))
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

			if (mGameBoard->isWall(mBoardCoordX, mBoardCoordY + 1))
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

			if (mGameBoard->isWall(mBoardCoordX - 1, mBoardCoordY))
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

			if (mGameBoard->isWall(mBoardCoordX + 1, mBoardCoordY))
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