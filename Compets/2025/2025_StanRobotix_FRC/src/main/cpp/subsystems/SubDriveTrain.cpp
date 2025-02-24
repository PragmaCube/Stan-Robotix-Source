// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    m_backLeft.SetInverted(true);
    m_frontRight550PID.EnableContinuousInput(0, 1);
    m_frontLeft550PID.EnableContinuousInput(0, 1);
    m_backLeft550PID.EnableContinuousInput(0, 1);
    m_backRight550PID.EnableContinuousInput(0, 1);
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() 
{
    frc::Rotation2d gyroAngle = mIMU.getRotation2d();

    m_robotPose = m_odometry.Update(gyroAngle, m_swerveModulePositions);
}

void SubDriveTrain::Init() {}

// Pour obtenir la position des modules b
// on multiple l'encodeur du drive motor par
// le gear ratio, le perimetre des roues puis on le converti on metres

void SubDriveTrain::Drive(float iX, float iY, float i0)
{
    frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(m_maxSpeed * iY, m_maxSpeed * iX, m_maxSpeed0 * i0, mIMU.getRotation2d().Degrees());

    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);

    frc::Rotation2d flCurrentAngle(units::degree_t(m_frontLeft550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto flOptimized = frc::SwerveModuleState::Optimize(fl, flCurrentAngle);
    flOptimized.speed *= (flOptimized.angle - flCurrentAngle).Cos();

    m_frontLeft550PID.SetSetpoint(double(flOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontLeft550.Set(m_frontLeft550PID.Calculate(m_frontLeft550AbsoluteEncoder.GetPosition()));
    m_frontLeft.Set(double(flOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);



    frc::Rotation2d frCurrentAngle(units::degree_t(m_frontRight550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto frOptimized = frc::SwerveModuleState::Optimize(fr, frCurrentAngle);
    frOptimized.speed *= (frOptimized.angle - frCurrentAngle).Cos();

    m_frontRight550PID.SetSetpoint(double(frOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontRight550.Set(m_frontRight550PID.Calculate(m_frontRight550AbsoluteEncoder.GetPosition()));
    m_frontRight.Set(double(frOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);



    frc::Rotation2d blCurrentAngle(units::degree_t(m_backLeft550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto blOptimized = frc::SwerveModuleState::Optimize(bl, blCurrentAngle);
    blOptimized.speed *= (blOptimized.angle - blCurrentAngle).Cos();

    m_backLeft550PID.SetSetpoint(double(blOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backLeft550.Set(m_backLeft550PID.Calculate(m_backLeft550AbsoluteEncoder.GetPosition()));
    m_backLeft.Set(double(blOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);



    frc::Rotation2d brCurrentAngle(units::degree_t(m_backRight550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto brOptimized = frc::SwerveModuleState::Optimize(br, brCurrentAngle);
    brOptimized.speed *= (brOptimized.angle - brCurrentAngle).Cos();

    m_backRight550PID.SetSetpoint(double(brOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backRight550.Set(m_backRight550PID.Calculate(m_backRight550AbsoluteEncoder.GetPosition()));
    m_backRight.Set(double(brOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);
}

frc::Pose2d SubDriveTrain::getPose()
{
    return m_robotPose;
}

void SubDriveTrain::resetPose(frc::Pose2d iRobotPose)
{
    m_robotPose = iRobotPose;
}

frc::ChassisSpeeds SubDriveTrain::getRobotRelativeSpeeds()
{
    frc::SwerveModuleState  frontLeftState{units::meters_per_second_t(m_frontLeft550Encoder.GetVelocity()) , frc::Rotation2d(units::degree_t(m_frontLeft550AbsoluteEncoder.GetPosition()  * 360))};
    frc::SwerveModuleState frontRightState{units::meters_per_second_t(m_frontRight550Encoder.GetVelocity()), frc::Rotation2d(units::degree_t(m_frontRight550AbsoluteEncoder.GetPosition() * 360))};
    frc::SwerveModuleState   backLeftState{units::meters_per_second_t(m_backLeft550Encoder.GetVelocity())  , frc::Rotation2d(units::degree_t(m_backLeft550AbsoluteEncoder.GetPosition()   * 360))};
    frc::SwerveModuleState  backRightState{units::meters_per_second_t(m_backRight550Encoder.GetVelocity()) , frc::Rotation2d(units::degree_t(m_backRight550AbsoluteEncoder.GetPosition()  * 360))};
    
    auto [forward, sideways, angular] = m_kinematics.ToChassisSpeeds(frontLeftState, frontRightState, backLeftState, backRightState);
    frc::ChassisSpeeds robotRelativeSpeeds = frc::ChassisSpeeds::FromRobotRelativeSpeeds(forward,sideways,angular,mIMU.getRotation2d());
    return robotRelativeSpeeds;

}

void SubDriveTrain::driveRobotRelative(frc::ChassisSpeeds speeds)
{
    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);

    frc::Rotation2d flCurrentAngle(units::degree_t(m_frontLeft550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto flOptimized = frc::SwerveModuleState::Optimize(fl, flCurrentAngle);
    flOptimized.speed *= (flOptimized.angle - flCurrentAngle).Cos();

    m_frontLeft550PID.SetSetpoint(double(flOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontLeft550.Set(m_frontLeft550PID.Calculate(m_frontLeft550AbsoluteEncoder.GetPosition()));
    m_frontLeft.Set(double(flOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);



    frc::Rotation2d frCurrentAngle(units::degree_t(m_frontRight550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto frOptimized = frc::SwerveModuleState::Optimize(fr, frCurrentAngle);
    frOptimized.speed *= (frOptimized.angle - frCurrentAngle).Cos();

    m_frontRight550PID.SetSetpoint(double(frOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_frontRight550.Set(m_frontRight550PID.Calculate(m_frontRight550AbsoluteEncoder.GetPosition()));
    m_frontRight.Set(double(frOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);



    frc::Rotation2d blCurrentAngle(units::degree_t(m_backLeft550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto blOptimized = frc::SwerveModuleState::Optimize(bl, blCurrentAngle);
    blOptimized.speed *= (blOptimized.angle - blCurrentAngle).Cos();

    m_backLeft550PID.SetSetpoint(double(blOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backLeft550.Set(m_backLeft550PID.Calculate(m_backLeft550AbsoluteEncoder.GetPosition()));
    m_backLeft.Set(double(blOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);



    frc::Rotation2d brCurrentAngle(units::degree_t(m_backRight550AbsoluteEncoder.GetPosition() - 0.5) * 360);
    auto brOptimized = frc::SwerveModuleState::Optimize(br, brCurrentAngle);
    brOptimized.speed *= (brOptimized.angle - brCurrentAngle).Cos();

    m_backRight550PID.SetSetpoint(double(brOptimized.angle.Radians() / (2*std::numbers::pi)) + 0.5);
    m_backRight550.Set(m_backRight550PID.Calculate(m_backRight550AbsoluteEncoder.GetPosition()));
    m_backRight.Set(double(brOptimized.speed / m_maxSpeed) * DriveTrainConstants::speedCap);
}