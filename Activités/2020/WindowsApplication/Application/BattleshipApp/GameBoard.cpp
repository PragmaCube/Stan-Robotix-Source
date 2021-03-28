#include "GameBoard.h"
#include "BoatsPosition.h"
#include <string>
#include <sstream>

GameBoard::GameBoard()
{
	defineDefautBrush();

	reset();
}

void GameBoard::defineDefautBrush() //création des pinceaux de couleurs
{
	mBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	mRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	mGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	mGrayBrush = CreateSolidBrush(RGB(0, 0, 0));
	mBlueBrush = CreateSolidBrush(RGB(0, 0, 255));;
	mPurpleBrush = CreateSolidBrush(RGB(128, 0, 128));;
	mOrangeBrush = CreateSolidBrush(RGB(255, 165, 0));;
	mYellowBrush = CreateSolidBrush(RGB(255, 255, 0));;
}

void GameBoard::reset() //réinitialisation de la table de jeux
{
	mBoatsPosition.resetSetState();
}

void GameBoard::click(int iX, int iY) //cliquer sur un cercle pour changer l'état de la position
{
	const int wLeftBorder     = mLeftBoardCoor- mRadiusToken;
	const int wTopBorder      = mTopBoardCoor - mRadiusToken;
	const int wTotalGridSize  = 10 * mSizeCell;
	int wRowClick = -1;
	int wColumnClick = -1;
		if (
			(wLeftBorder < iX) && (iX < wLeftBorder + wTotalGridSize) &&
			(wTopBorder < iY) && (iY < wTopBorder + wTotalGridSize)
			)
		{
			wRowClick = (iY - wTopBorder) / mSizeCell;
			wColumnClick = (iX - wLeftBorder) / mSizeCell;
		}
		if (mClick == true)
		{
			if ((wRowClick != -1) && (wColumnClick != -1))
			{
				int wPositionState = mBoatsPosition.getGridState(wColumnClick, wRowClick);

				switch (wPositionState)
				{
				case BoatsPosition::eBoat:
					mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eHit);
					mBoatsPosition.setDestroyBoatColor();
					mShots++;
					mHits++;
					break;
				case BoatsPosition::eSea:
					mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eMiss);
					mShots++;
					mMissed++;
					break;
				}
			}
		}
}

