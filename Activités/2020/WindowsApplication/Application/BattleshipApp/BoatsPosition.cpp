#include "BoatsPosition.h"

void BoatsPosition::resetSetState() // formation de la table de jeu
{
	for (int y = 0; y < 10; y++)       // attribution � toutes les positions l'�tat eau
	{
		for (int x = 0; x < 10; x ++)
		{
			mState[y][x] = eSea;
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		mHPAircraftCarrier[i] = 0;
		mHPCruiser[i] = 0;
		mHPBattleship1[i] = 0;
		mHPBattleship2[i] = 0;
		mHPBattleship3[i] = 0;
		mHPDestroyer[i] = 0;
	}

	mRound = 0;

	generateAircraftCarrier();  // appels des diff�rentes fonctions des bateaux pour g�n�rer le positions selon le type d�finit par la taille

	generateCruiser();
	
	for (int i = 0; i < 3; i++)
	{
		mRound = i;
		generateBattleship();
	}

	generateDestroyer();

	mBoatsRemaining = 6;
} 

int BoatsPosition::getGridState(int iX, int iY)
{
	return mState[iY][iX];  //retourner l'�tat d'une position
}

void BoatsPosition::setGridState(int iX, int iY, int iNewState)
{
	mState[iY][iX] = iNewState; //changement de l'�tat par l'�tat introduit
}

int BoatsPosition::getBoatsRemaining()
{
	return mBoatsRemaining;
}

void BoatsPosition::generateAircraftCarrier()
{
	generateBoatPosition(5);
}

void BoatsPosition::generateDestroyer()
{
	generateBoatPosition(2);
}

void BoatsPosition::generateCruiser()
{
	generateBoatPosition(4);
}

void BoatsPosition::generateBattleship()
{
	generateBoatPosition(3);
}

void BoatsPosition::generateBoatPosition(int iLong) //processus de g�n�ration des position d'un bateau en fonction de sa taille
{
	int wDirectionShip = eUp;
	int x = 0;
	int y = 0;

	bool wFindHead = false;
	bool wFoundPosition = false;
	while (wFoundPosition == false) //boucle du processus entier
	{
		while (wFindHead == false)//boucle de g�n�ner la postion de la t�te
		{
			x = rand() % 10;  //g�n�ration de la t�te du bateau (1/taille du bateau en construction)
			y = rand() % 10;
			wFindHead = (mState[y][x] == eSea); //v�rification la position, si elle est disponible de base, si disponible, desactivation de cette boucle
		}
		wDirectionShip = getRandomDirection(x, y, iLong); /*appel d'une fonction qui fournit une direction que la construction du 
		corps du bateau va prendre, il est possible qu'il retourne la r�ponse qu'il impossible de placer le bateau*/

		switch (wDirectionShip) //attribution de l'�tat bateau aux positions de la t�te et les positions avoisinnantes selon le sens
		{
		case eUp:
			for (int i = 0; i < iLong; i++)
			{
				mState[y - i][x] = eBoat;
			}
			wFoundPosition = true; //d�sactivation de la boucle du processus entier
			break;

		case eRight:
			for (int i = 0; i < iLong; i++)
			{
				mState[y][x + i] = eBoat;
			}
			wFoundPosition = true;
			break;

		case eDown:
			for (int i = 0; i < iLong; i++)
			{
				mState[y + i][x] = eBoat;
			}
			wFoundPosition = true;
			break;

		case eLeft:
			for (int i = 0; i < iLong; i++)
			{
				mState[y][x - i] = eBoat;
			}
			wFoundPosition = true;
			break;

		case eNoDirection: //cas o� le bateau est impla�able dans toute les directions � partir de la t�te
			wFindHead = false; /*r�activation de la boucle de g�n�ration de la position de la t�te, pour une nouvelle tentative 
							   de trouver une place*/
			break;
		}
	}
	findBoat(x, y, wDirectionShip, iLong); //appel d'une fonction pour savoir remplir le tableau d'infornations de l'un des bateaux � l'aide la longeur
}

int BoatsPosition::getRandomDirection(int iHeadX, int iHeadY, int iLong)
{
	bool wSearchingDirectionCycle = false;
	int wRandomDirection;
	bool wCheckResults = false;
	int wResultsTable[4] = { 0 };
	for (int i = 0; i < 4; i++)//cr�ation d'un tableau de r�sultat d'analyse des 4 sens
	{
		wResultsTable[i] = 0; 
	}

	int wCheckingProgress = 0;
	while (wSearchingDirectionCycle == false) //boucle � la recherche d'une potentille direction
	{
		wRandomDirection = rand() % 4 + 1; //g�n�ration al�atoire d'un sens 

		switch (wRandomDirection)
		{
		case eUp:
			if (iHeadY - iLong >= 0) //calcul permettant de savoir si quand le bateau prend une certaine direction il sort ou pas du tableau
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong); /*appel d'une fonction qui v�rifie si les 
				positioons sont disponibles*/
				if (wCheckResults == true)
				{
					wSearchingDirectionCycle = true; /*si il est possible de placer le bateau � cette emplacement la boucle de recherche d'une 
					direction est d�sactiv�e*/
				}
			}
			break;

		case eRight:
			if (iHeadX + iLong <= 10)
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wSearchingDirectionCycle = true;
				}
			}
			break;

		case eDown:
			if (iHeadY + iLong <= 10)
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wSearchingDirectionCycle = true;
				}
			}
			break;

		case eLeft:
			if (iHeadX - iLong >= 0)
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wSearchingDirectionCycle = true;
				}
			}
		}
		if (wCheckResults == false)/*quand le bateau ne peut pas �tre plac� dans un certain sens, le sens est plac� dans un 
			tableau, la m�moire de ce qui a �t� analys� et pas*/
		{
			if (wResultsTable[wRandomDirection - 1] != wRandomDirection)
			{
				wResultsTable[wRandomDirection - 1] = wRandomDirection;
				wCheckingProgress = wCheckingProgress + 1; //� chaque fois qu'un sens n'a pas �t� analys�, le compteur du nombre de sens test�s
			}
		}
		if (wCheckingProgress == 4) /*quand le compteur attteint 4, donc toute les sens ont �t� test�s, la fonction va retourner 
			une valeur qui fera recommencer le processus entier*/
		{
			wRandomDirection = 5;
			wSearchingDirectionCycle = true; //d�sactivation de la boucle 
		}
	}
	return wRandomDirection;
}

