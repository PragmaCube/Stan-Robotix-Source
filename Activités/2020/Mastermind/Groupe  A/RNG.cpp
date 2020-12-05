  #include <iostream>
  #include <cstdlib>
  #include <ctime>


  void RNG() {

      srand(time(NULL));
      int LastNum = 4;
      int randomChecker[LastNum];

      for (int i = 0; i < LastNum;) {
          int randomNumber;
          // std::cout<<"test"<<std::endl;
          randomNumber = (rand() % 10);

          bool repeter = false;
          for (int j = 0; j < i; j++) {
              if (randomNumber == randomChecker[j]) {
                  repeter = true;
              }
          }
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
