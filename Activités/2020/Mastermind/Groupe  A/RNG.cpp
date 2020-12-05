  #include <iostream>
  #include <cstdlib>
  #include <ctime>


  void RNG() {
//variables à declarer
      srand(time(NULL));
      int LastNum = 4;
      int randomChecker[LastNum];
//répeter avec la valeur de LastNum
      for (int i = 0; i < LastNum;) {
          int randomNumber;
          // std::cout<<"test"<<std::endl;
          randomNumber = (rand() % 10);
//repeter est la variable qui determine si on a eu un bon nombre ou pas
          bool repeter = false;
//ce qui verifie que le nombre a jamais ete la avant
          for (int j = 0; j < i; j++) {
              if (randomNumber == randomChecker[j]) {
                  repeter = true;
              }
          }
//ce qui mets la variable dans le array si jamais le nombre ne se trouve pas avant
          if (repeter == false) {
              randomChecker[i] = randomNumber;
              std::cout << randomChecker[i] << std::endl;
              i = i + 1;
          }
      }

  }

  int main() {
  RNG();

  }
