// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/config/RobotConfig.h>
#include <pathplanner/lib/controllers/PPHolonomicDriveController.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Translation2d.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/DriverStation.h>
#include <tuple>
#include <array>
#include <vector>
#include <units/velocity.h>
#include <units/angle.h>
#include <wpi/array.h>

#include "Constants.h"
#include "subsystems/SubIMU.h"
#include "subsystems/SwerveModule.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

// Method that drives the robot in field relative drive
  void driveFieldRelative(float iX, float iY, float i0);

// Method that returns a ChassisSpeeds from the robot relative speeds
  frc::ChassisSpeeds getRobotRelativeSpeeds();
// Method that drives the robot in robot relative drive
  void driveRobotRelative(frc::ChassisSpeeds speeds);

// Method that returns the robot's pose
  frc::Pose2d getPose();
// Method that redefines the robot's pose with its input
  void resetPose(frc::Pose2d iRobotPose);

  void Init();

  // Load the RobotConfig from the GUI settings. You should probably
  // store this in your Constants file
  pathplanner::RobotConfig config = pathplanner::RobotConfig::fromGUISettings();

 private:

  // Declaring the locations of the SwerveModules
  frc::Translation2d * m_frontLeftLocation;
  frc::Translation2d * m_frontRightLocation;
  frc::Translation2d * m_backLeftLocation;
  frc::Translation2d * m_backRightLocation;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // Declaring the four SwerveModule objects
  SwerveModule * m_frontLeftModule;
  SwerveModule * m_frontRightModule;
  SwerveModule * m_backLeftModule;
  SwerveModule * m_backRightModule;

  // wpi::array<frc::SwerveModulePosition, 4> * m_swerveModulePositions;

  // Declaring my swerve kinematics object
  frc::SwerveDriveKinematics<4> * m_kinematics;
  // Declaring the robot pose object
  frc::Pose2d * m_robotPose;
  // Declaring the swerve odometry object
  frc::SwerveDriveOdometry<4> * m_odometry;

  // Declaring the IMU object
  SubIMU * mIMU = nullptr;
};
