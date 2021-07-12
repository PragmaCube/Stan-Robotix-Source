#include "PacmanGameBoard.h"

void PacmanGameBoard::initializeMap()
{
	reset();
	buildMap();
	extraTrails();
}

void PacmanGameBoard::reset()
{
	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			mMap[y][x] = eVoid;
		}
	}
}

void PacmanGameBoard::buildMap()
{
	defineBorders();
	buildBloc(2,2);
	buildBloc(6,2);
	buildBloc(6,6);
	buildBloc(2,6);
}

void PacmanGameBoard::defineBorders()
{
	for (int x = 0; x < 11; x++)
	{
		mMap[0][x] = eWall;
	}
	for (int x2 = 0; x2 < 11; x2++)
	{
		mMap[10][x2] = eWall;
	}
	for (int y = 0; y < 11; y++)
	{
		mMap[y][0] = eWall;
	}
	for (int y2 = 0; y2 < 11; y2++)
	{
		mMap[y2][10] = eWall;
	}
}

void PacmanGameBoard::buildBloc(int X, int Y)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mMap[Y + y][X + x] = eWall;
		}
	}
}

void PacmanGameBoard::extraTrails()
{
	for (int y = 0; y < 7; y++)
	{
		mMap[2+y][3] = eVoid;
	}

	for (int y2 = 3; y2 < 8; y2+=4 )
	{
		for (int x = 6; x < 9; x++)
		{
			mMap[y2][x] = eVoid;
		}
	}
}

bool PacmanGameBoard::isWall(unsigned int x, unsigned int y)
{
	bool wIsWall = true;

	if ((x < 11) && (y < 11))
	{
		wIsWall = mMap[y][x] == eWall;
	}
	return wIsWall;
}

void PacmanGameBoard::drawMap(HDC ihdc, RECT& iPaintArea)
{
	int x = 350;
	int y = 100;
	for (int kX = 0; kX < 11; kX++)
	{
		for (int kY = 0; kY < 11; kY++)
		{
			if (mMap[kY][kX] == eVoid)
			{
				::SelectObject(ihdc, mBlackBrush);
			}
			else
			{
				::SelectObject(ihdc, mBlueBrush);
			}

			::Rectangle(
				ihdc,
				(x + kX * 40) - 20,
				(y + kY * 40) - 20,
				(x + kX * 40) + 20,
				(y + kY * 40) + 20);
		}
	}
}