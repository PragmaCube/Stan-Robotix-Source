// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Swerve.h"

Swerve::Swerve() = default;

// This method will be called once per scheduler run
void Swerve::Periodic() {}

void Swerve::Init()
{
    
}

void Swerve::Move(float iX, float iY, float i0)
{
    // frc::ChassisSpeeds speeds{m_maxSpeedX * iX, m_maxSpeedY * iY, m_maxSpeed0 * i0};

    // auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);

    // m_frontLeft550PID.SetReference(double(fl.angle.Radians() / (2*std::numbers::pi)), rev::ControlType::kPosition);
    // m_frontRight550PID.SetReference(double(fr.angle.Radians() / (2*std::numbers::pi)), rev::ControlType::kPosition);
    // m_backLeft550PID.SetReference(double(bl.angle.Radians() / (2*std::numbers::pi)), rev::ControlType::kPosition);
    // m_backRight550PID.SetReference(double(br.angle.Radians() / (2*std::numbers::pi)), rev::ControlType::kPosition);


    // m_frontLeft.Set(double(fl.speed / m_maxSpeedX) * 0.7);
    // m_frontRight.Set(double(fr.speed / m_maxSpeedX) * 0.7);
    // m_backLeft.Set(double(bl.speed / m_maxSpeedX) * 0.7);
    // m_backRight.Set(double(br.speed / m_maxSpeedX) * 0.7);

    m_backRight.Set(0.7);
}


