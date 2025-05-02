// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAlgaePivot.h"
#include <cmath>

SubAlgaePivot::SubAlgaePivot()
{
    mAlgaePivotMotor = new rev::spark::SparkMax{AlgaeConstants::Pivot::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mPIDController = new frc::PIDController{AlgaeConstants::Pivot::kP, AlgaeConstants::Pivot::kI, AlgaeConstants::Pivot::kD};
}

// This method will be called once per scheduler run
void SubAlgaePivot::Periodic() {}

double SubAlgaePivot::GetAngle()
{
    return (mAlgaePivotMotor->GetEncoder().GetPosition() + AlgaeConstants::Pivot::kOffset) / AlgaeConstants::Pivot::gearRatio * 2*std::numbers::pi;
}

void SubAlgaePivot::Stop()
{
    mAlgaePivotMotor->StopMotor();
}

void SubAlgaePivot::SetPosition(double Setpoint)
{
    mPIDController->SetSetpoint(Setpoint);
    double pivotAngle = GetAngle();
    double Output = mPIDController->Calculate(pivotAngle) * 13;

    mAlgaePivotMotor->SetVoltage((AlgaeConstants::Pivot::kG * cos(pivotAngle)) + units::volt_t(Output));
}

bool SubAlgaePivot::AtSetPoint()
{
    return mPIDController->AtSetpoint();
}

void SubAlgaePivot::SetVoltage(units::volt_t iVoltage){
    mAlgaePivotMotor->SetVoltage(iVoltage);
}

void SubAlgaePivot::CounterGravity()
{
    double pivotAngle = GetAngle();
    mAlgaePivotMotor->SetVoltage(AlgaeConstants::Pivot::kG * cos(pivotAngle));
}

/*
    le setpoint doit etre donné en tours, même type que le cout.
    le cout renvoi la position du pivot entre -1 et 1, avec 0 comme pivot horizontale.
    le PID devrait calculer une valeur aussi entre -1 et 1, qui se fait multiplier par 13 pour avoir une nombre utilisable de volts.
*/