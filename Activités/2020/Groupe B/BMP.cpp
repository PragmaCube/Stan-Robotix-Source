#include "BMP.h"
#include "Generateur.h"

int BMP::getBMP()
{
	return mBMP;
}


void BMP::setBMP(std::string iTentative, std::string iDeviner) {
	for (int i = 0; i < 4; i++)
	{
		for (int i2 = 0; i2 < 4; i2++)
		{
			if (iTentative[i2] == iDeviner[i])
			{
				if (i != i2)
				{
					mBMP = mBMP + 1;
				}
			}
		}
	}
