// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubElevator.h"

SubElevator::SubElevator()
{
    mElevatorMotor = new rev::spark::SparkMax{ElevatorConstants::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mPIDController = new frc::PIDController{ElevatorConstants::kP, ElevatorConstants::kI, ElevatorConstants::kD};
    mRelativeEncoder = new rev::spark::SparkRelativeEncoder{mElevatorMotor->GetEncoder()};
    mPIDController->SetTolerance(0.01);
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
    mElevatorMotor->SetVoltage(-units::voltage::volt_t(ElevatorConstants::kG));
}

void SubElevator::SetPosition(double iSetpoint)
{
    mPIDController->SetSetpoint(iSetpoint);
    double elevatorPositionMeters = (-(mRelativeEncoder->GetPosition() + ElevatorConstants::kOffset) / 20 * 0.14);
    double CalculatedPID = mPIDController->Calculate(elevatorPositionMeters) * 13;

    mElevatorMotor->SetVoltage(-units::voltage::volt_t(CalculatedPID + ElevatorConstants::kG + ElevatorConstants::kS * sgn(-mRelativeEncoder->GetVelocity())));
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

void SubElevator::DefaultCommand()
{
    Stop();
}