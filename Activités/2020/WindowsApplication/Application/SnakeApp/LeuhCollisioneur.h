#pragma once
#include "BoutteDeSerpent.h"
#include "pom.h"



class LeuhCollisionneur
{
public:
	LeuhCollisionneur();
	void setPomme(pom* mPommePtr);
	void setSerpent(BoutteDeSerpent* mSerpentPtr);
	void manger(RECT iWindowRect);
	void score(HDC ihdc);
private:
	pom* mPommePtr;
	BoutteDeSerpent* mSerpentPtr;
	int mScore = 0;
};
