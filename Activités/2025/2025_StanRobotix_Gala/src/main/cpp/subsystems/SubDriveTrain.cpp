// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain(SubIMU *iIMU, int iStartingPose)
{

    // Initialization of the SwerveModules' location relative to the robot center
    m_frontLeftLocation = new frc::Translation2d{0.3683_m, 0.3556_m};
    m_frontRightLocation = new frc::Translation2d{0.3683_m, -0.3556_m};
    m_backLeftLocation = new frc::Translation2d{-0.3683_m, 0.3556_m};
    m_backRightLocation = new frc::Translation2d{-0.3683_m, -0.3556_m};

    // Initialization of the SwerveModules with the motor IDs
    m_frontLeftModule = new SwerveModule{DriveTrainConstants::kFrontLeftMotorID, DriveTrainConstants::kFrontLeftMotor550ID};
    m_frontRightModule = new SwerveModule{DriveTrainConstants::kFrontRightMotorID, DriveTrainConstants::kFrontRightMotor550ID};
    m_backLeftModule = new SwerveModule{DriveTrainConstants::kBackLeftMotorID, DriveTrainConstants::kBackLeftMotor550ID};
    m_backRightModule = new SwerveModule{DriveTrainConstants::kBackRightMotorID, DriveTrainConstants::kBackRightMotor550ID};

    m_frontLeftModule->SetNeoInverted(true);

    // Initialization of the IMU
    mIMU = iIMU;

    // Initialization of the swerve kinematics with the SwerveModules' location
    m_kinematics = new frc::SwerveDriveKinematics<4>{*m_frontLeftLocation, *m_frontRightLocation, *m_backLeftLocation, *m_backRightLocation};
    // Initialization of the robot's pose
    switch (iStartingPose)
    {
    case RedLeft:
        m_robotPose = new frc::Pose2d{units::meter_t(9.972), units::meter_t(0.769), mIMU->getRotation2d() + frc::Rotation2d(units::degree_t(180))};
        break;
    case RedCenter:
        m_robotPose = new frc::Pose2d{units::meter_t(9.972), units::meter_t(4.030), mIMU->getRotation2d() + frc::Rotation2d(units::degree_t(180))};
        break;
    case RedRight:
        m_robotPose = new frc::Pose2d{units::meter_t(9.972), units::meter_t(7.3), mIMU->getRotation2d() + frc::Rotation2d(units::degree_t(180))};
        break;
    case BlueLeft:
        m_robotPose = new frc::Pose2d{units::meter_t(8), units::meter_t(7.261), mIMU->getRotation2d()};
        break;
    case BlueCenter:
        m_robotPose = new frc::Pose2d{units::meter_t(8), units::meter_t(4.010), mIMU->getRotation2d()};
        break;
    case BlueRight:
        m_robotPose = new frc::Pose2d{units::meter_t(7.58), units::meter_t(0.774), mIMU->getRotation2d()};
        break;
    case Test:
        m_robotPose = new frc::Pose2d{units::meter_t(7), units::meter_t(4), mIMU->getRotation2d()};
        break;
    }
    // Initialization of the swerve odometry with the kinematics, the robot's rotation, an array of the SwerveModules' position, and the robot's pose
    m_odometry = new frc::SwerveDriveOdometry<4>{*m_kinematics, mIMU->getRotation2d(), {m_frontLeftModule->GetModulePosition(), m_frontRightModule->GetModulePosition(), m_backLeftModule->GetModulePosition(), m_backRightModule->GetModulePosition()}, *m_robotPose};

}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic()
{
    // Refreshing the SwerveModules' position and states
    m_frontLeftModule->RefreshModule();
    m_frontRightModule->RefreshModule();
    m_backLeftModule->RefreshModule();
    m_backRightModule->RefreshModule();

    // Update of the robot's pose with the robot's rotation and an array of the SwerveModules' position
    frc::Rotation2d gyroAngle = mIMU->getRotation2d();
    *m_robotPose = m_odometry->Update(gyroAngle, {m_frontLeftModule->GetModulePosition(),
                                                  m_frontRightModule->GetModulePosition(),
                                                  m_backLeftModule->GetModulePosition(),
                                                  m_backRightModule->GetModulePosition()});
}

