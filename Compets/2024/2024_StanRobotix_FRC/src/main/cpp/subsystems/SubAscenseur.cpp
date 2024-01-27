// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/PIDSubsystem.h>
#include "subsystems/SubAscenseur.h"

SubAscenseur::SubAscenseur()
{
    // mPIDController1.SetP(AscenseurConstants::kP);
    // mPIDController2.SetP(AscenseurConstants::kP);
    // mPIDController1.SetI(AscenseurConstants::kI);
    // mPIDController2.SetI(AscenseurConstants::kI);
    // mPIDController1.SetD(AscenseurConstants::kD);
    // mPIDController2.SetD(AscenseurConstants::kD);
    
    // mPIDController1.SetFF(AscenseurConstants::kFF);
    // mPIDController2.SetFF(AscenseurConstants::kFF);
    // mPIDController1.SetOutputRange(AscenseurConstants::kMinOutput, AscenseurConstants::kMaxOutput);
}

// This method will be called once per scheduler run
void SubAscenseur::Periodic() {}

double SubAscenseur::getPositionVoulue()
{
    return PositionVoulue;
}

void SubAscenseur::setPositionVoulue(double iPositionVoulue)
{
    PositionVoulue = iPositionVoulue;
}

void SubAscenseur::bougeAscenseur(double iVitesse)
{
    mAscenseurMotor1.Set(iVitesse);
    mAscenseurMotor2.Set(-iVitesse);
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

double SubAscenseur::getVelocityMotor1()
{
    return mAscenseurMotor1Encoder.GetVelocity();
}

double SubAscenseur::getVelocityMotor2()
{
    return mAscenseurMotor2Encoder.GetVelocity();
}

void SubAscenseur::stopAscenseurMotors()
{
    mPIDController1.SetReference(0, rev::CANSparkMax::ControlType::kDutyCycle);
    mPIDController2.SetReference(0, rev::CANSparkMax::ControlType::kDutyCycle);
}