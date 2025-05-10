// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubElevator.h"

SubElevator::SubElevator()
{
    mElevatorMotor = new rev::spark::SparkMax{ElevatorConstants::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mPIDController = new frc::PIDController{ElevatorConstants::kP, ElevatorConstants::kI, ElevatorConstants::kD};
    mRelativeEncoder = new rev::spark::SparkRelativeEncoder{mElevatorMotor->GetEncoder()};
    mProfiledPIDController = new frc::ProfiledPIDController<units::radians>{ElevatorConstants::kP, ElevatorConstants::kI, ElevatorConstants::kD, ElevatorConstants::kConstraints};
    mFeedForward = new frc::ElevatorFeedforward{ElevatorConstants::kS, ElevatorConstants::kG, ElevatorConstants::kV, ElevatorConstants::kA};
    mPIDController->SetTolerance(0.01);
    mProfiledPIDController->SetTolerance(ElevatorConstants::kTolerance);
}

// This method will be called once per scheduler run
void SubElevator::Periodic() {}

void SubElevator::manualUp()
{
    mElevatorMotor->Set(-0.03);
}

void SubElevator::manualDown()
{
    mElevatorMotor->Set(0.03);
}

void SubElevator::Stop()
{
    mElevatorMotor->StopMotor();
}

void SubElevator::CounterGravity()
{
    mElevatorMotor->SetVoltage(ElevatorConstants::kG * -1);
}

void SubElevator::SetPosition(double iSetpoint)
{
    mPIDController->SetSetpoint(iSetpoint);
    double elevatorPositionMeters = (-(mRelativeEncoder->GetPosition() + ElevatorConstants::kOffset) / 20 * 0.14);
    units::volt_t CalculatedPID = units::volt_t(mPIDController->Calculate(elevatorPositionMeters) * 13);

    mElevatorMotor->SetVoltage((CalculatedPID + ElevatorConstants::kG + ElevatorConstants::kS * sgn(-mRelativeEncoder->GetVelocity())) * -1);
}

void SubElevator::SetPositionFeedForward(double iSetpoint)
{
    mProfiledPIDController->SetGoal
}

int SubElevator::sgn(double iInput)
{
    if (iInput > 0)
    {
        return 1;
    }
    else if (iInput < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

bool SubElevator::AtSetpoint()
{
    return mPIDController->AtSetpoint();
}

void SubElevator::DefaultCommand()
{
    Stop();
}