bool BoatsPosition::isBoatPerfectlyPlaced(int iX, int iY, int iDirection, int iLong)
{
	bool wBoatPositionOk = true;
	switch (iDirection)
	{
	case eUp:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[iY - i][iX] != eSea) /*v�rification de si une des positions est occup�e, si oui, la v�rification est arr�ter 
				et la fonction va retourner qu'il n'est pas possible de placer le bateau*/
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eRight:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[iY][iX + i] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eDown:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[iY + i][iX] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eLeft:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[iY][iX - i] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
	}
	return wBoatPositionOk;
}

void BoatsPosition::findBoat(int iX, int iY, int iSens, int iLong) //fonction qui permet de d�terminer pour quel bateau il faut remplir le tableau d'information gr�ce � la longeur
{
	switch (iLong)
	{
		case 2: setDestroyerTable(iX, iY, iSens);
		break;

		case 3: setBattleshipTable(iX, iY, iSens);
		break;

		case 4: setCruiserTable(iX, iY, iSens);
		break;

		case 5: setAircraftCarrierTable(iX, iY, iSens);
	}
}

//fonctions qui remplissent le tableau d'information de chaque bateau
void BoatsPosition::setAircraftCarrierTable(int iX, int iY, int iSens)
{
	mHPAircraftCarrier[0] = iX;
	mHPAircraftCarrier[1] = iY;
	mHPAircraftCarrier[2] = iSens;
}

void BoatsPosition::setCruiserTable(int iX, int iY, int iSens)
{

	mHPCruiser[0] = iX;
	mHPCruiser[1] = iY;
	mHPCruiser[2] = iSens;
}

