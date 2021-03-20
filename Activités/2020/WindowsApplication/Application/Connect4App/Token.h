#pragma once
#include <windows.h>



class Token
{
public:
	enum { eNothing, eRed, eBlue };

	Token();
	void draw(HDC ihdc);

	void setPosition(int iPosX, int iPosY);
	void setcolor(HDC ihdc, RECT& iPaintArea, HBRUSH & iBrush); //indication de la couleur par un cercle afficher en haut 

	void setType(int iColor);

	HBRUSH mRedBrush, mBlueBrush;

private:

	int mPosX, mPosY;
	int mType;
	
	

	
};

