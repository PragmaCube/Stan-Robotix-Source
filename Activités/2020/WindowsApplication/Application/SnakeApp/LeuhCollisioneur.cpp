#include "LeuhCollisioneur.h"
#include <string>
#include <codecvt>


LeuhCollisionneur::LeuhCollisionneur() : mPommePtr(nullptr), mSerpentPtr(nullptr)
{
}


void LeuhCollisionneur::setPomme(pom* iPomme)
{
	mPommePtr = iPomme;
}

void LeuhCollisionneur::setSerpent(BoutteDeSerpent* iSerpent)
{
	mSerpentPtr = iSerpent;
}

void LeuhCollisionneur::manger(RECT iWindowRect)
{
		
	if (mSerpentPtr->getX() <= mPommePtr->getX() + 30 &&
		mSerpentPtr->getX() >= mPommePtr->getX() - 30 &&
		mSerpentPtr->getY() <= mPommePtr->getY() + 30 &&
		mSerpentPtr->getY() >= mPommePtr->getY() - 30)
	{
		mPommePtr->Teleportation(iWindowRect);
		mScore++;
	}

}

std::wstring LeuhCollisionneur::getStringToDisplay(const std::wstring & iText, int iNumber, HDC ihdc, RECT& iPaintArea, int iNumber)
{
	std::wstring wBoats = getStringToDisplay(L"Boats remaining : ",
		mBoatsPosition.getBoatsRemaining());
	displayText(170, 105, wBoats, 0, 30, ihdc, iPaintArea);
}

