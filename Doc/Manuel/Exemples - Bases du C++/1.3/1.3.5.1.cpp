#include <iostream>
#include <vector>
using namespace std;

int main()
{
    float positions[32] = {0.0, 0.36, 0.62, 0.98, 1.73, 3.20, 6.28, 12.03, 
                            17.02, 18.38, 19.3, 20.31, 21.38, 23.29, 25.29, 27.82,
                            30.23, 36.92, 42.93, 49.29, 55.92, 62.38, 69.8, 75.42,
                            85.18, 87.52, 89.62, 90.10, 90.15, 90.56, 90.57, 90.62 };

    float* ptr = positions;

    float deltaT = 0.1;
    vector<float> vitesses;

    for (int i = 1; i < 31; i++)
    {
        vitesses.push_back((positions[i + 1] - positions[i - 1]) / (2 * deltaT));
        cout << i << " : " << vitesses.at(i - 1) << endl;
    }

    *ptr = -1000;

    cout << positions[0];

    return 0;
}