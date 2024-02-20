#include <iostream>
#include <cstdlib>
#include <ctime>

// RNG? Pour RaNdom Generator? Trouvez un nom plus �vocateur!
void RNG() {
    srand(time(NULL));
    // Les normes de codage peuvent varier, mais c'est tr�s rare de commencer
    // le nom d'une variable par une majuscule!
    int LastNum = 4;
    int randomChecker[LastNum];
	// Si vous ne faites pas d'incr�mentation � chaque it�ration, pourquoi utiliser un for?
	// Vous devriez plut�t utiliser un while, l'intention est plus claire :
	//     int i = 0
	//     while{i < lastNum) { ... }
    for (int i = 0; i < LastNum;) {
        int randomNumber;
        // �vitez de laisser du code mort inutilement!
        // std::cout<<"test"<<std::endl;
		
		// L'association de valeur aurait pu se faire en une ligne:
		//     int randomNumber = rand() % 10;
        randomNumber = (rand() % 10);
        bool repeter = false;
        for (int j = 0; j < i; j++) {
            if (randomNumber == randomChecker[j]) {
                repeter = true;
            }
        }
        // Il y a une fa�on beaucoup plus �l�gante de v�rifier une valeur bool�enne!
        // Indice : l'op�rateur == retourne... une valeur bool�enne.
        if (repeter == false) {
            randomChecker[i] = randomNumber;
            std::cout << randomChecker[i] << std::endl;
            i = i + 1;
        }
    }
	// �ventuellement, il faudra que cette fonction retourne quelque chose...
}

int main() {
    // Normalement, on ne cr�e pas une fonction juste pour remplacer le main.
    // J'imagine cependant que vous voulez cr�er d'autres fonctions ensuite,
    // comme le code n'est pas fini je comprends cet usage.
    RNG();
}

// Continuez comme �a!
