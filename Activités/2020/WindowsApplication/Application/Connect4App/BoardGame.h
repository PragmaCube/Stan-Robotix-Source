#pragma once
#include <windows.h>
#include "Token.h"
#include <vector>

class BoardGame
{
private: 
	int mRow;  // Enelever les proprietes inutiles
	int mColumn;
	const int kSizeTopCell = 117; 
	const int kSizeSideCell = 102;
	const int kTopBorder = 50; // Si inutile ... on enleve
	const int kLeftBorder = 0;

	bool mConnect; // Enelever les proprietes inutiles

	int mGridState[7][6];

	std::vector<Token> mTokenList;

	int getColumn(int iPosX);
	int getRow( int iPosX, int iTokenColor);

	RECT mDrawingRect;
	int mWinner;

	
	void CheckConnect(int iColumn, int iRow); // minuscule

	void addToken(int iPosX, int iColor);

public:
	BoardGame();

	void paint(HDC ihdc, RECT& iPaintArea);

	void InitArray(); // resetGame a la place

	void AddRedToken(int iPosX);
	void AddBlueToken(int iPosX);
	
	
};

