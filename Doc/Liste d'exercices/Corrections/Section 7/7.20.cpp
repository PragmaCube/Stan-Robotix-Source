#include <iostream>
#include <vector>
using namespace std;

float produitScalaire(vector<float> v, vector<float> w)
{
    if (v.size() != w.size())
    {
        return 0;
    }

    float somme = 0;

    for (int i = 0; i < v.size(); i++)
    {
        somme += v.at(i) * w.at(i);
    }

    return somme;
}

vector<float> produitVectoriel(vector<float> v, vector<float> w)
{
    if (v.size() != w.size() || v.size() != 3 || w.size() != 3)
    {
        return vector<float>{0, 0, 0};
    }

    return vector<float>{v.at(1) * w.at(2) - v.at(2) * w.at(1),
                        v.at(2) * w.at(0) - v.at(0) * w.at(2),
                        v.at(0) * w.at(1) - v.at(1) * w.at(0)};
}

int main()
{
    vector<float> v = {1, 3, 2};
    vector<float> w = {-2, -2, 4};
    vector<float> produit = produitVectoriel(v, w);

    cout << "Produit scalaire de v et w : " << produitScalaire(v, w) << endl;
    cout << "Produit vectoriel de v et w : " << produit.at(0) << ", " << produit.at(1) << ", " << produit.at(2) << endl;
    cout << "Produit scalaire de v et v * w : " << produitScalaire(v, produit) << endl;
    cout << "Produit scalaire de w et v * w : " << produitScalaire(w, produit) << endl;

    return 0;
}