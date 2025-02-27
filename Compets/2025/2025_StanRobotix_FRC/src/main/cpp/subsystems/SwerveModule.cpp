// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>

#include "subsystems/SwerveModule.h"

SwerveModule::SwerveModule(int iNeoMotorID, int iNeo550MotorID)
{
    // Initialization of the motor controllers with the motorID constructor input
    m_MotorNeo = new rev::spark::SparkMax{iNeoMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    m_MotorNeo550 = new rev::spark::SparkMax{iNeo550MotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};

    // Initialization of the PIDController with the P,I and D constants and a continuous input from 0 to 1
    m_Neo550PID = new frc::PIDController{DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};
    m_Neo550PID->EnableContinuousInput(0,1);

    // Initialization of the motor's encoders and absolute encoder
    m_NeoEncoder = new rev::spark::SparkRelativeEncoder{m_MotorNeo->GetEncoder()};
    m_Neo550Encoder = new rev::spark::SparkRelativeEncoder{m_MotorNeo550->GetEncoder()};
    m_Neo550AbsoluteEncoder = new rev::spark::SparkAbsoluteEncoder{m_MotorNeo550->GetAbsoluteEncoder()};

    // Initialization of the molule's SwerveModulePosition and SwerveModuleState from the encoder's velocity and position
    m_ModuleState = new frc::SwerveModuleState{units::meters_per_second_t(m_NeoEncoder->GetVelocity()*DriveTrainConstants::kGearRatio*DriveTrainConstants::kWheelPerimeter),
                                              frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 2 * std::numbers::pi)};
    m_ModulePosition = new frc::SwerveModulePosition{units::meter_t(m_NeoEncoder->GetPosition()*DriveTrainConstants::kGearRatio*DriveTrainConstants::kWheelPerimeter),
                                              frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 2 * std::numbers::pi)};
}

frc::SwerveModuleState SwerveModule::OptimizeState(frc::SwerveModuleState iDesiredState)
{
    frc::SwerveModuleState OptimizedState = iDesiredState;
    frc::Rotation2d Neo550CurrentAngle(units::degree_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 360);
    OptimizedState.Optimize(Neo550CurrentAngle);
    OptimizedState.CosineScale(Neo550CurrentAngle);
    return OptimizedState;
}

void SwerveModule::setDesiredState(frc::SwerveModuleState iDesiredState)
{
    frc::SwerveModuleState OptimizedState = OptimizeState(iDesiredState);
    m_Neo550PID->SetSetpoint(double(OptimizedState.angle.Radians() / (2 * std::numbers::pi)) + 0.5);
    m_MotorNeo550->Set(m_Neo550PID->Calculate(m_Neo550AbsoluteEncoder->GetPosition()));
    m_MotorNeo->Set(double(OptimizedState.speed * (1 / units::meters_per_second_t(DriveTrainConstants::kMaxSpeed)) * DriveTrainConstants::kSpeedCap));
    // std::cout << m_Neo550PID->Calculate(m_Neo550AbsoluteEncoder->GetPosition()) << std::endl;
}

void SwerveModule::setNeoInverted(bool iInverted)
{
    m_MotorNeo->SetInverted(iInverted);
}

frc::SwerveModuleState SwerveModule::getModuleState()
{
//     *m_ModuleState = frc::SwerveModuleState{units::meters_per_second_t(m_Neo550Encoder->GetVelocity()*DriveTrainConstants::kGearRatio*DriveTrainConstants::kWheelPerimeter),
//                                             frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 2 * std::numbers::pi)};
    return *m_ModuleState;
}

frc::SwerveModulePosition SwerveModule::getModulePosition()
{
    // *m_ModulePosition = frc::SwerveModulePosition{units::meter_t(m_Neo550Encoder->GetPosition()*DriveTrainConstants::kGearRatio*DriveTrainConstants::kWheelPerimeter),
    //                                              frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 2 * std::numbers::pi)};
    return *m_ModulePosition;
}

void SwerveModule::refreshModule()
{
    *m_ModuleState = frc::SwerveModuleState{units::meters_per_second_t(m_NeoEncoder->GetVelocity()*DriveTrainConstants::kGearRatio*DriveTrainConstants::kWheelPerimeter),
                                            frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 2 * std::numbers::pi)};
    *m_ModulePosition = frc::SwerveModulePosition{units::meter_t(m_NeoEncoder->GetPosition()*DriveTrainConstants::kGearRatio*DriveTrainConstants::kWheelPerimeter),
                                                 frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 2 * std::numbers::pi)};
}