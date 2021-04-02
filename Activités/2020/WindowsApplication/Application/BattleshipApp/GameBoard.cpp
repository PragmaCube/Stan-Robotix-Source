#include "GameBoard.h"
#include "BoatsPosition.h"
#include <string>
#include <sstream>

GameBoard::GameBoard()
{
	defineDefautBrush();
	mShots = 0;
	mHits = 0;
	mMissed = 0;
	mClick = true;
	reset();
}

void GameBoard::defineDefautBrush() //cr�ation des pinceaux de couleurs
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

void GameBoard::reset() //r�initialisation de la table de jeux
{
	mBoatsPosition.resetSetState();
}

void GameBoard::click(int x, int y) //cliquer sur un cercle pour changer l'�tat de la position
{
	const int wLeftBorder     = mkLeftBoardCoor- mkRadiusToken;
	const int wTopBorder      = mkTopBoardCoor - mkRadiusToken;
	const int wTotalGridSize  = 10 * mkSizeCell;
	int wRowClick = -1;
	int wColumnClick = -1;
		if (
			(wLeftBorder < x) && (x < wLeftBorder + wTotalGridSize) &&
			(wTopBorder < y) && (y < wTopBorder + wTotalGridSize)
			)
		{
			wRowClick = (y - wTopBorder) / mkSizeCell;
			wColumnClick = (x - wLeftBorder) / mkSizeCell;
		}
		if (mClick == true) //boucle permettant de d�scativer le clique pour jouer en fin de partie
		{
			if ((wRowClick != -1) && (wColumnClick != -1))
			{
				int wPositionState = mBoatsPosition.getGridState(wColumnClick, wRowClick);

				switch (wPositionState)
				{
				case BoatsPosition::eBoat: //quand la position est une partie de b�teau cacher
					mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eHit); //appel d'une fonction qui va chamger l'�tat de la position en partie du bateau touch�e dans le tableau de l'�tat de chaque position
					mBoatsPosition.setDestroyBoatColor(); //appel d'une fonction qui v�rifie si il y a un bateau trouv� � 100%, comme �a le b�teau prendra une certaine couleur
					mShots++; //met � jour le conpteur de tirs
					mHits++; //met � jour le compteur de tirs r�ussis
					break;
				case BoatsPosition::eSea: //quand la position est de l'eau
					mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eMiss);//appel d'une fonction qui va chamger l'�tat de la position en eau visible dans le tableau de l'�tat de chaque position
					mShots++; //met � jour le conpteur de tirs
					mMissed++;//met � jour le compteur de tirs rat�s
					break;
				}
			}
		}
}

void GameBoard::drawGameBoard(HDC ihdc, RECT& iPaintArea) //cr�ation du tableau de jeu
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
			//coloriagre du cercle, la couleur selon l'�tat de la position
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
	//�criture des lettre en ordonn�e
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
	//�criture des chiffres et le nombre en abscisse 
	for (int i4 = 0; i4 < 10; i4++)
	{
		if (i4 == 9)
		{
			wlast = 2;
		}
		std::wstring wChar = wnumbers.substr(i4, wlast);
		RECT wTextArea = { 395 + i4 * 40, 60, 2000, 2000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			(int)(DT_LEFT | DT_BOTTOM));
	}
	//Affiche la rogression de la partie, nombre de bateaux restant 
	std::wstring wChar = wBoats.substr(0, 20);
	RECT wTextArea = {170, 105, 2000, 2000};
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));
	//Affiche le nombre de tirs effectu�s
	wChar = wShots.substr(0, 20);
	wTextArea = { 170, 130, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));
	//Affiche le nombre de tirs r�ussis
	wChar = wHits.substr(0, 20);
	wTextArea = { 170, 155, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));
	//Affiche le nombre de tirs rat�s
	wChar = wMissed.substr(0, 20);
	wTextArea = { 170, 180, 2000, 2000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));
	//Affiche victoire quand le joueur a trouv� tout les bateaux(= 20 tirs touch�s)
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
	//Affiche d�faite quand le jour a trouv� tout les positions de l'eau(80 positions), j'ai touv� un specimen qui a �t� capable de perdre
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

HBRUSH GameBoard::getBrush(int x, int y) //fonction qui d�finit la couleur du pinceau pour une certaine position en fonction de l'�tat
{
	int wPositionState = mBoatsPosition.getGridState(y, x);//r�cup�ration de l'�tat � la position i2 i
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
