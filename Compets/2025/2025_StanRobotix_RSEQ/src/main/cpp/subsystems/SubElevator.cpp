// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubElevator.h"

SubElevator::SubElevator()
{
    mElevatorMotor = new rev::spark::SparkMax{ElevatorConstants::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};

    mPIDController = new frc::PIDController{ElevatorConstants::kP, ElevatorConstants::kI, ElevatorConstants::kD};
    mPIDController->SetTolerance(0.01);
    mProfiledPIDController = new frc::ProfiledPIDController<units::radians>{ElevatorConstants::kP, ElevatorConstants::kI, ElevatorConstants::kD, ElevatorConstants::kConstraints};
    mProfiledPIDController->SetTolerance(ElevatorConstants::kTolerance);

    mFeedForward = new frc::ElevatorFeedforward{ElevatorConstants::kS, ElevatorConstants::kG, ElevatorConstants::kV, ElevatorConstants::kA};

    mSparkMaxConfig = new rev::spark::SparkMaxConfig{};

    mSparkMaxConfig->encoder.PositionConversionFactor(ElevatorConstants::kGearRatio);
    mSparkMaxConfig->encoder.VelocityConversionFactor(ElevatorConstants::kGearRatio);

    mElevatorMotor->Configure(*mSparkMaxConfig, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kNoPersistParameters);

    mRelativeEncoder = new rev::spark::SparkRelativeEncoder{mElevatorMotor->GetEncoder()};
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
    mElevatorMotor->SetVoltage(ElevatorConstants::kG);
}

void SubElevator::SetPosition(double iSetpoint)
{
    mPIDController->SetSetpoint(iSetpoint);
    double elevatorPositionMeters = ((mRelativeEncoder->GetPosition() + ElevatorConstants::kOffset) * ElevatorConstants::kConvertionToMetersFactor);
    units::volt_t CalculatedPID = units::volt_t(mPIDController->Calculate(elevatorPositionMeters) * 13);

    mElevatorMotor->SetVoltage(CalculatedPID + ElevatorConstants::kG + ElevatorConstants::kS * sgn(-mRelativeEncoder->GetVelocity()));
}

void SubElevator::SetPositionFeedForward(units::radian_t iGoal)
{
    mProfiledPIDController->SetGoal(iGoal);

    units::meters_per_second_t desiredVelocity = units::meters_per_second_t(mProfiledPIDController->Calculate(units::radian_t((mRelativeEncoder->GetPosition() + ElevatorConstants::kOffset) * ElevatorConstants::kConvertionToMetersFactor)));
    units::meters_per_second_t currentVelocity = units::meters_per_second_t(mRelativeEncoder->GetVelocity() * ElevatorConstants::kConvertionToMetersFactor);
    // units::radians_per_second_squared_t desiredAcceleration = (mProfiledPIDController->GetSetpoint().velocity.value() - mLastVelocity) / (frc::Timer::GetFPGATimestamp() - mLastTime);

    mElevatorMotor->SetVoltage(mFeedForward->Calculate(currentVelocity, desiredVelocity, frc::Timer::GetFPGATimestamp() - mLastTime));

    mLastTime = frc::Timer::GetFPGATimestamp();
}

void SubElevator::MesureCurrentTime()
{
    mLastTime = frc::Timer::GetFPGATimestamp();
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

bool SubElevator::AtSetpointFeedForward()
{
    return mProfiledPIDController->AtGoal();
}

void SubElevator::DefaultCommand()
{
    Stop();
}