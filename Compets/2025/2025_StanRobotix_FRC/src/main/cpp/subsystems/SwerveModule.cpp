// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SwerveModule.h"

SwerveModule::SwerveModule(int iNeo550MotorID, int iNeoMotorID)
{
    m_MotorNeo = new rev::spark::SparkMax{iNeoMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    m_MotorNeo550 = new rev::spark::SparkMax{iNeo550MotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    m_Neo550PID = new frc::PIDController{DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};
    m_Neo550PID->EnableContinuousInput(0,1);
    m_NeoEncoder = new rev::spark::SparkRelativeEncoder{m_MotorNeo->GetEncoder()};
    m_Neo550Encoder = new rev::spark::SparkRelativeEncoder{m_MotorNeo550->GetEncoder()};
    m_Neo550AbsoluteEncoder = new rev::spark::SparkAbsoluteEncoder{m_MotorNeo550->GetAbsoluteEncoder()};
    m_ModuleState = new frc::SwerveModuleState{units::meters_per_second_t(m_Neo550Encoder->GetVelocity()*m_gearRatio*m_wheelPerimeter),
                                              frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * std::numbers::pi)};
    m_ModulePosition = new frc::SwerveModulePosition{units::meter_t(m_Neo550Encoder->GetPosition()*m_gearRatio*m_wheelPerimeter),
                                              frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * std::numbers::pi)};
}

frc::SwerveModulePosition SwerveModule::getModulePosition()
{
    return frc::SwerveModulePosition{units::meter_t(m_Neo550Encoder->GetPosition()*m_gearRatio*m_wheelPerimeter),
                                    frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * std::numbers::pi)};
}

double SwerveModule::OptimizeAngle(frc::SwerveModuleState * iDesiredState)
{
    frc::Rotation2d Neo550CurrentAngle(units::degree_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * 360);
    iDesiredState->Optimize(Neo550CurrentAngle);
    iDesiredState->CosineScale(Neo550CurrentAngle);
    iDesiredState->angle;
    double OptimizedAngle(m_ModuleState->angle.Radians());
    return OptimizedAngle;
}

void SwerveModule::setDesiredState(frc::SwerveModuleState * iDesiredState)
{
    m_Neo550PID->SetSetpoint(OptimizeAngle(iDesiredState) / (2*std::numbers::pi) + 0.5);
    m_MotorNeo550->Set(m_Neo550PID->Calculate(m_Neo550AbsoluteEncoder->GetPosition()));
    m_MotorNeo->Set(OptimizeAngle(iDesiredState) * DriveTrainConstants::speedCap);
}

void SwerveModule::setNeoInverted(bool iInverted)
{
    m_MotorNeo->SetInverted(iInverted);
}

frc::SwerveModuleState SwerveModule::getModuleState()
{
    return frc::SwerveModuleState{units::meters_per_second_t(m_Neo550Encoder->GetVelocity()*m_gearRatio*m_wheelPerimeter),
                                 frc::Rotation2d(units::radian_t(m_Neo550AbsoluteEncoder->GetPosition() - 0.5) * std::numbers::pi)};
}