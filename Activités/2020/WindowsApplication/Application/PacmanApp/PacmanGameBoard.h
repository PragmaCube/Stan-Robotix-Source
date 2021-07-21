#pragma once

#include <Windows.h>
#include <windowsx.h>

enum { eVoid, eWall, ePoint, eBonus, eFruit, eSpawn, eTP};
enum { eV, eW, eP, eB, eF, eS, eT}; //pour la carte memoire
	
class PacmanGameBoard
{
public:
	PacmanGameBoard();

	void drawMap(HDC ihdc, RECT& iPaintArea);
	void drawMemory(HDC ihdc, RECT& iPaintArea);
	void initializeMap();

	bool isWall(unsigned int x, unsigned int y);

	void toggleDebugging();

private:
	
	int mMap[31][28];

	const HBRUSH mBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	const HBRUSH mBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	const HBRUSH mYellowBrush = CreateSolidBrush(RGB(255, 255, 0));
	const HBRUSH mOrangeBrush = CreateSolidBrush(RGB(255, 165, 0));
	const HBRUSH mRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	const HBRUSH mGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	const HBRUSH mPurpleBrush = CreateSolidBrush(RGB(127, 0, 255));

	void reset();

	bool mIsInit;
	HDC mMazeInCache;

	bool mIsDebuggingLayout;
	
	const int mNbRows = 28;
	const int mNbColumns = 31;
	
};

