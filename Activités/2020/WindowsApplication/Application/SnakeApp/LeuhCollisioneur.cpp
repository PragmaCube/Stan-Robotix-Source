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
	if (nullptr != mPommePtr && nullptr != mSerpentPtr)
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
}

void LeuhCollisionneur::score(HDC ihdc)
{

		std::string wMessage = "Vous avez mangé " + std::to_string(mScore) + " pomme(s)";
		std::wstring wChar = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(wMessage);
		RECT wTextArea = { 500, 20, 2000, 2000 };
		::DrawText(
			ihdc,
			wChar.c_str(),
			wChar.length(),
			&wTextArea,
			((int)DT_LEFT | DT_BOTTOM));

}

