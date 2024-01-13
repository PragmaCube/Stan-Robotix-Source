// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAscenseur.h"
#include "Constants.h"

SubAscenseur::SubAscenseur() = default;

// This method will be called once per scheduler run
void SubAscenseur::Periodic() {}

int SubAscenseur::getVitesse()
{
    return vitesse;
}

void SubAscenseur::setVitesse(float Vitesse)
{
    vitesse = Vitesse;
}

void SubAscenseur::Set(double iVitesse)
{
    SubAscenseur.Set(iVitesse);
}