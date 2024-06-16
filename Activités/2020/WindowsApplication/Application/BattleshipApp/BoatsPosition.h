#pragma once
#include <Windows.h>
class BoatsPosition
{
public:
	enum { eNotInit, eSea, eBoat, eMiss, eHit};
	enum { eNotUsed, eUp, eRight, eDown, eLeft, eNoDirection};
	
	int getGridState(int x, int y);
	void setGridState(int x, int y, int iNewState);
	void resetSetState();
	void setDestroyBoatColor();
	int getBoatsRemaining();
	 
private:
	void generateAircraftCarrier();
	void generateDestroyer();
	void generateCruiser();
	void generateBattleship();
	void generateBoatPosition(int iLong);
	int  getRandomDirection(int iX, int iY, int ilong);
	bool isBoatPerfectlyPlaced(int iX, int iY, int iDirection, int iLong);

	void findBoat(int iX, int iY, int iSens, int iLong);
	void setAircraftCarrierTable(int iX, int iY, int iSens);
	void setCruiserTable(int iX, int iY, int iSens);
	void setBattleshipTable(int iX, int iY, int iSens);
	void setDestroyerTable(int iX, int iY, int iSens);
	void BoatsColorProcess(int iX, int iY, int iSens, int iLong);

	int mState[10][10];
	int mHPAircraftCarrier[3];
	int mHPDestroyer[3];
	int mHPCruiser[3];
	int mHPBattleship1[3];
	int mHPBattleship2[3];
	int mHPBattleship3[3];
	int mRound;

	int mBoatsRemaining;
};
