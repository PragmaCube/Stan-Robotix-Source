#include <iostream>
#include <string>

int main()
{
  while(true)
  {
    std::string wCombinaison;
    std::string wNPlace;
    std::cout << "tapez un nombre a 4 chiffres" << std::endl;
    std::cin >> wCombinaison;
    
    while (wCombinaison.length() != 4)
    {
      std::cout << "tapez un nombre a 4 chiffres\n>>>";
      std::cin >> wCombinaison;
    }

    int wGood, wGoodPlace = 0;

    for (int a = 0; a < 4; a++) //savoir pour chacun des nombres s'ils sont bons ('b'), bons et bien placés ('m') ou mauvais ('n')
    {
      for (int y = 0; y < 4; y++)
      {
        if (wCombinaison[a] == randomChecker[y])
        {
          wNPlace + "m";
        }
        if (wCombinaison[a] == randomChecker[a])
        {
          wNPlace + "b";
        }
        else
        {
          wNPlace + "n";
        }
      }
    }

    for (int i = 0; i < 4; i++)
    {
      switch (wNPlace[i])
      {
        case 'b':
          wGood++;
          break;
        case 'm':
          wGoodPlace++;
          break;
        case 'n':
          break;
      }

      if (wGoodPlace == 4)
      {
        std::cout << "Bravo, vous avez trouvez !!!";
        break;
      }

      else
      {
        std::cout << wGood << " sont/est bon(s) et " << wGoodPlace << " bn(s) et bien place(s)" << std::endl;
      }
    }
  }
}
