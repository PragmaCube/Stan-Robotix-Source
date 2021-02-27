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

	GenerateAircraftCarrier();  // appels des diff�rentes fonctions des bateaux pour g�n�rer le positions selon le type d�finit par la taille

	GenerateCruiser();
	
	for (int i = 0; i < 3; i++)
	{
		GenerateBattleship();
	}

	GenerateDestroyer();
} 

int BoatsPosition::getGridState(int x, int y)
{
	return mState[y][x];  //retourner l'�tat d'une position
}

void BoatsPosition::setGridState(int x, int y, int iNewState)
{
	mState[y][x] = iNewState; //changement de l'�tat par l'�tat introduit
}

void BoatsPosition::GenerateAircraftCarrier()
{
	generateBoatPosition(5);
}

void BoatsPosition::GenerateDestroyer()
{
	generateBoatPosition(2);
}

void BoatsPosition::GenerateCruiser()
{
	generateBoatPosition(4);
}

void BoatsPosition::GenerateBattleship()
{
	generateBoatPosition(3);
}

void BoatsPosition::generateBoatPosition(int iLong) //processus de g�n�ration des position d'un bateau en fonction de sa taille
{
	int wDirectionShip;
	int x;
	int y;
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

bool BoatsPosition::isBoatPerfectlyPlaced(int x, int y, int iDirection, int iLong)
{
	bool wBoatPositionOk = true;
	switch (iDirection)
	{
	case eUp:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[y - i][x] != eSea) /*v�rification de si une des positions est occup�e, si oui, la v�rification est arr�ter 
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
			if (mState[y][x + i] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eDown:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[y + i][x] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eLeft:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[y][x - i] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
	}
	return wBoatPositionOk;
}