void BoatsPosition::setBattleshipTable(int iX, int iY, int iSens)
{
	switch (mRound) //vu qu'il en existe tois de ce type, on trouve le tableau exacte � l'aide de mRound  qui permet de d�terminer � quel bateau de ce type on est rendu dans la construction
	{
	case 0:
		mHPBattleship1[0] = iX;
		mHPBattleship1[1] = iY;
		mHPBattleship1[2] = iSens;
		break;
	case 1:
		mHPBattleship2[0] = iX;
		mHPBattleship2[1] = iY;
		mHPBattleship2[2] = iSens;
		break;
	case 2:
		mHPBattleship3[0] = iX;
		mHPBattleship3[1] = iY;
		mHPBattleship3[2] = iSens;
	}
}

void BoatsPosition::setDestroyerTable(int iX, int iY, int iSens)
{
	mHPDestroyer[0] = iX;
	mHPDestroyer[1] = iY;
	mHPDestroyer[2] = iSens;
}

void BoatsPosition::setDestroyBoatColor() //fonction qui lance plusierus fois le processus de v�rification de si le bateau est d�couvert au complet, avec les donn�es du tableau du bateau � v�rifier et sa longueur
{
	BoatsColorProcess(mHPAircraftCarrier[0], mHPAircraftCarrier[1], mHPAircraftCarrier[2], 5);
	BoatsColorProcess(mHPCruiser[0], mHPCruiser[1], mHPCruiser[2], 4);
	BoatsColorProcess(mHPBattleship1[0], mHPBattleship1[1], mHPBattleship1[2], 3);
	BoatsColorProcess(mHPBattleship2[0], mHPBattleship2[1], mHPBattleship2[2], 3);
	BoatsColorProcess(mHPBattleship3[0], mHPBattleship3[1], mHPBattleship3[2], 3);
	BoatsColorProcess(mHPDestroyer[0], mHPDestroyer[1], mHPDestroyer[2], 2);
}

void BoatsPosition::BoatsColorProcess(int iX, int iY, int iSens, int iLong)//processus de v�rification de si le bateau est d�truit
{
	int wNumberOfDestroyPointsX4 = 0;
	switch (iSens)
	{
	case eUp:
		for (int i = 0; i < iLong; i++)
		{
			wNumberOfDestroyPointsX4 = wNumberOfDestroyPointsX4 + mState[iY - i][iX];
		}
		if (iLong * 4 == wNumberOfDestroyPointsX4) //si la somme des �tats de chaque parties de bateau est �gal � la longueur de bateau fois 4 (4 quand la partie du bateau est touch�e), donc le bateau est d�truit puisque tout les parties sont donc logiquements touch�es
		{
			for (int i = 0; i < iLong; i++)
			{
				mState[iY - i][iX] = 3 + iLong; //modification de la valeur de chaque �tat, pour que le bateau prennent une certaine couleur lors de la coloration
			}
			mBoatsRemaining--; //mise � jour de compteur de nombre de bateaux restant � d�truire
		}
		break;

	case eRight:
		for (int i = 0; i < iLong; i++)
		{
			wNumberOfDestroyPointsX4 = wNumberOfDestroyPointsX4 + mState[iY][iX + i];
		}
		if (iLong * 4 == wNumberOfDestroyPointsX4)
		{
			for (int i = 0; i < iLong; i++)
			{
				mState[iY][iX + i] = 3 + iLong;
			}
			mBoatsRemaining--;
		}
		break;

	case eDown:
		for (int i = 0; i < iLong; i++)
		{
			wNumberOfDestroyPointsX4 = wNumberOfDestroyPointsX4 + mState[iY + i][iX];
		}
		if (iLong * 4 == wNumberOfDestroyPointsX4)
		{
			for (int i = 0; i < iLong; i++)
			{
				mState[iY + i][iX] = 3 + iLong;
			}
			mBoatsRemaining--;
	    }
		break;

	case eLeft:
		for (int i = 0; i < iLong; i++)
		{
			wNumberOfDestroyPointsX4 = wNumberOfDestroyPointsX4 + mState[iY][iX - i];
		}
		if (iLong * 4 == wNumberOfDestroyPointsX4)
		{
			for (int i = 0; i < iLong; i++)
			{
				mState[iY][iX - i] = 3 + iLong;
			}
			mBoatsRemaining--;
		}
	}
}