void SubDriveTrain::driveFieldRelative(float iX, float iY, float i0, double SpeedModulation)
{
    // Creating a ChassisSpeeds from the wanted speeds and the robot's rotation
    frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iY,
                                                                            units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iX,
                                                                            units::radians_per_second_t(DriveTrainConstants::kMaxSpeed0) * i0,
                                                                            mIMU->getRotation2d());

    // Transforming the ChassisSpeeds into four SwerveModuleState for each SwerveModule
    auto [fl, fr, bl, br] = m_kinematics->ToSwerveModuleStates(speeds);

    // Setting the desired state of each SwerveModule to the corresponding SwerveModuleState
    m_frontLeftModule->SetDesiredState(fl, SpeedModulation);
    m_frontRightModule->SetDesiredState(fr, SpeedModulation);
    m_backLeftModule->SetDesiredState(bl, SpeedModulation);
    m_backRightModule->SetDesiredState(br, SpeedModulation);
}

frc::Pose2d SubDriveTrain::getPose()
{
    return *m_robotPose;
}

void SubDriveTrain::resetPose(frc::Pose2d iRobotPose)
{
    *m_robotPose = iRobotPose;
}

frc::ChassisSpeeds SubDriveTrain::getRobotRelativeSpeeds()
{
    // Creating directionnal speeds from the SwerveModules' state
    auto [forward, sideways, angular] = m_kinematics->ToChassisSpeeds(wpi::array<frc::SwerveModuleState, 4>{m_frontLeftModule->GetModuleState(),
                                                                                                            m_frontRightModule->GetModuleState(),
                                                                                                            m_backLeftModule->GetModuleState(),
                                                                                                            m_backRightModule->GetModuleState()});
    // Creating a ChassisSpeeds from these speeds and the robot's rotation and returning it
    frc::ChassisSpeeds robotRelativeSpeeds = frc::ChassisSpeeds::FromRobotRelativeSpeeds(forward, sideways, angular, mIMU->getRotation2d());
    return robotRelativeSpeeds;
}

void SubDriveTrain::driveRobotRelative(frc::ChassisSpeeds speeds, double SpeedModulation)
{
    // Tansforming the ChassisSpeeds into four SwerveModuleState for each SwerveModule
    auto [fl, fr, bl, br] = m_kinematics->ToSwerveModuleStates(speeds);

    // Setting the desired state of each SwerveModule to the corresponding SwerveModuleState
    m_frontLeftModule->SetDesiredState(fl, SpeedModulation);
    m_frontRightModule->SetDesiredState(fr, SpeedModulation);
    m_backLeftModule->SetDesiredState(bl, SpeedModulation);
    m_backRightModule->SetDesiredState(br, SpeedModulation);
}

void SubDriveTrain::driveRobotRelativeFromJoystick(float iX, float iY, float i0, double SpeedModulation)
{
    // Creating a ChassisSpeeds from the wanted speeds and the robot's rotation
    frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromRobotRelativeSpeeds(units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iY,
                                                                            units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iX,
                                                                            units::radians_per_second_t(DriveTrainConstants::kMaxSpeed0) * i0,
                                                                            mIMU->getRotation2d());

    // Transforming the ChassisSpeeds into four SwerveModuleState for each SwerveModule
    auto [fl, fr, bl, br] = m_kinematics->ToSwerveModuleStates(speeds);

    // Setting the desired state of each SwerveModule to the corresponding SwerveModuleState
    m_frontLeftModule->SetDesiredState(fl, SpeedModulation);
    m_frontRightModule->SetDesiredState(fr, SpeedModulation);
    m_backLeftModule->SetDesiredState(bl, SpeedModulation);
    m_backRightModule->SetDesiredState(br, SpeedModulation);
}