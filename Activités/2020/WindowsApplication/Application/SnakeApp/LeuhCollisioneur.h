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
	std::wstring getStringToDisplay(const std::wstring& iText, int iNumber, HDC ihdc, RECT& iPaintArea, int iNumber);
	std::wstring getStringToDisplay(const std::wstring& iText, int iNumber);
	void score(HDC ihdc);
private:
	pom* mPommePtr;
	BoutteDeSerpent* mSerpentPtr;
	int mScore = 0;
	int iNumber
};
