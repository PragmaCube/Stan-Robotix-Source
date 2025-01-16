// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include <iostream>
#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    m_frontLeft.SetInverted(false);
    m_frontRight550PID.EnableContinuousInput(0, 1);
    m_frontLeft550PID.EnableContinuousInput(0, 1);
    m_backLeft550PID.EnableContinuousInput(0, 1);
    m_backRight550PID.EnableContinuousInput(0, 1);
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::Init()
{
    
}


void SubDriveTrain::Drive(float iX, float iY, float i0)
{
    frc::ChassisSpeeds speeds{m_maxSpeedY * iY, m_maxSpeedX * iX, m_maxSpeed0 * i0};

    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);


    // std::cout << double(fl.angle) << std::endl;
    // std::cout << double(fr.angle) << std::endl;
    // std::cout << double(bl.angle) << std::endl;
    // std::cout << double(br.angle.Degrees()) << std::endl;

    // std::cout << double(br.speed)  << std::endl;

    // m_frontLeft550PID.SetSetpoint(0);
    // m_frontLeft550.Set(m_frontLeft550PID.Calculate(m_frontLeft550AbsoluteEncoder.GetPosition()));
    // m_frontLeft.Set(-0.04);

    // m_frontRight550PID.SetSetpoint(0);
    // m_frontRight550.Set(m_frontRight550PID.Calculate(m_frontRight550AbsoluteEncoder.GetPosition()));
    // m_frontRight.Set(-0.04);

    // m_backLeft550PID.SetSetpoint(0);
    // m_backLeft550.Set(m_backLeft550PID.Calculate(m_backLeft550AbsoluteEncoder.GetPosition()));
    // m_backLeft.Set(-0.04);

    // m_backRight550PID.SetSetpoint(0);
    // m_backRight550.Set(m_backRight550PID.Calculate(m_backRight550AbsoluteEncoder.GetPosition()));
    // m_backRight.Set(-0.04);

    frc::Rotation2d flCurrentAngle(units::degree_t(m_frontLeft550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto flOptimized = frc::SwerveModuleState::Optimize(fl, flCurrentAngle);
    flOptimized.speed *= (flOptimized.angle - flCurrentAngle).Cos();

    m_frontLeft550PID.SetSetpoint(double(flOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontLeft550.Set(m_frontLeft550PID.Calculate(m_frontLeft550AbsoluteEncoder.GetPosition()));
    m_frontLeft.Set(double(flOptimized.speed / m_maxSpeedX) * 0.2);



    frc::Rotation2d frCurrentAngle(units::degree_t(m_frontRight550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto frOptimized = frc::SwerveModuleState::Optimize(fr, frCurrentAngle);
    frOptimized.speed *= (frOptimized.angle - frCurrentAngle).Cos();

    m_frontRight550PID.SetSetpoint(double(frOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontRight550.Set(m_frontRight550PID.Calculate(m_frontRight550AbsoluteEncoder.GetPosition()));
    m_frontRight.Set(double(frOptimized.speed / m_maxSpeedX) * 0.2);



    frc::Rotation2d blCurrentAngle(units::degree_t(m_backLeft550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto blOptimized = frc::SwerveModuleState::Optimize(bl, blCurrentAngle);
    blOptimized.speed *= (blOptimized.angle - blCurrentAngle).Cos();

    m_backLeft550PID.SetSetpoint(double(blOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backLeft550.Set(m_backLeft550PID.Calculate(m_backLeft550AbsoluteEncoder.GetPosition()));
    m_backLeft.Set(double(blOptimized.speed / m_maxSpeedX) * 0.2);



    frc::Rotation2d brCurrentAngle(units::degree_t(m_backRight550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto brOptimized = frc::SwerveModuleState::Optimize(br, brCurrentAngle);
    brOptimized.speed *= (brOptimized.angle - brCurrentAngle).Cos();

    m_backRight550PID.SetSetpoint(double(brOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backRight550.Set(m_backRight550PID.Calculate(m_backRight550AbsoluteEncoder.GetPosition()));
    m_backRight.Set(double(brOptimized.speed / m_maxSpeedX) * 0.2);

    
    // m_backRight.Set(double(br.speed));
    std::cout << double(flOptimized.angle.Degrees()) << std::endl;
}
       