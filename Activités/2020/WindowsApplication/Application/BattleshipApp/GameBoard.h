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

private:
	HBRUSH mBlackBrush;
	HBRUSH mRedBrush;
	HBRUSH mGreenBrush;
	HBRUSH mGrayBrush;
	HBRUSH mWhiteBrush;
	BoatsPosition mBoatsPosition;

	HBRUSH getBrush(int i, int i2);
	void defineDefautBrush();
};

