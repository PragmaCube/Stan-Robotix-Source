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
	BoatsPosition mBoatsPosition;

	HBRUSH getBrush(int i, int i2);
	void defineDefautBrush();

	const int mLeftBoardCoor = 400;
	const int mTopBoardCoor  = 100;
	const int mSizeCell= 40;
	const int mRadiusToken = 15;
};

