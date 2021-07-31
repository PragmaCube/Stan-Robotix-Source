#include "PacmanMonster.h"
#include "Constants.h"

PacmanMonster::PacmanMonster(): mIsInit(false)
{
	
}

void PacmanMonster::initialise(RECT iWindowRect, Monster iMonsterType, PacmanGameBoard* iGameBoard, PacmanPlayer* iPlayer)
{
	mGameBoard = iGameBoard;
	mPlayer = iPlayer;

	int wRed = 0;
	int wGreen = 0;
	int wBlue = 0;

	switch (iMonsterType)
	{
	case eBlinky:
		wRed = 255;
		break;
	case ePinky:
		wRed = 255;
		wBlue = 255;
		break;
	case eInky:
		wBlue = 255;
		break;
	case eClyde:
		wGreen = 255;
		wBlue = 255;
		break;
	default:
		break;
	}
	
	COLORREF wColor = RGB(wRed, wGreen, wBlue);
	mBrush = CreateSolidBrush(wColor);

	if (!mIsInit)
	{
		// Valeurs arbitraires pour que le monstre s'affiche à
		// un endroit en particulier

		mCoorX = ((iWindowRect.left + iWindowRect.right) / 2) - 20;
		mCoorY = iWindowRect.bottom / 2 - 20;

		mCoorYMin = iWindowRect.bottom;
		mCoorYMax = iWindowRect.top;
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;

		mIsInit = true;
	}

	else                             // ce else permet de résoudre le pb de redimensionnement de l'écran
	{
		mCoorYMin = iWindowRect.bottom;
		mCoorYMax = iWindowRect.top;
		mCoorXMin = iWindowRect.left;
		mCoorXMax = iWindowRect.right;
	}
}

bool PacmanMonster::isWallByWay(char iWay)
{
	switch (iWay)
	{
	case 'u':
		if (mGameBoard->isWall(mBoardCoordX, mBoardCoordY - 1))
		{
			return true;
		}

		return false;
	case 'd':
		if (mGameBoard->isWall(mBoardCoordX, mBoardCoordY + 1))
		{
			return true;
		}

		return false;
	case 'l':
		if (mGameBoard->isWall(mBoardCoordX - 1, mBoardCoordY))
		{
			return true;
		}

		return false;
	case 'r':
		if (mGameBoard->isWall(mBoardCoordX + 1, mBoardCoordY))
		{
			return true;
		}

		return false;
	default:
		return false;
	}
}

void PacmanMonster::moveMonsterUp()
{
	if (mCoorY - kSpeedY >= mCoorYMax)
	{
		mCoorY -= kSpeedY;
	}
}

void PacmanMonster::moveMonsterDown()
{
	if (mCoorY + kSpeedY <= mCoorYMin)
	{
		mCoorY += kSpeedY;
	}
}

void PacmanMonster::moveMonsterRight()
{
	if (mCoorX + kSpeedX <= mCoorXMax)
	{
		mCoorX += kSpeedX;
	}
}

void PacmanMonster::moveMonsterLeft()
{
	if (mCoorX - kSpeedX >= mCoorXMin)
	{
		mCoorX -= kSpeedX;
	}
}

void PacmanMonster::move()
{
	/*

	// Il y a conservation du mouvement (pour le moment)
	// Le déplacement se fait en 8 étapes (8 x 5 = 40 --> épaisseur des blocs)
	// Le mouvement ne change pas pendant ces étapes

	if (8 < mStep)
	{
		mStep = 1;

		switch (mWay)
		{
		case 'u':
			mBoardCoordY--;
			break;
		case 'd':
			mBoardCoordY++;
			break;
		case 'l':
			mBoardCoordX--;
			break;
		case 'r':
			mBoardCoordX++;
			break;
		default:
			break;
		}

		if (1 == mBoardCoordX && 1 == mBoardCoordY)
		{
			mWay = 'd';
		}

		else if (1 == mBoardCoordX && 9 == mBoardCoordY)
		{
			mWay = 'r';
		}

		else if (9 == mBoardCoordX && 1 == mBoardCoordY)
		{
			mWay = 'l';
		}

		else if (9 == mBoardCoordX && 9 == mBoardCoordY)
		{
			mWay = 'u';
		}
	}

	switch (mWay)
	{
	case 'u':
		moveMonsterUp();
		break;
	case 'd':
		moveMonsterDown();
		break;
	case 'l':
		moveMonsterLeft();
		break;
	case 'r':
		moveMonsterRight();
		break;
	}

	mStep++;
	*/
}

void PacmanMonster::paint(HDC ihdc)
{
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush);

	::Ellipse(ihdc,
		(int)(mCoorX) - kRadius,
		(int)(mCoorY) - kRadius,
		(int)(mCoorX) + kRadius,
		(int)(mCoorY) + kRadius);

	::SelectObject(ihdc, wOldBrush);
}