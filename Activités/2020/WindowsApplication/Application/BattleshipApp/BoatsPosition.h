#pragma once
#include <Windows.h>
class BoatsPosition
{
public:
	enum { eNotInit, eSea, eBoat, eMiss, eHit};
	enum { eNotUsed, eUp, eRight, eDown, eLeft, eNoDirection};
	int mBoatsRemaining = 6;

	void generateAircraftCarrier();
	void generateDestroyer();
	void generateCruiser();
	void generateBattleship();
	int getGridState(int x, int y);
	void setGridState(int x, int y, int iNewState);
	void resetSetState();
	void setDestroyBoatColor();
	int getBoatsRemaining();
	 
private:

	int mState[10][10];
	
	void generateBoatPosition(int iLong);
	int getRandomDirection(int x, int y, int ilong);
	bool isBoatPerfectlyPlaced(int x, int y, int iDirection, int iLong);

	void findBoat(int x, int y, int iSens, int iLong);
	void setAircraftCarrierTable(int x, int y, int iSens);
	void setCruiserTable(int x, int y, int iSens);
	void setBattleshipTable(int x, int y, int iSens);
	void setDestroyerTable(int x, int y, int iSens);
	void BoatsColorProcess(int x, int y, int iSens, int iLong);
	int mHPAircraftCarrier[3];
	int mHPDestroyer[3];
	int mHPCruiser[3];
	int mHPBattleship1[3];
	int mHPBattleship2[3];
	int mHPBattleship3[3];
	int mRound;
};