void GameBoard::drawGameBoard(HDC ihdc, RECT& iPaintArea) //création du tableau de jeu
{
	int wlast = 1; char wBuffer[10];
	std::wstring wletters = L"ABCDEFGHIJ";

	std::wstring wnumbers = L"12345678910";

	std::wostringstream wBoatsText;
	wBoatsText << (L"Boats remaining : ") << mBoatsPosition.getBoatsRemaining();
	std::wstring wBoats = wBoatsText.str();
	
	std::wostringstream wShotsText;
	wShotsText << (L"Shots : ") <<  mShots;
	std::wstring wShots = wShotsText.str();

	std::wostringstream wHitsText;
	wHitsText << (L"Hits : ") << mHits;
	std::wstring wHits = wHitsText.str();

	std::wostringstream wMissedText;
	wMissedText << (L"Missed : ") << mMissed;
	std::wstring wMissed = wMissedText.str();
	
	std::wstring wVictory = L"Victory!!! Press N for restart.";

	std::wstring wDefeat = L"Defeat... Press N for restart.";

	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mWhiteBrush);

	static bool wDebugDrawGreen    = true;
	static bool wDebugDrawBlack    = true;
	static bool wDebugDrawRed      = true;
	static bool wDebugDrawGray     = true;
	static bool wDebugDrawBlue     = true;
	static bool wDebugDrawPurple   = true;
	static bool wDebugDrawOrange   = true;
	static bool wDebugDrawYellow   = true;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			//coloriagre du cercle, la couleur selon l'état de la position
			HBRUSH wDrawingBrush = getBrush(x, y);

			if ((mBlackBrush == wDrawingBrush && wDebugDrawBlack) ||
				(mRedBrush   == wDrawingBrush && wDebugDrawRed) ||
				(mGreenBrush == wDrawingBrush && wDebugDrawGreen) ||
				(mGrayBrush  == wDrawingBrush && wDebugDrawGray) ||
				(mBlueBrush == wDrawingBrush && wDebugDrawBlue) ||
				(mPurpleBrush == wDrawingBrush && wDebugDrawPurple) ||
				(mOrangeBrush == wDrawingBrush && wDebugDrawOrange) ||
				(mYellowBrush == wDrawingBrush && wDebugDrawYellow))
			{
				::SelectObject(ihdc, wDrawingBrush);
			}
			else
			{
				::SelectObject(ihdc, mWhiteBrush);
			}
			//dessin du contour du cercle
			::Ellipse(ihdc,
				(int)(mkLeftBoardCoor + y * mkSizeCell) - mkRadiusToken,/*x*/
				(int)(mkTopBoardCoor  + x * mkSizeCell) - mkRadiusToken,/*y*/
				(int)(mkLeftBoardCoor + y * mkSizeCell) + mkRadiusToken,/*x*/
				(int)(mkTopBoardCoor  + x * mkSizeCell) + mkRadiusToken);/*y*/
		}
	}

	::SelectObject(ihdc, wOldBrush);
	//écriture des lettre en ordonnée
	for (int i3 = 0; i3 < 10; i3++)
	{
		std::wstring wChar = wletters.substr(i3, 1);
		RECT wTextArea = { 350, 95+i3*40, 2000, 2000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			((int)DT_LEFT | DT_BOTTOM));
	}
	//écriture des chiffres et le nombre en abscisse 
	for (int i4 = 0; i4 < 10; i4++)
	{
		if (i4 == 9)
		{
			wlast = 2;
		}
		std::wstring wChar = wnumbers.substr(i4, wlast);
		RECT wTextArea = { 395+i4*40, 60, 2000, 2000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			(int)(DT_LEFT | DT_BOTTOM ));
	}

	std::wstring wChar = wBoats.substr(0, 20);
	RECT wTextArea = {170, 105, 2000, 2000};
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));

	wChar = wShots.substr(0, 20);
	wTextArea = { 170, 130, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));

	wChar = wHits.substr(0, 20);
	wTextArea = { 170, 155, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));

	wChar = wMissed.substr(0, 20);
	wTextArea = { 170, 180, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));

	if (mHits == 20)
	{
		wChar = wVictory.substr(0, 30);
		wTextArea = { 170, 275, 5000, 5000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			(int)(DT_LEFT | DT_BOTTOM));
	}

	if (mMissed == 80)
	{
		wChar = wDefeat.substr(0, 30);
		wTextArea = { 170, 275, 5000, 5000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			(int)(DT_LEFT | DT_BOTTOM));
		mClick = false;
	}
}

HBRUSH GameBoard::getBrush(int i, int i2) //fonction qui définit la couleur du pinceau pour une certaine position en fonction de l'état
{
	int wPositionState = mBoatsPosition.getGridState(i2, i);//récupération de l'état à la position i2 i
	HBRUSH wSelect= 0;
	switch (wPositionState)
	{
	case 1:
		wSelect = mBlackBrush;
		break;

	case 2: wSelect = mGrayBrush;
		break;

	case 3: wSelect = mGreenBrush;
		break;

	case 4: wSelect = mRedBrush;
		break;

	case 5: wSelect = mYellowBrush;
		break;

	case 6: wSelect = mOrangeBrush;
		break;

	case 7: wSelect = mBlueBrush;
		break;

	case 8: wSelect = mPurpleBrush;
		break;
	}
	
	return wSelect;
}

void GameBoard::ResetStats()
{
	mShots = 0;
	mHits = 0;
	mMissed = 0;
	mClick = true;
}