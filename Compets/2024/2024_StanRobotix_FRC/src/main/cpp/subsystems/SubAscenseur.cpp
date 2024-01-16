// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/PIDSubsystem.h>
#include "subsystems/SubAscenseur.h"
#include "Constants.h"

SubAscenseur::SubAscenseur()
{
    // Pour installer le PID
    mPIDController.SetP(AscenseurConstants::kP);
    mPIDController.SetI(AscenseurConstants::kI);
    mPIDController.SetD(AscenseurConstants::kD);
    mPIDController.SetIZone(AscenseurConstants::kIz);
    mPIDController.SetFF(AscenseurConstants::kFF);

    mPIDController.SetOutputRange(AscenseurConstants::kMinOutput, AscenseurConstants::kMaxOutput);
    mPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    mPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    mPIDController.SetSmartMotionMaxAccel(kMaxAcc);
    mPIDController.SetSmartMotionAllowedClosedLoopError(kAllErr);
    // ---------------------
}

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

void SubAscenseur::bougeAscenseur(double iVitesse)
{
    mAscenseurMotor1.Set(iVitesse);
    mAscenseurMotor2.Set(iVitesse);
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
    mAscenseurMotor1.Set(0);
    mAscenseurMotor2.Set(0);
}