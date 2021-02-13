#pragma once

#include <string>
#include <Windows.h>
#include "BoatsPosition.h"

class GameBoard
{
public:
	GameBoard();

	void drawGameBoard(HDC ihdc, RECT& iPaintArea);
	HBRUSH getColour(int i, int i2);
	RECT mPositions[10][10];

	BoatsPosition mBoatsPosition;
	

private:
	HBRUSH mBlackBrush;
	HBRUSH mRedBrush;
	HBRUSH mGreenBrush;
	HBRUSH mGrayBrush;
};

