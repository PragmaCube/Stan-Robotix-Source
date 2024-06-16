#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> occurences = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vector<float> observations = {0.17, 0.26, 0.35, 0.51, 0.55, 0.45, 0.6, 0.63, 0.68, 0.72, 0.79, 0.86, 0.82, 0.9, 0.88, 0.93, 0.97, 1.0, 1.1, 1.11, 1.15};

    float totalOccurences = 0, totalObservations = 0;
    float a = 0.4435;

    for (int i = 0; i < occurences.size(); i++)
    {
        totalOccurences += occurences[i];
        totalObservations += observations[i];
    }

    float b = totalObservations / observations.size() - a * totalOccurences / occurences.size();

    cout << "La valeur attendue pour la 21e occurence est : " << a * 21 + b;

    return 0;
}