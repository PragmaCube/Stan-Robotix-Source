#include "BoatsPosition.h"

void BoatsPosition::resetSetState()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x ++)
		{
			mState[x][y] = eSea;
		}
	}

	GenerateAircraftCarrier();

	GenerateCruiser();
	
	for (int i = 0; i < 3; i++)
	{
		GenerateBattleship();
	}

	GenerateDestroyer();
}

int BoatsPosition::getGridState(int x, int y)
{
	return mState[x][y];
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

bool BoatsPosition::isBoatPerfectlyPlaced(int x, int y, int iDirection, int iLong)
{
	bool wBoatPositionOk = true;
	switch (iDirection)
	{
	case eUp:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[x][y - i] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eRight:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[x + i][y] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eDown:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[x][y + i] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
		break;

	case eLeft:
		for (int i = 1; i < iLong; i++)
		{
			if (mState[x - i][y] != eSea)
			{
				wBoatPositionOk = false;
				break;
			}
		}
	}
	return wBoatPositionOk;
}

void BoatsPosition::generateBoatPosition(int iLong)
{
	int wDirectionShip;
	int x;
	int y;
	bool wFindHead = false;
	int wFoundPosition = false;
	while (wFoundPosition == false)
	{
		while (wFindHead == false)
		{
			x = rand() % 10 + 1;;
			y = rand() % 10 + 1;;
			wFindHead = (mState[x][y] == eSea);
		}
		wDirectionShip = getRandomDirection(x, y, iLong);

		switch (wDirectionShip)
		{
		case eUp:
			for (int i = 0; i < iLong; i++)
			{
				mState[x][y - i] = eBoat;
			}
			wFoundPosition = true;
			break;

		case eRight:
			for (int i = 0; i < iLong; i++)
			{
				mState[x + i][y] = eBoat;
			}
			wFoundPosition = true;
			break;

		case eDown:
			for (int i = 0; i < iLong; i++)
			{
				mState[x][y + i] = eBoat;
			}
			wFoundPosition = true;
			break;

		case eLeft:
			for (int i = 0; i < iLong; i++)
			{
				mState[x - i][y] = eBoat;
			}
			wFoundPosition = true;
			break;

		case eNoDirection: 
			wFindHead = false;
			break;
		}
	}
}

int BoatsPosition::getRandomDirection(int iHeadX, int iHeadY, int iLong)
{
	int wWhile = 0;
	int wRandomDirection;
	bool wCheckResults = false;
	int wResultsTable[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		wResultsTable[i] = 0;
	}

	int wCheckingProgress = 0;
	while (wWhile == 0)
	{
		wRandomDirection = rand() % 4 + 1;

		switch (wRandomDirection)
		{
		case eUp:
			if (iHeadY - iLong >= 0)
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wWhile = 1;
				}
			}
			break;

		case eRight:
			if (iHeadX + iLong <= 10)
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wWhile = 1;
				}
			}
			break;

		case eDown:
			if (iHeadY + iLong <= 10)
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wWhile = 1;
				}
			}
			break;

		case eLeft:
			if (iHeadX - iLong >= 0)
			{
				wCheckResults = isBoatPerfectlyPlaced(iHeadX, iHeadY, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wWhile = 1;
				}
			}
		}
		if (wCheckResults == false)
		{
			if (wResultsTable[wRandomDirection - 1] != wRandomDirection)
			{
				wResultsTable[wRandomDirection - 1] = wRandomDirection;
				wCheckingProgress = wCheckingProgress + 1;
			}
		}
		if (wCheckingProgress == 4)
		{
			wRandomDirection = 5;
			wWhile = 1;
		}
	}
	return wRandomDirection;
}

