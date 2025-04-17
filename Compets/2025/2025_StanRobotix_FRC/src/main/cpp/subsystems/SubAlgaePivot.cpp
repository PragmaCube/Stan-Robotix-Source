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

void SubAlgaePivot::Stop()
{
    mAlgaePivotMotor->StopMotor();
}

void SubAlgaePivot::SetPosition(double Setpoint)
{
    mPIDController->SetSetpoint(Setpoint);

    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + AlgaeConstants::Pivot::kOffset) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController->Calculate((mAlgaePivotMotor->GetEncoder().GetPosition() + AlgaeConstants::Pivot::kOffset) / 80 * 2 * std::numbers::pi) * 13;

    mAlgaePivotMotor->SetVoltage((units::volt_t(AlgaeConstants::Pivot::kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID)); //
}

bool SubAlgaePivot::AtSetPoint()
{
    return mPIDController->AtSetpoint();
}

void SubAlgaePivot::Climb()
{
    mAlgaePivotMotor->SetVoltage(units::volt_t(-2.5));
}

void SubAlgaePivot::StayStill()
{
    mAlgaePivotMotor->SetVoltage(units::volt_t(-0.75));
}

void SubAlgaePivot::PivotUpSmooth()
{
    mAlgaePivotMotor->SetVoltage(units::volt_t(0.95));
}

void SubAlgaePivot::CounterGravity()
{
    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + AlgaeConstants::Pivot::kOffset) / 80 * 2 * std::numbers::pi;
    mAlgaePivotMotor->SetVoltage(units::volt_t(AlgaeConstants::Pivot::kG) * cos(pivotPositionRad));
}

/*
    le setpoint doit etre donné en tours, même type que le cout.
    le cout renvoi la position du pivot entre -1 et 1, avec 0 comme pivot horizontale.
    le PID devrait calculer une valeur aussi entre -1 et 1, qui se fait multiplier par 13 pour avoir une nombre utilisable de volts.
*/