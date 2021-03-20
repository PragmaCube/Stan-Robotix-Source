#include "SnakeApplication.h"
#include "../../Framework/IApplication.h"
#include <stdlib.h>     
#include <time.h>       
#include <math.h>
#include <string>

void SnakeApplication::paint(HDC ihdc, RECT& iPaintArea)
{
	std::wstring wTitle = L"Application de Snake";

	::DrawText(
		ihdc,
		wTitle.c_str(),
		wTitle.length(),
		&iPaintArea,
		DT_CENTER | DT_TOP);
	int wRadius = 100;
	while (wRadius > 20)
	{
		SnakeApplication::Ellipse (ihdc,
			(int)(mPosX)-wRadius,
			(int)(mPosY)-wRadius,
			(int)(mPosX)+wRadius,
			(int)(mPosY)+wRadius);

		wRadius -= 10;
}
}