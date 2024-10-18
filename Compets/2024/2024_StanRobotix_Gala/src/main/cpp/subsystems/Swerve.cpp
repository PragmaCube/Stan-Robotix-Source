// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include <iostream>
#include "subsystems/Swerve.h"

Swerve::Swerve() = default;

// This method will be called once per scheduler run
void Swerve::Periodic() {}

void Swerve::Init()
{
    
}

    // float A = iX - i0*(0.125);
    // float B = iX + i0*(0.125);
    // float C = iY - i0*(0.125);
    // float D = iY + i0*(0.125);

    // float Vfr = -sqrt(B*B + C*C)/2;
    // float Vfl = sqrt(B*B + D*D)/2;
    // float Vbl = sqrt(A*A + D*D)/2;
    // float Vbr = sqrt(A*A + C*C)/2;

    // m_frontRight.Set(Vfr);
    // m_frontRight550PID.SetSetpoint(atan2(B, C) / (2*std::numbers::pi) + 0.5);
    // m_frontRight550.Set(m_frontRight550PID.Calculate(m_frontRight550AbsoluteEncoder.GetPosition()));

    // m_frontLeft.Set(Vfl);
    // m_frontLeft550PID.SetSetpoint(atan2(B, D) / (2*std::numbers::pi) + 0.5);
    // m_frontLeft550.Set(m_frontLeft550PID.Calculate(m_frontLeft550AbsoluteEncoder.GetPosition()));
    
    // m_backLeft.Set(Vbl);
    // m_backLeft550PID.SetSetpoint(atan2(A, D) / (2*std::numbers::pi) + 0.5);
    // m_backLeft550.Set(m_backLeft550PID.Calculate(m_backLeft550AbsoluteEncoder.GetPosition()));
    
    // m_backRight.Set(Vbr);
    // m_backRight550PID.SetSetpoint(atan2(A, C) / (2*std::numbers::pi) + 0.5);
    // m_backRight550.Set(m_backRight550PID.Calculate(m_backRight550AbsoluteEncoder.GetPosition()));


void Swerve::Move(float iX, float iY, float i0)
{
    frc::ChassisSpeeds speeds{m_maxSpeedY * iY, m_maxSpeedX * iX, m_maxSpeed0 * i0};

    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);


    // std::cout << double(fl.angle) << std::endl;
    // std::cout << double(fr.angle) << std::endl;
    // std::cout << double(bl.angle) << std::endl;
    // std::cout << double(br.angle.Degrees()) << std::endl;

    std::cout << double(br.speed / m_maxSpeedX) * 0.7 << std::endl;

    frc::Rotation2d flCurrentAngle(units::degree_t(m_frontLeft550AbsoluteEncoder.GetPosition()) * 360);
    auto flOptimized = frc::SwerveModuleState::Optimize(fl,
   units::radian_t(m_frontLeft550AbsoluteEncoder.GetPosition()));
    flOptimized.speed *= (flOptimized.angle - flCurrentAngle).Cos();

    m_frontLeft550PID.SetSetpoint(double(flOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontLeft550.Set(m_frontLeft550PID.Calculate(m_frontLeft550AbsoluteEncoder.GetPosition()));
    m_frontLeft.Set(-double(flOptimized.speed / m_maxSpeedX) * 0.7);



    frc::Rotation2d frCurrentAngle(units::degree_t(m_frontRight550AbsoluteEncoder.GetPosition()) * 360);
    auto frOptimized = frc::SwerveModuleState::Optimize(fr,
   units::radian_t(m_frontRight550AbsoluteEncoder.GetPosition()));
    frOptimized.speed *= (frOptimized.angle - frCurrentAngle).Cos();

    m_frontRight550PID.SetSetpoint(double(frOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontRight550.Set(m_frontRight550PID.Calculate(m_frontRight550AbsoluteEncoder.GetPosition()));
    m_frontRight.Set(double(frOptimized.speed / m_maxSpeedX) * 0.7);



    frc::Rotation2d blCurrentAngle(units::degree_t(m_backLeft550AbsoluteEncoder.GetPosition()) * 360);
    auto blOptimized = frc::SwerveModuleState::Optimize(bl,
   units::radian_t(m_backLeft550AbsoluteEncoder.GetPosition()));
    blOptimized.speed *= (blOptimized.angle - blCurrentAngle).Cos();

    m_backLeft550PID.SetSetpoint(double(blOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backLeft550.Set(m_backLeft550PID.Calculate(m_backLeft550AbsoluteEncoder.GetPosition()));
    m_backLeft.Set(-double(blOptimized.speed / m_maxSpeedX) * 0.7);



    frc::Rotation2d brCurrentAngle(units::degree_t(m_backRight550AbsoluteEncoder.GetPosition()) * 360);
    auto brOptimized = frc::SwerveModuleState::Optimize(br,
   units::radian_t(m_backRight550AbsoluteEncoder.GetPosition()));
    brOptimized.speed *= (brOptimized.angle - brCurrentAngle).Cos();

    m_backRight550PID.SetSetpoint(double(brOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backRight550.Set(m_backRight550PID.Calculate(m_backRight550AbsoluteEncoder.GetPosition()));
    m_backRight.Set(-double(brOptimized.speed / m_maxSpeedX) * 0.7);

}



//     // m_frontLeft550PID.SetReference((15), rev::ControlType::kPosition);
//     // m_frontRight550PID.SetReference((15), rev::ControlType::kPosition);
//     // m_backLeft550PID.SetReference((15), rev::ControlType::kPosition);
//     // m_backRight550PID.SetReference((15), rev::ControlType::kPosition);

//     // m_frontLeft550PID.SetSetpoint(0.7);
//     // m_frontLeft550.Set(m_frontLeft550PID.Calculate(m_frontLeft550AbsoluteEncoder.GetPosition()));

//     // m_frontRight550PID.SetSetpoint(0.7);
//     // m_frontRight550.Set(m_frontRight550PID.Calculate(m_frontRight550AbsoluteEncoder.GetPosition()));

//     // m_backLeft550PID.SetSetpoint(0.7);
//     // m_backLeft550.Set(m_backLeft550PID.Calculate(m_backLeft550AbsoluteEncoder.GetPosition()));
//     // std::cout << m_backLeft550AbsoluteEncoder.GetPosition() << std::endl;

//     // m_backRight550PID.SetSetpoint(0.7);
//     // m_backRight550.Set(m_backRight550PID.Calculate(m_backRight550AbsoluteEncoder.GetPosition()));
//     // // std::cout << m_backRight550AbsoluteEncoder.GetPosition() << std::endl;


    
    
    

//     // m_backRight.Set(0.3);
//     // m_backRight550.Set(0.3);

//     // m_backLeft.Set(0.3);
//     // m_backLeft550.Set(0.3);
    
//     // m_frontRight.Set(0.3);
//     //m_frontRight550.Set(0.3);
    
//     // m_frontLeft.Set(0.3);
//     // m_frontLeft550.Set(0.3);
       