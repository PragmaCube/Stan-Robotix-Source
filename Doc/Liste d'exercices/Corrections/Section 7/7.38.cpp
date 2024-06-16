#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double pas = 0.00001;
    double t0 = 0;
    double y0 = 0;
    double y0Prime = 0.5;

    double E = 12;
    double L = 0.5;
    double C = 0.05;

    double tMax = 10;

    vector<double> tension = {y0, y0Prime * pas + y0};

    for (int i = 0; i < int(tMax / pas) - 2; i++)
    {
        tension.push_back(2 * tension.at(i + 1) - tension.at(i) + pas * pas * (E - tension.at(i)) / (L * C));
    }

    double min = tension.at(0);
    double max = tension.at(0);

    for (int i = 0; i < tension.size(); i++)
    {
        if (tension.at(i) > max)
        {
            max = tension.at(i);
        }

        if (tension.at(i) < min)
        {
            min = tension.at(i);
        }
    }

    cout << "Minimum de la tension : " << min << " maximum de la tension : " << max;

    return 0;
}