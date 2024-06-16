#include <iostream>
#include <vector>
using namespace std;

float interpolationDegre3(vector<float> x, vector<float> y, float point)
{
    float image = 0;

    for (int i = 0; i < x.size(); i++)
    {
        image += y.at(i) * (point - x.at((i + 1) % (int)x.size())) * (point - x.at((i + 2) % (int)x.size())) / ((x.at(i % (int)x.size()) -  - x.at((i + 1) % (int)x.size())) * (x.at(i % (int)x.size()) -  - x.at((i + 2) % (int)x.size())));
    }

    return image;
}

int main()
{
    vector<float> x = {0, 3, -2};
    vector<float> y = {1, 1, 4};

    cout << "L'image de 4 est : " << interpolationDegre3(x, y, 4);

    return 0;
}