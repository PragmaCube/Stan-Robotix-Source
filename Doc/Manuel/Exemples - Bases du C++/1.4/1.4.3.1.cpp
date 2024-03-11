#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


double f(double x)
{
    return sqrt(1 - x * x);
}

vector<double> aire(double a, double b, int points = 10)
{
    vector<double> aires;
    double aire, h;

    for (int j = 3; j <= points; j++)
    {
        aire = f(a) + f(b);
        h = (b - a) / (j * 2);

        for (int i = 0; i < j; i++)
        {
            aire += 4 * f(a + h * (2 * i + 1));
        }

        for (int i = 1; i < j; i++)
        {
            aire += 2 * f(a + h * 2 * i);
        }

        aire *= h / 3;

        aires.push_back(aire);
    }

    return aires;
}

int main()
{
    vector<double> aires = aire(-1, 1, 50);

    for (int i = 0; i < aires.size(); i += 10)
    {
        cout << "Approximation avec " << i + 3 << " points : " << aires.at(i) << endl;
    }

    return 0;
}