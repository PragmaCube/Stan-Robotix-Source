#include <iostream>

#include "vecteur.h"

int main() {

  float wX1, wX2, wY1, wY2;
  Vecteur wVect1, wVect2;

  std::cout << "Veuillez rentrer les coordonnées pour chaque vecteur :\n\nVecteur 1 :\n>>> X : ";

  std::cin >> wX1;

  std::cout << "\n>>> Y : ";

  std::cin >> wY1;

  std::cout << "\n>>> X : ";

  std::cin >> wX2;

  std::cout << "\n>>> Y : ";

  std::cin >> wY2;

  wVect1.setX(wX1);
  wVect1.setY(wY1);

  wVect2.setX(wX2);
  wVect2.setY(wY2);

  std::cout << "La norme de chaque vecteur est :\n\nVecteur 1 :\n>>> " << wVect1.getNorme() << "\n\nVecteur 2 :\n>>> " << wVect2.getNorme();

  std::cout << "\nLe produit scalaire des deux vecteurs est : " << produitScalaire(wVect1, wVect2);

  std::cout << "\nLe produit scalaire est ";
  
  switch(int(produitScalaire(wVect1, wVect2) / std::abs(produitScalaire(wVect1, wVect2))))
    {
      case -1: 
        std::cout << "négatif";
      break;
      
      case 0:
        std::cout << "nul";
      break;
      
      case 1:
        std::cout << "positif";
      break;
    }
}