#include "BoatsPosition.h"
void BoatsPosition::ResetSetState()
{
	for (int i = 0; i < 10; i++)
	{
		for (int i2 = 0; i < 10; i++)
		{
			mState[i2][i] = 0;
		}
	}
}

int BoatsPosition::getBoatsPosition(int x, int y)
{
	return mState[x][y];
}

void BoatsPosition::PositionAircraftCarrier()
{
	int const wAircraftCarrierLong = 5;
	SetBoatsPosition(wAircraftCarrierLong);
}

void BoatsPosition::PositionDestroyer()
{
	int const wDestroyerLong = 2;
	SetBoatsPosition(wDestroyerLong);
}

void BoatsPosition::PositionCruiser()
{
	int const wCruiserLong = 4;
	SetBoatsPosition(wCruiserLong);
}

void BoatsPosition::PositionBattleship()
{
	int const wBattleshipLong = 4;
	SetBoatsPosition(wBattleshipLong);
}

void BoatsPosition::SetBoatsPosition(int iLong)
{
	int wDirectionShip;
	int x;
	int y;
	bool wWhile = false;
	int wWhile1 = 1;
	while (wWhile1 == 1)
	{
		while (wWhile == false)
		{
			x = getRamdomValueXY();
			y = getRamdomValueXY();
			wWhile = getCheckRoot(x, y);
		}
		wDirectionShip = getRandomValueDirection(x, y, iLong);
		switch (wDirectionShip)
		{
		case 1:for (int i = 0; i < 5; i++)
		{
			mState[x][y - i];
		}
			  wWhile1 = 0;
			  break;

		case 2:for (int i = 0; i < 5; i++)
		{
			mState[x + i][y];
		}
			  wWhile1 = 0;
			  break;

		case 3:for (int i = 0; i < 5; i++)
		{
			mState[x][y + i];
		}
			  wWhile1 = 0;
			  break;

		case 4:for (int i = 0; i < 5; i++)
		{
			mState[x - 1][y];
		}
			  wWhile1 = 0;
			  break;

		case 5: wWhile = false;
		}
	}
}

int BoatsPosition::getRamdomValueXY()
{
	int wRandomXY;
	wRandomXY = rand()%10 + 1;
	return wRandomXY;
}

int BoatsPosition::getRandomValueDirection(int x, int y, int iLong)
{
	int wWhile = 0;
	int wRandomDirection;
	bool wCheckResults;
	int wResultsTable[4] = {0};
	for (int i = 0; i < 4; i++)
	{
		wResultsTable[i] = 0;
	}
	int wCheckingProgress = 0;
	while (wWhile != 1)
	{
		wRandomDirection = rand() % 4 + 1;
		switch (wRandomDirection)
		{
		    case 1:if(y - iLong >= 0)
			{
				wCheckResults = getCheckNeighbour(x, y, wRandomDirection, iLong);
				if (wCheckResults == true)
				{
					wWhile = 1;
				}
			}
			break;

		    case 2:if (x + iLong <= 10)
			{
				wWhile = 1;
			}
			break;

			case 3:if (y + iLong <= 10)
			{
				wWhile = 1;
			}
			break;

			case 4:if (x - iLong >= 0)
			{
				wWhile = 1;
			}
		}
		if (wCheckResults == false)
		{
			if (wResultsTable[wCheckResults-1] != wCheckResults)
			{
				wResultsTable[wCheckResults - 1] = wCheckResults;
				wCheckingProgress = wCheckingProgress + 1;
			}
			
		}
		if (wCheckingProgress = 4)
		{
			wRandomDirection = 5;
			wWhile = 1;
		}
	}
	return wRandomDirection;
}

bool BoatsPosition::getCheckRoot(int x, int y)
{
	if (mState[x][y] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BoatsPosition::getCheckNeighbour(int x, int y, int iDirection, int iLong)
{
	int wProgress;
	switch (iDirection)
	{
	case 1:for (int i = 1; i < iLong; i++)
	       {
		       if (mState[x][y-i] == 1)
		       {
				   wProgress = i;
				   break;
		       }
	       }
	break;

	case 2:for (int i = 1; i < iLong; i++)
	       {
		       if (mState[x+i][y] == 1)
		       {
				   wProgress = i;
			       break;
		       }
	       }
	break;

	case 3:for (int i = 1; i < iLong; i++)
	       {
		       if (mState[x][y+i] == 1)
		       {
				   wProgress = i;
			       break;
		       }
	       }
	break;

	case 4:for (int i = 1; i < iLong; i++)
	       {
		       if (mState[x - 1][y] == 1)
		       {
			       wProgress = i;
		           break;
		       }
           }
	}
    if(wProgress == iLong)
    {
		return true;
    }
	else
	{
		return false;
	}
}