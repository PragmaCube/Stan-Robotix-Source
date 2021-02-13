#pragma once
#include <Windows.h>
class BoatsPosition
{
public:
	void PositionAircraftCarrier();
	void PositionDestroyer();
	void PositionCruiser();
	void PositionBattleship();
	int getBoatsPosition(int x, int y);
	int mState[10][10];
private:
	void SetBoatsPosition(int iLong);
	void ResetSetState();
	int getRamdomValueXY();
	int getRandomValueDirection(int x, int y, int ilong);
	bool getCheckRoot(int x, int y);
	bool getCheckNeighbour(int x, int y, int iDirection, int iLong);
};
