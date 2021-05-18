#pragma once

#include <string>
#include <Windows.h>
#include "BoatsPosition.h"

class GameBoard
{
public:
	GameBoard();

	void reset();

	void drawGameBoard(HDC ihdc, RECT& iPaintArea);

	void click(int iX, int iY);

private:
	HBRUSH mBlackBrush;
	HBRUSH mRedBrush;
	HBRUSH mGreenBrush;
	HBRUSH mGrayBrush;
	HBRUSH mWhiteBrush;
	HBRUSH mBlueBrush;
	HBRUSH mPurpleBrush;
	HBRUSH mOrangeBrush;
	HBRUSH mYellowBrush;
	BoatsPosition mBoatsPosition;

	const static int mkLeftBoardCoor = 400;
	const static int mkTopBoardCoor  = 100;
	const static int mkSizeCell      = 40;
	const static int mkRadiusToken   = 15;

	int mShots;
	int mMissed;
	int mHits;

	bool mClick;

	void displayText(int x, int y, std::wstring iText, int iStart, int iNumberOfCaracters, HDC ihdc, RECT& iPaintArea);
	std::wstring getStringToDisplay(const std::wstring& iText, int iNumber);

	HBRUSH getBrush(int iX, int iY);
	void defineDefautBrush();
};

