#include "complexe.h"

NombreComplexe::NombreComplexe() { }

NombreComplexe::~NombreComplexe() { }

double NombreComplexe::getPartieRelle()
{
    return partieRelle;
}

double NombreComplexe::getPartieImaginaire()
{
    return partieImaginaire;
}

void NombreComplexe::setPartieReelle(double PartieReelle)
{
    partieRelle = PartieReelle;
}

void NombreComplexe::setPartieImaginaire(double PartieImaginaire)
{
    partieImaginaire = PartieImaginaire;
}

NombreComplexe additionComplexe(NombreComplexe z, NombreComplexe w)
{
    NombreComplexe v;

    v.setPartieReelle(z.getPartieRelle() + w.getPartieRelle());
    v.setPartieImaginaire(z.getPartieImaginaire() + w.getPartieImaginaire());

    return v;
}

NombreComplexe multiplicationComplexe(NombreComplexe z, NombreComplexe w)
{
    NombreComplexe v;

    v.setPartieReelle(z.getPartieRelle() * w.getPartieRelle() - z.getPartieImaginaire() * w.getPartieImaginaire());
    v.setPartieImaginaire(z.getPartieImaginaire() * w.getPartieRelle() + z.getPartieRelle() * w.getPartieImaginaire());

    return v;
}

NombreComplexe divisionComplexe(NombreComplexe z, NombreComplexe w)
{
    NombreComplexe v;

    v.setPartieReelle((z.getPartieRelle() * w.getPartieRelle() + z.getPartieImaginaire() * w.getPartieImaginaire()) / (w.getPartieRelle() * w.getPartieRelle() + w.getPartieImaginaire() * w.getPartieImaginaire()));
    v.setPartieImaginaire((z.getPartieImaginaire() * w.getPartieRelle() - z.getPartieRelle() * w.getPartieImaginaire()) / (w.getPartieRelle() * w.getPartieRelle() + w.getPartieImaginaire() * w.getPartieImaginaire()));

    return v;
}