#include "Inky.h"
#include "Constants.h"

Inky::Inky()
{

}

char Inky::bestRightLeft(char iLastChoice, unsigned int iOtherY)
{
	if (iLastChoice == 'r')
	{
		if (isWallByWay('l'))
		{
			if (mBoardCoordY - iOtherY > 0)
			{
				// Doit aller en haut

				if (isWallByWay('u'))
				{
					if (isWallByWay('d'))
					{
						return 'r';
					}

					return 'd';
				}

				return 'u';
			}

			else
			{
				// Doit aller en bas

				if (isWallByWay('d'))
				{
					if (isWallByWay('u'))
					{
						return 'r';
					}

					return 'u';
				}

				return 'd';
			}
		}

		return 'l';
	}

	else if (iLastChoice == 'l')
	{
		if (isWallByWay('r'))
		{
			if (mBoardCoordY - iOtherY > 0)
			{
				// Doit aller en haut

				if (isWallByWay('u'))
				{
					if (isWallByWay('d'))
					{
						return 'l';
					}

					return 'd';
				}

				return 'u';
			}

			else
			{
				// Doit aller en bas

				if (isWallByWay('d'))
				{
					if (isWallByWay('u'))
					{
						return 'l';
					}

					return 'u';
				}

				return 'd';
			}
		}

		return 'r';
	}
}

char Inky::bestUpDown(char iLastChoice, unsigned int iOtherX)
{
	if (iLastChoice == 'u')
	{
		if (isWallByWay('d'))
		{
			if (mBoardCoordX - iOtherX > 0)
			{
				// Doit aller à gauche

				if (isWallByWay('l'))
				{
					if (isWallByWay('r'))
					{
						return 'u';
					}

					return 'r';
				}

				return 'l';
			}

			else
			{
				// Doit aller à droite

				if (isWallByWay('r'))
				{
					if (isWallByWay('l'))
					{
						return 'u';
					}

					return 'l';
				}

				return 'r';
			}
		}

		return 'd';
	}

	else if (iLastChoice == 'd')
	{
		if (isWallByWay('u'))
		{
			if (mBoardCoordX - iOtherX > 0)
			{
				// Doit aller à gauche

				if (isWallByWay('l'))
				{
					if (isWallByWay('r'))
					{
						return 'd';
					}

					return 'r';
				}

				return 'l';
			}

			else
			{
				// Doit aller à droite

				if (isWallByWay('r'))
				{
					if (isWallByWay('l'))
					{
						return 'd';
					}

					return 'l';
				}

				return 'r';
			}
		}

		return 'u';
	}
	
}

char Inky::nextMoveWithTarget()
{
	if (mBoardCoordX == mTargetX1 && mBoardCoordY == mTargetY1)
	{
		mTarget1Done = true;
	}

	if (!mTarget1Done)
	{
		if (mBoardCoordX - mTargetX1 > 0)
		{
			// Doit aller à gauche

			return bestUpDown('d', mTargetX1);
		}

		else if (mBoardCoordX - mTargetX1 == 0)
		{
			// Doit aller en haut / en bas

			if (mBoardCoordY - mTargetY1 > 0)
			{
				// Doit aller en haut

				if (isWallByWay('u'))
				{
					if (isWallByWay('d'))
					{
						if (isWallByWay('r'))
						{
							return 'l';
						}

						return 'r';
					}

					return 'd';
				}

				return 'u';
			}

			else
			{
				// Doit aller en bas

				if (isWallByWay('d'))
				{
					if (isWallByWay('u'))
					{
						if (isWallByWay('r'))
						{
							return 'l';
						}

						return 'r';
					}

					return 'u';
				}

				return 'd';
			}
		}

		else
		{
			// Doit aller à droite

			return bestRightLeft('l', mTargetY1);
		}
	}

	else
	{
		if (mBoardCoordX - mTargetX2 > 0)
		{
			// Doit aller à gauche

			return bestUpDown('d', mTargetX2);
		}

		else if (mBoardCoordX - mTargetX2 == 0)
		{
			// Doit aller en haut / en bas

			if (mBoardCoordY - mTargetY2 > 0)
			{
				// Doit aller en haut

				if (isWallByWay('u'))
				{
					if (isWallByWay('d'))
					{
						if (isWallByWay('r'))
						{
							return 'l';
						}

						return 'r';
					}

					return 'd';
				}

				return 'u';
			}

			else
			{
				// Doit aller en bas

				if (isWallByWay('d'))
				{
					if (isWallByWay('u'))
					{
						if (isWallByWay('r'))
						{
							return 'l';
						}

						return 'r';
					}

					return 'u';
				}

				return 'd';
			}
		}

		else
		{
			// Doit aller à droite

			return bestUpDown('u', mTargetX2);
		}
	}
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