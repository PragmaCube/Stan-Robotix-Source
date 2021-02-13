#include "GameBoard.h"
#include "BoatsPosition.h"
#include <string>

GameBoard::GameBoard()
{
	mBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	mRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	mGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	mGrayBrush = CreateSolidBrush(RGB(125, 125, 125));
}
		

void GameBoard::drawGameBoard(HDC ihdc, RECT& iPaintArea)
{
	int wStateAttribution;
	int x = 400;
	int y = 100;
	int wlast = 1;
	std::wstring wletters = L"ABCDEFGHIJ";
	std::wstring wnumbers = L"12345678910";
	int wRadius = 15;
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBlackBrush);
	for (int i = 0; i < 10; i++)
	{
		;
		for (int i2 = 0; i2 < 10; i2++)
		{
			::Ellipse(ihdc,
				(int)(x + i2 * 40) - wRadius,/*x*/
				(int)(y + i * 40) - wRadius,/*y*/
				(int)(x + i2 * 40) + wRadius,/*x*/
				(int)(y + i * 40) + wRadius);/*y*/

			HGDIOBJ wOldBrush = ::SelectObject(ihdc, getColour(i, i2));
			::FloodFill(ihdc, x + i2 * 40, y + i * 40, RGB(0, 0, 0));
			::SelectObject(ihdc, wOldBrush);
			
			mPositions[i2][i].top = y + i * 40 - wRadius;
			mPositions[i2][i].left = x + i2 * 40 - wRadius;
			mPositions[i2][i].right = x + i2 * 40 + wRadius;
			mPositions[i2][i].bottom = y + i * 40 + wRadius;
		}
	}

	
	for (int i3 = 0; i3 < 10; i3++)
	{
		std::wstring wChar = wletters.substr(i3, 1);
		RECT wTextArea = { 350, 95+i3*40, 2000, 2000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			DT_LEFT | DT_BOTTOM);
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
			DT_LEFT | DT_BOTTOM);
	}
}

HBRUSH GameBoard::getColour(int i, int i2)
{
	int wPositionState = mBoatsPosition.getBoatsPosition(i2,i);
	HBRUSH wSelect= mBlackBrush;
	switch (wPositionState)
	{

	case 2: wSelect = mGrayBrush;
		break;

	case 3: wSelect = mGreenBrush;
		break;

	case 4: wSelect = mRedBrush;
		break;
	}
	return wSelect;
}

	