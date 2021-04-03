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
		mCoorX = iWindowRect.left + (double)(100);
		mCoorY = iWindowRect.top + (double)(1000);


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