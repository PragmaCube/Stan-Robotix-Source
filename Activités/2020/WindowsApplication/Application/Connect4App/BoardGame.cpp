#include "BoardGame.h"
#include <string>


BoardGame::BoardGame() 
{
	mTokenList.resize(42); // =6*7 
}

void BoardGame::paint(HDC ihdc, RECT& iPaintArea)
{	
	mDrawingRect = iPaintArea;

	for (int i = iPaintArea.top+kTopBorder; i < iPaintArea.bottom; i += kSizeSideCell) 
	{

		::MoveToEx(ihdc, iPaintArea.left, i, nullptr);
		::LineTo(ihdc, iPaintArea.right, i);

	} // dessiner les lignes horizontales

	for (int j = iPaintArea.left; j < iPaintArea.right; j += kSizeTopCell)
	{
		::MoveToEx(ihdc, j, iPaintArea.top + kTopBorder, nullptr);
		::LineTo(ihdc, j, iPaintArea.bottom);

	} //dessiner les lignes verticales

	int wNbToken = mTokenList.size();
	for (int i = 0; i < wNbToken; i++)
	{
     	Token wToken = mTokenList[i];
		wToken.draw(ihdc);

	}

	if (mWinner == Token::eRed)
	{
		std::wstring wWinner = L"Les rouges sont les gagnants !!";
		::DrawText(
			ihdc,
			wWinner.c_str(),
			wWinner.length(),
			&iPaintArea,
			DT_CENTER | DT_CENTER);

		mClick = false;

	} else if (mWinner == Token::eBlue)
	{
		std::wstring wWinner = L"Les bleus sont les gagnants !!";
		::DrawText(
			ihdc,
			wWinner.c_str(),
			wWinner.length(),
			&iPaintArea,
			DT_CENTER | DT_CENTER);
		mClick = false;
	}
}

void BoardGame::addRedToken(int iPosX)
{   
	addToken(iPosX, Token::eRed);
	rowConnect(Token::eRed);
	columnConnect(Token::eRed);
	diagonalUpConnect(Token::eRed);
	diagonalDownConnect(Token::eBlue);
}

void BoardGame::addBlueToken(int iPosX)
{
	addToken(iPosX, Token::eBlue);
	rowConnect(Token::eBlue);
	columnConnect(Token::eBlue);
	diagonalUpConnect(Token::eBlue);
	diagonalDownConnect(Token::eRed);
}

void BoardGame::addToken(int iPosX, int iColor)
{  
	int wSelectedColumn = getColumn(iPosX);
	int wSelectedRow = getRow(wSelectedColumn, iColor);


	if (wSelectedRow != -1 && wSelectedColumn != -1)
	{
		int wCenterX = (wSelectedColumn * kSizeTopCell) + mDrawingRect.left + kSizeTopCell / 2;
		int wCenterY = (wSelectedRow * kSizeSideCell) + (mDrawingRect.top + kTopBorder) + kSizeSideCell / 2;

		Token wToken;
		wToken.setPosition(wCenterX, wCenterY);
		wToken.setType(iColor);

		mTokenList.push_back(wToken);
	}
}

void BoardGame::rowConnect(int iColor)
{
	for (int j = 6; j >= 0; j--)
	{
		for (int h = 5; h >= 0; h--)
		{
			if (mGridState[j][h] == iColor)
			{
				if (mGridState[j + 1][h] == iColor)
				{
					if (mGridState[j + 2][h] == iColor)
					{
						if (mGridState[j + 3][h] == iColor)
						{
							mWinner = iColor;
						}
					}
				}
			}

		}

	} // alignement sur une ligne 
}


void BoardGame::columnConnect(int iColor)
{
	for (int j = 6; j >= 0; j--)
	{
		for (int h = 5; h >= 0; h--)
		{
			if (mGridState[j][h] == iColor)
			{
				if (mGridState[j][h + 1] == iColor)
				{
					if (mGridState[j][h + 2] == iColor)
					{
						if (mGridState[j][h + 3] == iColor)
						{
							mWinner = iColor;
						}
					}
				}
			}

		}

	}// alignement sur une colonne
}

void BoardGame::diagonalUpConnect(int iColor)
{
	for (int j = 0; j <= 6; j++)
	{
		for (int h = 5; h >= 0; h--)
		{
			if (mGridState[j][h] == iColor)
			{
				if (mGridState[j + 1][h - 1] == iColor)
				{
					if (mGridState[j + 2][h - 2] == iColor)
					{
						if (mGridState[j + 3][h - 3] == iColor)
						{
							mWinner = iColor;
						}
					}
				}
			}

		}

	} // alignement sur une diagonale 
}

void BoardGame::diagonalDownConnect(int iColor)
{
	for (int j = 6; j >= 0; j--)
	{
		for (int h = 5; h >= 0; h--)
		{
			if (mGridState[j][h] == iColor)
			{
				if (mGridState[j - 1][h - 1] == iColor)
				{
					if (mGridState[j - 2][h - 2] == iColor)
					{
						if (mGridState[j - 3][h - 3] == iColor)
						{
							mWinner = iColor;
						}
					}
				}
			}

		}

	} // alignement diagnole qui dessans
}

int BoardGame::getColumn(int iPosX)
{
	int wColumn = -1; 

	if ((mDrawingRect.left < iPosX) && (iPosX < mDrawingRect.left + (kSizeTopCell * 7))) // click dans l'espace de jeu

	{
		wColumn = (iPosX-mDrawingRect.left) / kSizeTopCell;
	}

	return wColumn;
}

int BoardGame::getRow(int iPosX, int iTokenColor)
{
	int wRow = -1;

    for (int i = 5; i >= 0; i--)
	{
	    if (mGridState[iPosX][i] == Token::eNothing)
		{
		    wRow = i;
		    mGridState[iPosX][i] = iTokenColor;
			break;
		}
	}

	return wRow;
}

void BoardGame::resetGame()
{
	for (int i = 0; i <= 6; i++)
	{
		for (int j = 0; j <= 5; j++)
		{
			mGridState[i][j] = Token::eNothing;
		}
	}
}



