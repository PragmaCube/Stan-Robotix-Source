// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    m_backLeftModule->setNeoInverted(true);
    m_frontLeftModule = new SwerveModule{DriveTrainConstants::kFrontLeftMotorID,DriveTrainConstants::kFrontLeftMotor550ID};
    m_frontRightModule = new SwerveModule{DriveTrainConstants::kFrontRightMotorID, DriveTrainConstants::kFrontRightMotor550ID};
    m_backLeftModule = new SwerveModule{DriveTrainConstants::kBackLeftMotorID, DriveTrainConstants::kBackLeftMotor550ID};
    m_backRightModule = new SwerveModule{DriveTrainConstants::kBackRightMotorID, DriveTrainConstants::kBackRightMotor550ID};
    // m_robotPose = new frc::Pose2d(units::meter_t(0),units::meter_t(0),mIMU.getRotation2d());
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() 
{
    // frc::Rotation2d gyroAngle = mIMU.getRotation2d();

    // *m_robotPose = m_odometry.Update(gyroAngle, m_swerveModulePositions);
}

void SubDriveTrain::Init()
{
    /*pathplanner::AutoBuilder::configure(
    [this](){ return getPose(); }, // Robot pose supplier
    [this](frc::Pose2d pose){ resetPose(pose); }, // Method to reset odometry (will be called if your auto has a starting pose)
    [this](){ return getRobotRelativeSpeeds(); }, // ChassisSpeeds supplier. MUST BE ROBOT RELATIVE
    [this](auto speeds, auto feedforwards){ driveRobotRelative(speeds); }, // Method that will drive the robot given ROBOT RELATIVE ChassisSpeeds. Also optionally outputs individual module feedforwards
    std::make_shared<pathplanner::PPHolonomicDriveController>( // PPHolonomicController is the built in path following controller for holonomic drive trains
        pathplanner::PIDConstants(PathPlannerConstants::kPTranslation, PathPlannerConstants::kITranslation, PathPlannerConstants::kDTranslation), // Translation PID constants
        pathplanner::PIDConstants(PathPlannerConstants::kPRotation, PathPlannerConstants::kIRotation, PathPlannerConstants::kDRotation) // Rotation PID constants
    ),
    config, // The robot configuration
    []() {
        // Boolean supplier that controls when the path will be mirrored for the red alliance
        // This will flip the path being followed to the red side of the field.
        // THE ORIGIN WILL REMAIN ON THE BLUE SIDE

        auto alliance = frc::DriverStation::GetAlliance();
        if (alliance) {
            return alliance.value() == frc::DriverStation::Alliance::kRed;
        }
        return false;
    },
    this // Reference to this subsystem to set requirements
  );*/
}

void SubDriveTrain::Drive(float iX, float iY, float i0)
{
    frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(m_maxSpeed * iY, m_maxSpeed * iX, m_maxSpeed0 * i0, mIMU.getRotation2d().Degrees());

    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);

    m_frontLeftModule->setDesiredState(&fl);
    m_frontRightModule->setDesiredState(&fr);
    m_backLeftModule->setDesiredState(&bl);
    m_backRightModule->setDesiredState(&br);
}

frc::Pose2d SubDriveTrain::getPose()
{
    // return *m_robotPose;
}

void SubDriveTrain::resetPose(frc::Pose2d iRobotPose)
{
    // *m_robotPose = iRobotPose;
}

frc::ChassisSpeeds SubDriveTrain::getRobotRelativeSpeeds()
{
    auto [forward, sideways, angular] = m_kinematics.ToChassisSpeeds(wpi::array<frc::SwerveModuleState, 4> (m_frontLeftModule->getModuleState(),
                                                                                                            m_frontRightModule->getModuleState(),
                                                                                                            m_backLeftModule->getModuleState(),
                                                                                                            m_backRightModule->getModuleState()));
    frc::ChassisSpeeds robotRelativeSpeeds = frc::ChassisSpeeds::FromRobotRelativeSpeeds(forward,sideways,angular,mIMU.getRotation2d());
    return robotRelativeSpeeds;
}

void SubDriveTrain::driveRobotRelative(frc::ChassisSpeeds speeds)
{
    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);

    m_frontLeftModule->setDesiredState(&fl);
    m_frontRightModule->setDesiredState(&fr);
    m_backLeftModule->setDesiredState(&bl);
    m_backRightModule->setDesiredState(&br);
}