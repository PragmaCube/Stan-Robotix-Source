#include "GameBoard.h"
#include "BoatsPosition.h"
#include <string>
#include <sstream>

GameBoard::GameBoard() : mClick(true)
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
	mShots = 0;
	mHits = 0;
	mMissed = 0;
	mClick = true;
}

void GameBoard::click(int iX, int iY) //cliquer sur un cercle pour changer l'état de la position
{
	const int wLeftBorder     = mkLeftBoardCoor- mkRadiusToken;
	const int wTopBorder      = mkTopBoardCoor - mkRadiusToken;
	const int wTotalGridSize  = 10 * mkSizeCell;
	int wRowClick = -1;
	int wColumnClick = -1;
	if (
		(wLeftBorder < iX) && (iX < wLeftBorder + wTotalGridSize) &&
		(wTopBorder < iY) && (iY < wTopBorder + wTotalGridSize)
		)
	{
		wRowClick = (iY - wTopBorder) / mkSizeCell;
		wColumnClick = (iX - wLeftBorder) / mkSizeCell;
	}
	if (mClick == true) //boucle permettant de déscativer le clique pour jouer en fin de partie
	{
		if ((wRowClick != -1) && (wColumnClick != -1))
		{
			int wPositionState = mBoatsPosition.getGridState(wColumnClick, wRowClick);

			switch (wPositionState)
			{
			case BoatsPosition::eBoat: //quand la position est une partie de bâteau cacher
				mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eHit); //appel d'une fonction qui va chamger l'état de la position en partie du bateau touchée dans le tableau de l'état de chaque position
				mBoatsPosition.setDestroyBoatColor(); //appel d'une fonction qui vérifie si il y a un bateau trouvé à 100%, comme ça le bâteau prendra une certaine couleur
				mShots++; //met à jour le conpteur de tirs
				mHits++; //met à jour le compteur de tirs réussis
				break;
			case BoatsPosition::eSea: //quand la position est de l'eau
				mBoatsPosition.setGridState(wColumnClick, wRowClick, BoatsPosition::eMiss);//appel d'une fonction qui va chamger l'état de la position en eau visible dans le tableau de l'état de chaque position
				mShots++; //met à jour le conpteur de tirs
				mMissed++;//met à jour le compteur de tirs ratés
				break;
			}
		}
	}
}

std::wstring  GameBoard::getStringToDisplay(const std::wstring & iText, int iNumber)
{
	std::wostringstream wText;

	wText << iText << iNumber;

	return wText.str();
}

void GameBoard::drawGameBoard(HDC ihdc, RECT& iPaintArea) //création du tableau de jeu
{
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

	int wlast = 1; char wBuffer[10];
	std::wstring wLetters = L"ABCDEFGHIJ";
	//écriture des lettre en ordonnée
	for (int i3 = 0; i3 < 10; i3++)
	{
		displayText(350, 95 + i3 * 40, wLetters, i3, 1, ihdc, iPaintArea);
	}

	//écriture des chiffres et le nombre en abscisse
	std::wstring wNumbers = L"12345678910";
	for (int i4 = 0; i4 < 10; i4++)
	{
		if (i4 == 9)
		{
			wlast = 2;
		}
		displayText(395 + i4 * 40, 60, wNumbers, i4, wlast, ihdc, iPaintArea);
	}

	//Affiche la progression de la partie, nombre de bateaux restant
	std::wstring wBoats = getStringToDisplay(L"Boats remaining : ",
		                                     mBoatsPosition.getBoatsRemaining());
	displayText(170, 105, wBoats, 0, 30, ihdc, iPaintArea);

	//Affiche le nombre de tirs effectués
	std::wstring wShots = getStringToDisplay(L"Shots : ",
		                                     mShots);
	displayText(170, 130, wShots, 0, 30, ihdc, iPaintArea);

	//Affiche le nombre de tirs réussis
	std::wstring wHits = getStringToDisplay(L"Hits : ",
		mHits);
	displayText(170, 155, wHits, 0, 30, ihdc, iPaintArea);

	//Affiche le nombre de tirs ratés
	std::wstring wMissed = getStringToDisplay(L"Missed : ",
		                                      mMissed);
	displayText(170, 180, wMissed, 0, 30, ihdc, iPaintArea);

	//Affiche victoire quand le joueur a trouvé tout les bateaux(= 20 tirs touchés)
	if (mHits == 20)
	{
		const std::wstring wVictory = L"Victory!!! Press N for restart.";
		displayText(170, 275, wVictory, 0, 30, ihdc, iPaintArea);
		mClick = false;
	}

	//Affiche défaite quand le jour a trouvé tout les positions de l'eau(80 positions), j'ai touvé un specimen qui a été capable de perdre
	if (mMissed == 80)
	{
		const std::wstring wDefeat = L"Defeat... Press N for restart.";
		displayText(170, 275, wDefeat, 0, 30, ihdc, iPaintArea);
		mClick = false;
	}
}

HBRUSH GameBoard::getBrush(int iX, int iY) //fonction qui définit la couleur du pinceau pour une certaine position en fonction de l'état
{
	int wPositionState = mBoatsPosition.getGridState(iY, iX);//récupération de l'état à la position i2 i
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

void GameBoard::displayText(int iX, int iY, std::wstring iText, int iStart, int iNumberOfCaracters, HDC ihdc, RECT& iPaintArea) //fonction pour afficher du texte
{
	std::wstring wChar;
	wChar = iText.substr(iStart, iNumberOfCaracters);
	RECT wTextArea = { iX, iY, 5000, 5000 };
	::DrawText(
		ihdc,
		wChar.c_str(),
		wChar.length(),
		&wTextArea,
		(int)(DT_LEFT | DT_BOTTOM));
}