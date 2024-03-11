// main.cpp

#include "cercle.h"

int main()
{
    Cercle cercle1;
    cercle1.setRayon(2);

    Cercle cercle2(2); // On évite d'appeler la méthode setRayon
    
    return 0;
}