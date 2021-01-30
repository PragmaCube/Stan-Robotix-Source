#pragma once

#include <string>
#include <Windows.h>

class GameBoard
{
public:
	GameBoard();

	void drawGameBoard(HDC ihdc, RECT& iPaintArea);

private:
	HBRUSH mBlackBrush;
};

