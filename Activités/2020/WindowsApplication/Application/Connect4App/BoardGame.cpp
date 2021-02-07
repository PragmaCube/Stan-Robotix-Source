#include "BoardGame.h"

void BoardGame::paint(HDC ihdc, RECT& iPaintArea)
{   
	for (int i = iPaintArea.top + 50; i < iPaintArea.bottom; i += 102) {

		::MoveToEx(ihdc, iPaintArea.left, i, nullptr);
		::LineTo(ihdc, iPaintArea.right, i);
	} // dessiner les lignes horizontales
      
	for (int j = iPaintArea.left; j < iPaintArea.right; j += 117)
	{
		::MoveToEx(ihdc, j, iPaintArea.top+50, nullptr);
		::LineTo(ihdc, j, iPaintArea.bottom);
	} //dessiner les lignes verticales

	mRed.drawTokenRed(ihdc, iPaintArea);
	mBlue.drawTokenBlue(ihdc, iPaintArea);
}

void BoardGame::AddRedToken(int iPosX, int iPosY)
{
	mRed.setPosition(iPosX, iPosY);
	
}

void BoardGame::AddBlueToken(int iPosX, int iPosY)
{
	mBlue.setPosition(iPosX, iPosY);
}
