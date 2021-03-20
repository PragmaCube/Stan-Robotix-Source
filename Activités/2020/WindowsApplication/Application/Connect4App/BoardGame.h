#pragma once
#include <windows.h>
#include "Token.h"
#include <vector>

class BoardGame
{
private: 
	int mRow;
	int mColumn;
	const int kSizeTopCell = 117; 
	const int kSizeSideCell = 102;
	const int kTopBorder = 50;
	const int kLeftBorder = 0;

	bool mConnect;

	int mGridState[6][7];

	enum { eNothing, eRed, eBlue };

	std::vector<Token> mTokenList;

	int getColumn(int iPosX);
	int getRow( int iPosX);

public:
	BoardGame();
	void paint(HDC ihdc, RECT& iPaintArea);
	void AddRedToken(int iPosX);
	void AddBlueToken(int iPosX);
	void InitArray();
	void CheckConnect(int iColumn, int iRow);
	

	Token mRed;
	Token mBlue;
	Token mToken;
	

};

