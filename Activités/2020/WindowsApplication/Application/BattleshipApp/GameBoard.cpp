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
	mGrayBrush = CreateSolidBrush(RGB(125, 125, 125));
	mWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
}

void GameBoard::reset()
{
	mBoatsPosition.resetSetState();
}

void GameBoard::drawGameBoard(HDC ihdc, RECT& iPaintArea)
{
	int x = 400;
	int y = 100;
	int wlast = 1;
	std::wstring wletters = L"ABCDEFGHIJ";
	std::wstring wnumbers = L"12345678910";
	int wRadius = 15;
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mWhiteBrush);

	static bool wDebugDrawGreen = true;
	static bool wDebugDrawBlack = true;
	static bool wDebugDrawRed   = true;
	static bool wDebugDrawGray = true;

	for (int i = 0; i < 10; i++)
	{
		for (int i2 = 0; i2 < 10; i2++)
		{
			HBRUSH wDrawingBrush = getBrush(i, i2);

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
				(int)(x + i2 * 40) - wRadius,/*x*/
				(int)(y + i * 40) - wRadius,/*y*/
				(int)(x + i2 * 40) + wRadius,/*x*/
				(int)(y + i * 40) + wRadius);/*y*/
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

	