// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    // Initialization of the SwerveModules' location relative to the robot center
    m_frontLeftLocation = new frc::Translation2d{0.3683_m, 0.3556_m};
    m_frontRightLocation = new frc::Translation2d{0.3683_m, -0.3556_m};
    m_backLeftLocation = new frc::Translation2d{-0.3683_m, 0.3556_m};
    m_backRightLocation = new frc::Translation2d{-0.3683_m, -0.3556_m};

    // Initialization of the SwerveModules with the motor IDs
    m_frontLeftModule = new SwerveModule{DriveTrainConstants::kFrontLeftMotorID,DriveTrainConstants::kFrontLeftMotor550ID};
    m_frontRightModule = new SwerveModule{DriveTrainConstants::kFrontRightMotorID, DriveTrainConstants::kFrontRightMotor550ID};
    m_backLeftModule = new SwerveModule{DriveTrainConstants::kBackLeftMotorID, DriveTrainConstants::kBackLeftMotor550ID};
    m_backRightModule = new SwerveModule{DriveTrainConstants::kBackRightMotorID, DriveTrainConstants::kBackRightMotor550ID};

    // Initialization of the IMU
    mIMU = new SubIMU;

    // Initialization of the swerve kinematics with the SwerveModules' location
    m_kinematics = new frc::SwerveDriveKinematics<4>{*m_frontLeftLocation, *m_frontRightLocation, *m_backLeftLocation, *m_backRightLocation};
    // Initialization of the robot's pose
    m_robotPose = new frc::Pose2d{units::meter_t(PathPlannerConstants::kStartingPoseX), units::meter_t(PathPlannerConstants::kStartingPoseY), mIMU->getRotation2d()};
    // Initialization of the swerve odometry with the kinematics, the robot's rotation, an array of the SwerveModules' position, and the robot's pose
    m_odometry = new frc::SwerveDriveOdometry<4>{*m_kinematics, mIMU->getRotation2d(), {
                    m_frontLeftModule->getModulePosition(),
                    m_frontRightModule->getModulePosition(),
                    m_backLeftModule->getModulePosition(),
                    m_backRightModule->getModulePosition()}, *m_robotPose};

    pathplanner::AutoBuilder::configure(
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
    );
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic()
{
    // Refreshing the SwerveModules' position and states
    m_frontLeftModule->refreshModule();
    m_frontRightModule->refreshModule();
    m_backLeftModule->refreshModule();
    m_backRightModule->refreshModule();

    // Update of the robot's pose with the robot's rotation and an array of the SwerveModules' position
    frc::Rotation2d gyroAngle = mIMU->getRotation2d();
    *m_robotPose = m_odometry->Update(gyroAngle, {
                    m_frontLeftModule->getModulePosition(),
                    m_frontRightModule->getModulePosition(),
                    m_backLeftModule->getModulePosition(),
                    m_backRightModule->getModulePosition()});
    
   std::cout << double(m_odometry->GetPose().X()) << std::endl << double(m_odometry->GetPose().Y()) << std::endl;
}
   
void SubDriveTrain::Init() {}

void SubDriveTrain::driveFieldRelative(float iX, float iY, float i0)
{
    // Creating a ChassisSpeeds from the wanted speeds and the robot's rotation
    frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iY,
                                                                            units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iX,
                                                                            units::radians_per_second_t(DriveTrainConstants::kMaxSpeed0) * i0,
                                                                            mIMU->getRotation2d());

    // Transforming the ChassisSpeeds into four SwerveModuleState for each SwerveModule
    auto [fl, fr, bl, br] = m_kinematics->ToSwerveModuleStates(speeds);

    // Setting the desired state of each SwerveModule to the corresponding SwerveModuleState
    m_frontLeftModule->setDesiredState(fl);
    m_frontRightModule->setDesiredState(fr);
    m_backLeftModule->setDesiredState(bl);
    m_backRightModule->setDesiredState(br);
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
    auto [forward, sideways, angular] = m_kinematics->ToChassisSpeeds(wpi::array<frc::SwerveModuleState, 4>{m_frontLeftModule->getModuleState(),
                                                                                                            m_frontRightModule->getModuleState(),
                                                                                                            m_backLeftModule->getModuleState(),
                                                                                                            m_backRightModule->getModuleState()});
    // Creating a ChassisSpeeds from these speeds and the robot's rotation and returning it
    frc::ChassisSpeeds robotRelativeSpeeds = frc::ChassisSpeeds::FromRobotRelativeSpeeds(forward,sideways,angular,mIMU->getRotation2d());
    return robotRelativeSpeeds;

}

void SubDriveTrain::driveRobotRelative(frc::ChassisSpeeds speeds)
{
    // Tansforming the ChassisSpeeds into four SwerveModuleState for each SwerveModule
    auto [fl, fr, bl, br] = m_kinematics->ToSwerveModuleStates(speeds);

    // Setting the desired state of each SwerveModule to the corresponding SwerveModuleState
    m_frontLeftModule->setDesiredState(fl);
    m_frontRightModule->setDesiredState(fr);
    m_backLeftModule->setDesiredState(bl);
    m_backRightModule->setDesiredState(br);
}