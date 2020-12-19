#include <iostream>
#include <string>

main(){
  while(true)
  {
    std::string combinaison;
    std::string nPlace;
    std::cout << "tapez un nombre a 4 chiffres" << std::endl;
    std::cin >> combinaison;
    while (combinaison.length() != 4){
      std::cout << "tapez un nombre a 4 chiffres\n>>>";
      std::cin >> combinaison;
    }
    int bon, bon_bien_place = 0;


    for (int a = 0; a < 4; a++) //savoir pour chacun des nombres s'ils sont bons ('b'), bons et bien placés ('m') ou mauvais ('n')
    {             
      for (int y = 0; y < 4; y++)
      {
        if (combinaison[a] == randomChecker[y])
        { 
          nPlace + "m";
        }
        if (combinaison[a] == randomChecker[a])
        {
          nPlace + "b";
        }
        else 
        {
          nPlace + "n";
        }
      }
    }
    for (int i = 0; i < 4; i++)
    {
      switch (nPlace[i])
      {
        case 'b':
          bon++;
          break;
        case 'm':
          bon_bien_place++;
          break;
        case 'n':
          break;
      } 
      if (bon_bien_place == 4)
      {
        std::cout << "Bravo, vous avez trouvez !!!";
        break;
      }
      else 
      {
        std::cout << bon << " sont/est bon(s) et " << bon_bien_place << " bn(s) et bien place(s)" << std::endl;
      }
    }
  }
}
