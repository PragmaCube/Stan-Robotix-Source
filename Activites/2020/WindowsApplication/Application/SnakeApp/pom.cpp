#include "pom.h"

pom::pom()
{

	COLORREF wColor = RGB(255, 0, 0);
	mBrush = CreateSolidBrush(wColor);


	mIsInit = false;


}
void pom::updateDrawingArea(RECT iWindowRect)
{

	if (!mIsInit)
	{
		mCoorX = iWindowRect.left + (double)(rand() % (iWindowRect.right - iWindowRect.left));
		mCoorY = iWindowRect.top + (double)(rand() % (iWindowRect.bottom - iWindowRect.top));


		mIsInit = true;
	}
}
void pom::paint(HDC ihdc) {
	HGDIOBJ wOldBrush = ::SelectObject(ihdc, mBrush);



	::Ellipse(ihdc,
		(int)(mCoorX)-mRadius,
		(int)(mCoorY)-mRadius,
		(int)(mCoorX)+mRadius,
		(int)(mCoorY)+mRadius);



	::SelectObject(ihdc, wOldBrush);

}
int pom::getX()
{
	return mCoorX;
}

int  pom::getY()
{
	return mCoorY;
}

void pom::Teleportation(RECT iWindowRect)
{
	mCoorX = iWindowRect.left + (double)(rand() % (iWindowRect.right - iWindowRect.left));
	mCoorY = iWindowRect.top + (double)(rand() % (iWindowRect.bottom - iWindowRect.top));
}
