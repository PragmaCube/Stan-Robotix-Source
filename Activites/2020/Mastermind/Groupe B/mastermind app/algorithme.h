#pragma once
#include <string>

class algorithme
{
public:
	int GoodPlace(std::string iTry, std::string iGuess);
	int WrongPlace(std::string iTry, std::string iGuess);
	std::string generateur();
};

