#pragma once
#include <iostream>
#include <string>
class BMP
{
private:

	int mBMP;
	/*int m_nombresT[4];
	int m_nombresD[4];*/
	std::string mTentative;
	std::string mDeviner;
	void setBMP(std::string, std::string);

public:

	int getBMP();
	/*void setTableauD(std::string iDeviner);
	void setTableauT(std::string iProposition);*/
};
