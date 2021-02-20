#pragma once
#include <Windows.h>
class BoatsPosition
{
public:
	enum { eNotInit, eSea, eBoat, eMiss, eHit};
	enum { eNotUsed, eUp, eRight, eDown, eLeft, eNoDirection};

	void GenerateAircraftCarrier();
	void GenerateDestroyer();
	void GenerateCruiser();
	void GenerateBattleship();
	int getGridState(int x, int y);
	
	void resetSetState();
private:

	int mState[10][10];

	void generateBoatPosition(int iLong);
	int getRandomDirection(int x, int y, int ilong);
	bool isBoatPerfectlyPlaced(int x, int y, int iDirection, int iLong);
};
