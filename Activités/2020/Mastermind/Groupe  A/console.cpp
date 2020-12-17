#include <string>
#include <iostream>

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
      case "b":
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
      std::cout << bon << " sont/est bon(s) et " << bon_bien_place << " bn(s) et bien place(s)" << endl;
    }
  }
}



/*

#include <string>
#include <iostream>

  int nb1, nb2, nb3, nb4,;
  std::cin >> nb1 >> nb2 >> nb3 >> nb4;
  int bon, bon_bien_place = 0;
  bool fin = false;

  int tableau[4];
  tableau[0] = nb1;
  tableau[1] = nb1;
  tableau[2] = nb3;
  tableau[3] = nb4;
  std::vector<char> reponse(0);

  for (int a = 0; a < 4; a++) //savoir pour chacun des nombres s'ils sont bons ('b'), bons et bien placés ('m') ou mauvais ('n')
  {             
    for (int y = 0; y < 4; y++)
    {
      if (tableau[a] == randomChecker[y])
      {
        reponse.push_back('m');
      }
      if (tableau[a] == randomChecker[a])
      {
          reponse.push_back('b');
      }
      else 
      {
        reponse.push_back('n');
      }
    }
  }
  for (int i = 0; i < 4; i++)
  {
    switch (reponse[i])
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
      fin = true;
    }
    else 
    {
      std::cout << bon << " sont/est bon(s) et " << bon_bien_place << " bon(s) et bien place(s)" << endl;
    }
*/
