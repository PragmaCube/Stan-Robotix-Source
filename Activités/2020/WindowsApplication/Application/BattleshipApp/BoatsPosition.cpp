#include "BoatsPosition.h"

void BoatsPosition::resetSetState() // formation de la table de jeu
{
	for (int y = 0; y < 10; y++)       // attribution à toutes les positions l'état eau
	{
		for (int x = 0; x < 10; x ++)
		{
			mState[y][x] = eSea;
		}
	}

	GenerateAircraftCarrier();  // appels des différentes fonctions des bateaux pour générer le positions selon le type définit par la taille

	GenerateCruiser();
	
	for (int i = 0; i < 3; i++)
	{
		GenerateBattleship();
	}

	GenerateDestroyer();
} 

int BoatsPosition::getGridState(int x, int y)
{
	return mState[y][x];  //retourner l'état d'une position
}

void BoatsPosition::setGridState(int x, int y, int iNewState)
{
	mState[y][x] = iNewState; //changement de l'état par l'état introduit
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

void BoatsPosition::generateBoatPosition(int iLong) //processus de génération des position d'un bateau en fonction de sa taille
{
	int wDirectionShip;
	int x;
	int y;
	bool wFindHead = false;
	bool wFoundPosition = false;
	while (wFoundPosition == false) //boucle du processus entier
	{
		while (wFindHead == false)//boucle de généner la postion de la tête
		{
			x = rand() % 10;  //génération de la tête du bateau (1/taille du bateau en construction)
			y = rand() % 10;
			wFindHead = (mState[y][x] == eSea); //vérification la position, si elle est disponible de base, si disponible, desactivation de cette boucle
		}
		wDirectionShip = getRandomDirection(x, y, iLong); /*appel d'une fonction qui fournit une direction que la construction du 
		corps du bateau va prendre, il est possible qu'il retourne la réponse qu'il impossible de placer le bateau*/

		switch (wDirectionShip) //attribution de l'état bateau aux positions de la tête et les positions avoisinnantes selon le sens
		{
		case eUp:
			for (int i = 0; i < iLong; i++)
			{
				mState[y - i][x] = eBoat;
			}
			wFoundPosition = true; //désactivation de la boucle du processus entier
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

		case eNoDirection: //cas où le bateau est implaçable dans toute les directions à partir de la tête
			wFindHead = false; /*réactivation de la boucle de génération de la position de la tête, pour une nouvelle tentative 
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
	for (int i = 0; i < 4; i++)//création d'un tableau de résultat d'analyse des 4 sens
	{
		wResultsTable[i] = 0; 
	}

	int wCheckingProgress = 0;
	while (wSearchingDirectionCycle == false) //boucle à la recherche d'une potentille direction
	{
		wRandomDirection = rand() % 4 + 1; //génération aléatoire d'un sens 

		switch (wRandomDirection)
		{
		case eUp:
			if (iHeadY - iLong >= 0) //calcul permettant de savoir si quand le bateau prend une certaine direction il sort ou pas du tableau
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong); /*appel d'une fonction qui vérifie si les 
				positioons sont disponibles*/
				if (wCheckResults == true)
				{
					wSearchingDirectionCycle = true; /*si il est possible de placer le bateau à cette emplacement la boucle de recherche d'une 
					direction est désactivée*/
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
		if (wCheckResults == false)/*quand le bateau ne peut pas être placé dans un certain sens, le sens est placé dans un 
			tableau, la mémoire de ce qui a été analysé et pas*/
		{
			if (wResultsTable[wRandomDirection - 1] != wRandomDirection)
			{
				wResultsTable[wRandomDirection - 1] = wRandomDirection;
				wCheckingProgress = wCheckingProgress + 1; //à chaque fois qu'un sens n'a pas été analysé, le compteur du nombre de sens testés
			}
		}
		if (wCheckingProgress == 4) /*quand le compteur attteint 4, donc toute les sens ont été testés, la fonction va retourner 
			une valeur qui fera recommencer le processus entier*/
		{
			wRandomDirection = 5;
			wSearchingDirectionCycle = true; //désactivation de la boucle 
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
			if (mState[y - i][x] != eSea) /*vérification de si une des positions est occupée, si oui, la vérification est arrêter 
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


