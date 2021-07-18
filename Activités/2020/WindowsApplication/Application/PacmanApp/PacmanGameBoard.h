#pragma once

#include <Windows.h>
#include <windowsx.h>

class PacmanGameBoard
{
public:
	PacmanGameBoard();

	void drawMap(HDC ihdc, RECT& iPaintArea);
	void initializeMap();

	bool isWall(unsigned int x, unsigned int y);

private:
	enum { eVoid, eWall };
	int mMap[11][11];

	const HBRUSH mBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	const HBRUSH mBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

	void reset();
	void buildMap();
	void defineBorders();
	void buildBloc(int X, int Y);
	void extraTrails();

	bool mIsInit;
	HBITMAP hInitialMazeBitmap;
	HDC mLocalDC;
	int mBitmapWidth, mBitmapHeight;
};

