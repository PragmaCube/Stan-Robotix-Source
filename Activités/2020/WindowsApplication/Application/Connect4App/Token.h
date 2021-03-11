#pragma once
#include <windows.h>



class Token
{
public:

	Token();
	void drawTokenRed(HDC ihdc, RECT& iPaintArea);
	void drawTokenBlue(HDC ihdc, RECT& iPaintArea);
	void drawToken(HDC ihdc, RECT& iPaintArea, HBRUSH & iBrush);
	void setPosition(int iPosX, int iPosY);
	void setcolor(HDC ihdc, RECT& iPaintArea, HBRUSH & iBrush); //indication de la couleur par un cercle afficher en haut 

	HBRUSH mRedBrush, mBlueBrush;
	bool mColor;  // si vrai le jeton est bleu sinon rouge
private:

	int mPosX, mPosY;
	bool mPos;
	

	
};

