#include <iostream>
#include <random>
using namespace std;

int main()
{
    int moins2 = 0, moins1 = 0, entre1 = 0, plus1 = 0, plus2 = 0;
    
    random_device systeme{};
    mt19937 generateur{systeme()};
    normal_distribution<float> distribution{0.0, 1.0};

    for (int i=0; i < 200; i++)
    {      
        float nombre = distribution(generateur);
        
        if (nombre > 2)
        {
            plus2++ ; 
        }

        else if (nombre > 1)
        {
            plus1++ ; 
        }

        else if (nombre >= -1)
        {
            entre1++ ; 
        }

        else if (nombre >= -2)
        {
            moins1++ ; 
        }

        else
        {
            moins2++ ; 
        }
    }
  
    cout << "\nx < -2       : ";

    for (int k = 0; k < moins2 / 3; k++)
    {
        cout << "*";
    }

    cout << "\nx < -1       : ";

    for (int k = 0; k < moins1 / 3; k++)
    {
        cout << "*";
    }

    cout << "\n-1 <= x <= 1 : ";

    for (int k = 0; k < entre1 / 3; k++)
    {
        cout << "*";
    }

    cout << "\nx >  1       : ";

    for (int k = 0; k < plus1 / 3; k++)
    {
        cout << "*";
    }

    cout << "\nx >  2       : ";

    for (int k = 0; k < plus2 / 3; k++)
    {
        cout << "*";
    }

    cout << endl;

    return 0;
}