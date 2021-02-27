#include "BoardGame.h"

BoardGame::BoardGame() {
	mTokenList.resize(42); // =6*7 
}
void BoardGame::paint(HDC ihdc, RECT& iPaintArea)
{   
	
	for (int i = iPaintArea.top+50; i < iPaintArea.bottom; i += kSizeSideCell) {

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

	/*if (mColor = true)
	{
		::Ellipse(ihdc,
			(int)(100)-100,
			(int)(25)-100,
			(int)(100)+100,
			(int)(25)+100);

		HGDIOBJ wOldBrush = ::SelectObject(ihdc, mColor.mBlueBrush);


		::FloodFill(ihdc, 100, 25, RGB(0, 0, 0));

		::SelectObject(ihdc, wOldBrush);
	}*/
}

void BoardGame::AddRedToken(int iPosX, int iPosY)
{  
	if (mColor = false)
	{
		mRed.setPosition(iPosX, iPosY);
	}
	
}

void BoardGame::AddBlueToken(int iPosX, int iPosY)
{
	if (mColor = true)
	{
		mBlue.setPosition(iPosX, iPosY);
	}
	
}

void BoardGame::InitArray()
{
	int mGridState[6][7];

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; i < 8; i++)
		{
			mGridState[i][j] = 0;

		}
	}
}

void BoardGame::click(int iPosX, int iPosY)
{
	if ((kLeftBorder < iPosX) && (iPosX < kLeftBorder + (kSizeTopCell*7)) && (kTopBorder < iPosY) && (iPosY < kTopBorder + (kSizeSideCell*6))) // click dans l'espace de jeu
		
	{
		mRow = (iPosY - kTopBorder) / kSizeSideCell;
		mColumn = (iPosX - kLeftBorder) / kSizeTopCell;
	}
}

// dessiner un petit cercle de la couleur du jeton qui doit etre poser
