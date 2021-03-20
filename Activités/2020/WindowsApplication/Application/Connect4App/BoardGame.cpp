#include "BoardGame.h"

/*BoardGame::BoardGame() 
{
	mTokenList.resize(42); // =6*7 
	
}*/

void BoardGame::paint(HDC ihdc, RECT& iPaintArea)
{	
	for (int i = iPaintArea.top+50; i < iPaintArea.bottom; i += kSizeSideCell) 
	{

		::MoveToEx(ihdc, iPaintArea.left, i, nullptr);
		::LineTo(ihdc, iPaintArea.right, i);

	} // dessiner les lignes horizontales

	for (int j = iPaintArea.left; j < iPaintArea.right; j += kSizeTopCell)
	{
		::MoveToEx(ihdc, j, iPaintArea.top + 50, nullptr);
		::LineTo(ihdc, j, iPaintArea.bottom);

	} //dessiner les lignes verticales

	mRed.drawTokenRed(ihdc, iPaintArea);
	mBlue.drawTokenBlue(ihdc, iPaintArea);

	
}

void BoardGame::AddRedToken(int iPosX)
{   
	int wSelectedColumn = getColumn(iPosX);
    int wSelectedRow = getRow(wSelectedColumn);

	mRed.setPosition(wSelectedColumn * kSizeTopCell, wSelectedRow * kSizeSideCell);	// wSelectedColumn et wSelectedRow en coordonne pixel;
	
	mGridState[wSelectedRow][wSelectedColumn] = eRed;
	
}

void BoardGame::AddBlueToken(int iPosX)
{
	int wSelectedColumn = getColumn(iPosX);
	int wSelectedRow = getRow(wSelectedColumn);
	

	mBlue.setPosition(wSelectedColumn *kSizeTopCell, wSelectedRow*kSizeSideCell);	// wSelectedColumn et wSelectedRow en coordonne pixel;

	mGridState[wSelectedRow][wSelectedColumn] = eBlue;
}

int BoardGame::getColumn(int iPosX)
{
	
	int wColumn = 0;
	if ((kLeftBorder < iPosX) && (iPosX < kLeftBorder + (kSizeTopCell * 7))) // click dans l'espace de jeu

	{
		wColumn = iPosX / kSizeTopCell;
		wColumn = (kSizeTopCell * wColumn) - (kSizeTopCell / 2);
	}

	// TODO: d/terminer quelle colonne le joueur a clique, et determiner le centre de la colonne en abciss

	return wColumn;
}

int BoardGame::getRow(int iColumn)
{
	int wRow = 0;

	for (int i = 0; i < 7; i++)
	{
		if (mGridState[i][getColumn(iColumn)] == eNothing)
		{
			wRow = 6;
		}
		else
		{
			wRow = i - 1;
		}
	}
	//int mGridState[6][7];
   // TODO BY LUNE


	return wRow;
}

void BoardGame::InitArray()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; i < 8; i++)
		{
			mGridState[i][j] = eNothing;

		}
	}
}
/*
void BoardGame::click(int iPosX, int iPosY)
{
	if ((kLeftBorder < iPosX) && (iPosX < kLeftBorder + (kSizeTopCell*7)) && (kTopBorder < iPosY) && (iPosY < kTopBorder + (kSizeSideCell*6))) // click dans l'espace de jeu
		
	{
		mRow = (iPosY - kTopBorder) / kSizeSideCell;
		mColumn = (iPosX - kLeftBorder) / kSizeTopCell;

		mGridState[mRow][mColumn] = 1;
	}
}*/


