// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubReefPivot.h"

SubReefPivot::SubReefPivot()
{
    mMotor = new rev::spark::SparkMax{ReefConstants::Pivot::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};

    mPIDController = new frc::PIDController{ReefConstants::Pivot::kP, ReefConstants::Pivot::kI, ReefConstants::Pivot::kD};
}

// This method will be called once per scheduler run
void SubReefPivot::Periodic() {}

void SubReefPivot::Stop()
{
    mMotor->StopMotor();
}

void SubReefPivot::SetPosition(double Setpoint)
{
    mPIDController->SetSetpoint(Setpoint);

    double pivotPositionRad = (mMotor->GetEncoder().GetPosition() + ReefConstants::Pivot::kOffset) / 20 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController->Calculate((mMotor->GetEncoder().GetPosition() + ReefConstants::Pivot::kOffset) / 20 * 2 * std::numbers::pi) * 13;

    mMotor->SetVoltage(-(units::volt_t(ReefConstants::Pivot::kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID)); //
    // std::cout << CalculatedPID << std::endl;
}

bool SubReefPivot::AtSetPoint()
{
    return mPIDController->AtSetpoint();
}

void SubReefPivot::CounterGravity()
{
    double pivotPositionRad = (mMotor->GetEncoder().GetPosition() + ReefConstants::Pivot::kOffset) / 16 * 2 * std::numbers::pi;
    mMotor->SetVoltage(-(units::volt_t(ReefConstants::Pivot::kG * cos(pivotPositionRad))));
}

void SubReefPivot::SetVoltage(double iVoltage)
{
    mMotor->SetVoltage(units::volt_t(iVoltage));
}