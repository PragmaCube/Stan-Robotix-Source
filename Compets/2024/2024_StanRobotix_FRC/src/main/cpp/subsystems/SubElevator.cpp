// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/PIDSubsystem.h>
#include "subsystems/SubElevator.h"

SubElevator::SubElevator()
{
    mPIDController1.SetP(ElevatorConstants::kP);
    mPIDController2.SetP(ElevatorConstants::kP);
    mPIDController1.SetI(ElevatorConstants::kI);
    mPIDController2.SetI(ElevatorConstants::kI);
    mPIDController1.SetD(ElevatorConstants::kD);
    mPIDController2.SetD(ElevatorConstants::kD);
    
    mPIDController1.SetFF(ElevatorConstants::kFF);
    mPIDController2.SetFF(ElevatorConstants::kFF);
    mPIDController1.SetOutputRange(ElevatorConstants::kMinOutput, ElevatorConstants::kMaxOutput);
}

// This method will be called once per scheduler run
void SubElevator::Periodic() {}

double SubElevator::getTargetPosition()
{
    return mTargetPosition;
}

void SubElevator::setTargetPosition(double iTargetPosition)
{
    mTargetPosition = iTargetPosition;
}

void SubElevator::manualMoveElevator(double iVitesse)
{
    mElevatorMotor1.Set(iVitesse);
    mElevatorMotor2.Set(-iVitesse);
}

void SubElevator::setElevatorPosition()
{
    mPIDController1.SetReference(mTargetPosition, rev::CANSparkMax::ControlType::kSmartMotion);
    mPIDController2.SetReference(-mTargetPosition, rev::CANSparkMax::ControlType::kSmartMotion);
}

double SubElevator::getEncoderPositionMotor(NumberMotor iNumberMotor)
{
    switch (iNumberMotor)
    {
    case Motor1:
        return mElevatorMotor1Encoder.GetPosition();
    case Motor2:
        return mElevatorMotor2Encoder.GetPosition();
    default:
        return 0;
    }
}

double SubElevator::getVelocityMotor(NumberMotor iNumberMotor)
{
    switch (iNumberMotor)
    {
    case Motor1:
        return mElevatorMotor1Encoder.GetVelocity();

    case Motor2:
        return mElevatorMotor2Encoder.GetVelocity();
    default:
        return 0;
    }
}

void SubElevator::stopElevatorMotors()
{
    mPIDController1.SetReference(0, rev::CANSparkMax::ControlType::kDutyCycle);
    mPIDController2.SetReference(0, rev::CANSparkMax::ControlType::kDutyCycle);
}

bool SubElevator::isMotorStruggling()
{
    return (mElevatorMotor1.GetOutputCurrent() >= 32);
}

double SubElevator::MotorStruggling()
{
    return mElevatorMotor1.GetOutputCurrent();
}

void SubElevator::setEnable(bool iEnable)
{
    mEnable = iEnable;
}

bool SubElevator::isEnable() 
{
    return mEnable;
}