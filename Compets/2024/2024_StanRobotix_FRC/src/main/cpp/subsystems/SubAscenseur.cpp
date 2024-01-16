// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/PIDSubsystem.h>
#include "subsystems/SubAscenseur.h"

SubAscenseur::SubAscenseur()
{
    // Pour installer le PID
    mPIDController1.SetP(AscenseurConstants::kP);
    mPIDController1.SetI(AscenseurConstants::kI);
    mPIDController1.SetD(AscenseurConstants::kD);
    mPIDController1.SetIZone(AscenseurConstants::kIz);
    mPIDController1.SetFF(AscenseurConstants::kFF);

    mPIDController1.SetOutputRange(AscenseurConstants::kMinOutput, AscenseurConstants::kMaxOutput);
    mPIDController1.SetSmartMotionMaxVelocity(kMaxVel);
    mPIDController1.SetSmartMotionMinOutputVelocity(kMinVel);
    mPIDController1.SetSmartMotionMaxAccel(kMaxAcc);
    mPIDController1.SetSmartMotionAllowedClosedLoopError(kAllErr);

    mPIDController2.SetP(AscenseurConstants::kP);
    mPIDController2.SetI(AscenseurConstants::kI);
    mPIDController2.SetD(AscenseurConstants::kD);
    mPIDController2.SetIZone(AscenseurConstants::kIz);
    mPIDController2.SetFF(AscenseurConstants::kFF);

    mPIDController2.SetOutputRange(AscenseurConstants::kMinOutput, AscenseurConstants::kMaxOutput);
    mPIDController2.SetSmartMotionMaxVelocity(kMaxVel);
    mPIDController2.SetSmartMotionMinOutputVelocity(kMinVel);
    mPIDController2.SetSmartMotionMaxAccel(kMaxAcc);
    mPIDController2.SetSmartMotionAllowedClosedLoopError(kAllErr);
    // ---------------------
}

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