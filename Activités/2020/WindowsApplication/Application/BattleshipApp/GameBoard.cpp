#include "GameBoard.h"
#include "BoatsPosition.h"
#include <string>

GameBoard::GameBoard()
{
	defineDefautBrush();

	reset();
}

void GameBoard::defineDefautBrush()
{
	mBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	mRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	mGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	mGrayBrush = CreateSolidBrush(RGB(200, 200, 200));
	mWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
}

void GameBoard::reset()
{
	mBoatsPosition.resetSetState();
}

void GameBoard::click(int iX, int iY)
{
	const int wLeftBorder     = mLeftBoardCoor- mRadiusToken;
	const int wTopBorder      = mTopBoardCoor - mRadiusToken;
	const int wTotalGridSize  = 10 * mSizeCell;

	int wRowClick = -1;
	int wColumnClick = -1;
	if (
		 (wLeftBorder < iX) && (iX < wLeftBorder + wTotalGridSize) &&
		 (wTopBorder < iY)  && (iY < wTopBorder + wTotalGridSize)
	   )
	{
      wRowClick   = (iY - wTopBorder)/ mSizeCell;
	  wColumnClick= (iX - wLeftBorder) / mSizeCell;
	}

	if ((wRowClick != -1) && (wColumnClick != -1))
	{
		int wPositionState = mBoatsPosition.getGridState(wColumnClick, wRowClick);
		
		switch(wPositionState)
		{
		case BoatsPosition::eBoat:
			mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eHit);
			break;
		case BoatsPosition::eSea:
			mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eMiss);
			break;
		}
	}
}

void GameBoard::drawGameBoard(HDC ihdc, RECT& iPaintArea)
{
	int wlast = 1;
	std::wstring wletters = L"ABCDEFGHIJ";
	std::wstring wnumbers = L"12345678910";
	
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mWhiteBrush);

	static bool wDebugDrawGreen = true;
	static bool wDebugDrawBlack = true;
	static bool wDebugDrawRed   = true;
	static bool wDebugDrawGray = true;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			HBRUSH wDrawingBrush = getBrush(x, y);

			if ((mBlackBrush == wDrawingBrush && wDebugDrawBlack) ||
				(mRedBrush   == wDrawingBrush && wDebugDrawRed) ||
				(mGreenBrush == wDrawingBrush && wDebugDrawGreen) ||
				(mGrayBrush  == wDrawingBrush && wDebugDrawGray))
			{
				::SelectObject(ihdc, wDrawingBrush);
			}
			else
			{
				::SelectObject(ihdc, mWhiteBrush);
			}

			::Ellipse(ihdc,
				(int)(mLeftBoardCoor + y * mSizeCell) - mRadiusToken,/*x*/
				(int)(mTopBoardCoor  + x * mSizeCell) - mRadiusToken,/*y*/
				(int)(mLeftBoardCoor + y * mSizeCell) + mRadiusToken,/*x*/
				(int)(mTopBoardCoor  + x * mSizeCell) + mRadiusToken);/*y*/
		}
	}

	::SelectObject(ihdc, wOldBrush);

	for (int i3 = 0; i3 < 10; i3++)
	{
		std::wstring wChar = wletters.substr(i3, 1);
		RECT wTextArea = { 350, 95+i3*40, 2000, 2000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			((int)DT_LEFT | DT_BOTTOM));
	}

	for (int i4 = 0; i4 < 10; i4++)
	{
		if (i4 == 9)
		{
			wlast = 2;
		}
		std::wstring wChar = wnumbers.substr(i4, wlast);
		RECT wTextArea = { 395+i4*40, 60, 2000, 2000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			(int)(DT_LEFT | DT_BOTTOM ));
	}
}

HBRUSH GameBoard::getBrush(int i, int i2)
{
	int wPositionState = mBoatsPosition.getGridState(i2,i);
	HBRUSH wSelect= 0;
	switch (wPositionState)
	{
	case 1:
		wSelect = mBlackBrush;
		break;

	case 2: wSelect = mGrayBrush;
		break;

	case 3: wSelect = mGreenBrush;
		break;

	case 4: wSelect = mRedBrush;
		break;
	}
	return wSelect;
}

	