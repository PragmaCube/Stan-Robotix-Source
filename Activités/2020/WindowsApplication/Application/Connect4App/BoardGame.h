#pragma once
#include <windows.h>
#include "Token.h"
#include <vector>

class BoardGame
{
private: 
	const int kSizeTopCell = 117; 
	const int kSizeSideCell = 102;
	const int kTopBorder = 50; 
	const int kLeftBorder = 0;


	int mGridState[7][6];
	int mWinner;

	std::vector<Token> mTokenList;

	int getColumn(int iPosX);
	int getRow(int iPosX, int iTokenColor);

	RECT mDrawingRect;

	void addToken(int iPosX, int iColor);
	void rowConnect( int iColor);
	void columnConnect(int iColor); 
	void diagonalUpConnect(int iColor);
	void diagonalDownConnect(int iColor);

	bool mClick = true;

public:
	BoardGame();

	void paint(HDC ihdc, RECT& iPaintArea);
	void resetGame(); 

	void addRedToken(int iPosX);
	void addBlueToken(int iPosX);
	
	
	
};

