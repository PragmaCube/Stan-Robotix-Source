#include <iostream>
#include <vector>
using namespace std;

class neurones {
  vector<float> x;
  vector<float> y;

public:
  neurones();
  ~neurones();

  void setX(float x);
  vector<float> getX() { return x; }

  void setY(float y);
  vector<float> getY() { return y; }

  for (int i = 0; i < x.size(); i++) {
  }
};

int main() {}
