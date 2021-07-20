#include "PacmanGameBoard.h"
#include "../../resource.h"
#include <windowsx.h>

extern HINSTANCE hInst;                                // instance actuelle;

static int mInitialMap[31][28] = 
{   
 //     1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,    
/*01*/{eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW},
/*02*/{eW,eB,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eW,eW,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eB,eW},
/*03*/{eW,eP,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eF,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eP,eW},
/*04*/{eW,eP,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eP,eW},
/*05*/{eW,eP,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eP,eW},
/*06*/{eW,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eW},
/*07*/{eW,eP,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eP,eW},
/*08*/{eW,eP,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eP,eW},
/*09*/{eW,eP,eP,eP,eP,eP,eP,eW,eW,eP,eP,eP,eP,eW,eW,eP,eP,eP,eP,eW,eW,eP,eP,eP,eF,eP,eP,eW},
/*10*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*11*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*12*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*13*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eS,eS,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*14*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eS,eS,eS,eS,eS,eS,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*15*/{eW,eT,eP,eP,eP,eP,eP,eP,eP,eP,eW,eS,eS,eS,eS,eS,eS,eW,eP,eP,eP,eP,eP,eP,eP,eP,eT,eW},
/*16*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eS,eS,eS,eS,eS,eS,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*17*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*18*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*19*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*20*/{eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW},
/*21*/{eW,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eW,eW,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eW},
/*22*/{eW,eP,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eP,eW},
/*23*/{eW,eP,eW,eW,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eP,eW,eW,eW,eW,eP,eW},
/*24*/{eW,eP,eP,eP,eW,eW,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eW,eW,eP,eP,eP,eW},
/*25*/{eW,eW,eW,eP,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eP,eW,eW,eW},
/*26*/{eW,eW,eW,eP,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eP,eW,eW,eW},
/*27*/{eW,eP,eP,eP,eP,eP,eP,eW,eW,eP,eP,eP,eP,eW,eW,eP,eP,eP,eP,eW,eW,eP,eP,eP,eP,eP,eP,eW},
/*28*/{eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW},
/*29*/{eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW,eW,eP,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eP,eW},
/*30*/{eW,eB,eP,eP,eP,eP,eF,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eP,eB,eW},
/*31*/{eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW,eW},
};

PacmanGameBoard::PacmanGameBoard() : mIsInit(false), mIsDebuggingLayout(false)
{

}

void PacmanGameBoard::initializeMap()
{
	reset();	
}

void PacmanGameBoard::toggleDebugging()
{
	mIsDebuggingLayout = !mIsDebuggingLayout;
}

void PacmanGameBoard::reset()
{
	for (int x = 0; x < mNbRows; x++)
	{
		for (int y = 0; y < mNbColumns; y++)
		{
			mMap[y][x] = mInitialMap[y][x];
		}
	}
}

bool PacmanGameBoard::isWall(unsigned int x, unsigned int y)
{
	bool wIsWall = true;

	if ((x < mNbRows) && (y < mNbColumns))
	{
		wIsWall = mMap[y][x] == eWall;
	}

	return wIsWall;
}

void PacmanGameBoard::drawMap(HDC ihdc, RECT& iPaintArea)
{
	static bool wDevelopMaze = true;
	if (wDevelopMaze)
	{
		if (!mIsInit)
		{
			HBITMAP wInitialMazeBitmap = LoadBitmap(hInst, L"IDB_BITMAPMAZE");
			mIsInit = true;

			mMazeInCache = ::CreateCompatibleDC(ihdc);
			HBITMAP hOldBmp = (HBITMAP)::SelectObject(mMazeInCache, wInitialMazeBitmap);

			BITMAP wBitmap;
			GetObject(wInitialMazeBitmap, sizeof(BITMAP), reinterpret_cast<LPVOID>(&wBitmap));

			StretchBlt(ihdc,
				0,
				0,
				iPaintArea.right - iPaintArea.left,
				iPaintArea.bottom - iPaintArea.top,
				mMazeInCache, 0, 0, wBitmap.bmWidth, wBitmap.bmHeight, SRCCOPY);

			BitBlt(mMazeInCache,
				0,
				0,
				iPaintArea.right - iPaintArea.left,
				iPaintArea.bottom - iPaintArea.top,
				ihdc, 0, 0, SRCCOPY);

			mIsInit = true;
		}
		BitBlt(ihdc,
			iPaintArea.left,
			iPaintArea.top,
			iPaintArea.right - iPaintArea.left,
			iPaintArea.bottom - iPaintArea.top,
			mMazeInCache, 0, 0, SRCCOPY);

		if (mIsDebuggingLayout)
		{
			drawMemory(ihdc, iPaintArea);
		}
	}
}

void PacmanGameBoard::drawMemory(HDC ihdc, RECT& iPaintArea)
{
	const float wSideX = (iPaintArea.right-iPaintArea.left)/mNbRows;
	const float wSideY = (iPaintArea.bottom - iPaintArea.top) /mNbColumns;
	int x = iPaintArea.left;
	int y = iPaintArea.top;

	for (int kX = 0; kX < mNbRows; kX++)
	{
		for (int kY = 0; kY < mNbColumns; kY++)
		{
			switch (mMap[kY][kX])
			{
			case eVoid:
				::SelectObject(ihdc, mBlackBrush);
				break;
			case eWall:
				::SelectObject(ihdc, mBlueBrush);
				break;
			case ePoint:
				::SelectObject(ihdc, mYellowBrush);
				break;
			case eBonus:
				::SelectObject(ihdc, mOrangeBrush);
				break;
			case eFruit:
				::SelectObject(ihdc, mRedBrush);
				break;
			case eSpawn:
				::SelectObject(ihdc, mGreenBrush);
				break;
			case eTP:
				::SelectObject(ihdc, mPurpleBrush);
			}

			::Rectangle(
				ihdc,
				(x + kX * wSideX),
				(y + kY * wSideY),
				(x + (kX+1) * wSideX),
				(y + (kY+1) * wSideY));
		}
	}
}