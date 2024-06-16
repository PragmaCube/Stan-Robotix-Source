#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "mastermind.h"

Mastermind::Mastermind() 
{
    tentatives = 0;

    code[0] = Rien;
    code[1] = Rien;
    code[2] = Rien;
    code[3] = Rien;

    essai[0] = Rien;
    essai[1] = Rien;
    essai[2] = Rien;
    essai[3] = Rien;
}

Mastermind::~Mastermind() { }

int Mastermind::getBienPlace()
{
    int compteur = 0;

    for (int i = 0; i < 4; i++)
    {
        if (code[i] == essai[i])
        {
            compteur++;
        }
    }

    return compteur;
}

int Mastermind::getMalPlace()
{
    int compteur = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (code[i] == essai[j] && i != j)
            {
                compteur++;
            }
        }
    }

    return compteur;
}

int Mastermind::getTentatives()
{
    return tentatives;
}

void Mastermind::nouvelEssai(Couleur Essai[4])
{
    essai[0] = Essai[0];
    essai[1] = Essai[1];
    essai[2] = Essai[2];
    essai[3] = Essai[3];

    tentatives++;
}

void Mastermind::genererCode()
{
    int couleur = 0;
    int compteur = 0;

    bool dejaPris[8] = {false, false, false, false, false, false, false, false};
    
    while (compteur < 4)
    {
        couleur = rand() % 8;

        if (!dejaPris[couleur])
        {
            dejaPris[couleur] = true;

            switch (couleur)
            {
            case 0:
                code[compteur] = Rouge;
                break;

            case 1:
                code[compteur] = Vert;
                break;

            case 2:
                code[compteur] = Bleu;
                break;

            case 3:
                code[compteur] = Jaune;
                break;

            case 4:
                code[compteur] = Gris;
                break;

            case 5:
                code[compteur] = Blanc;
                break;

            case 6:
                code[compteur] = Rose;
                break;

            case 7:
                code[compteur] = Orange;
                break;
            
            default:
                code[compteur] = Rien;
                break;
            }

            compteur++;
        }
    }
}

void Mastermind::afficherCode()
{
    for (int i = 0; i < 4; i++)
    {
        switch (code[i])
        {
        case Rouge:
            cout << "Couleur " << i + 1 << " : rouge.\n";
            break;

        case Vert:
            cout << "Couleur " << i + 1 << " : vert.\n";
            break;

        case Bleu:
            cout << "Couleur " << i + 1 << " : bleu.\n";
            break;

        case Jaune:
            cout << "Couleur " << i + 1 << " : jaune.\n";
            break;

        case Gris:
            cout << "Couleur " << i + 1 << " : gris.\n";
            break;

        case Blanc:
            cout << "Couleur " << i + 1 << " : blanc.\n";
            break;

        case Rose:
            cout << "Couleur " << i + 1 << " : rose.\n";
            break;

        case Orange:
            cout << "Couleur " << i + 1 << " : orange.\n";
            break;
        
        default:
            break;
        }
    }
}