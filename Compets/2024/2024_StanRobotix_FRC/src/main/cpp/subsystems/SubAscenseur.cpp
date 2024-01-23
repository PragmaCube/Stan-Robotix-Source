// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/PIDSubsystem.h>
#include "subsystems/SubAscenseur.h"

SubAscenseur::SubAscenseur()
{

}

// This method will be called once per scheduler run
void SubAscenseur::Periodic() {}

double SubAscenseur::getVitesse()
{
    return vitesse;
}

void SubAscenseur::setVitesse(double Vitesse)
{
    vitesse = Vitesse;
}

void SubAscenseur::bougeAscenseur(double vitesse)
{
    mPIDController1.SetReference(vitesse, rev::CANSparkMax::ControlType::kDutyCycle);
    mPIDController2.SetReference(-vitesse, rev::CANSparkMax::ControlType::kDutyCycle);
}

void SubAscenseur::setPositionAscenseur(double iPosition)
{
    mPIDController1.SetReference(iPosition, rev::CANSparkMax::ControlType::kSmartMotion);
    mPIDController2.SetReference(-iPosition, rev::CANSparkMax::ControlType::kSmartMotion);
}

double SubAscenseur::getEncoderPositionMotor1()
{
    return mAscenseurMotor1Encoder.GetPosition();
}

double SubAscenseur::getEncoderPositionMotor2()
{
    return mAscenseurMotor2Encoder.GetPosition();
}

void SubAscenseur::stopAscenseurMotors()
{
    mPIDController1.SetReference(0,rev::CANSparkMax::ControlType::kDutyCycle);
    mPIDController2.SetReference(0,rev::CANSparkMax::ControlType::kDutyCycle);
}