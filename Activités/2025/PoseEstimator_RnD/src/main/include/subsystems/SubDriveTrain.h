// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/config/RobotConfig.h>
#include <pathplanner/lib/controllers/PPHolonomicDriveController.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/button/CommandJoystick.h>
#include <frc/geometry/Translation2d.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/estimator/SwerveDrivePoseEstimator.h>
#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/Timer.h>
#include <units/math.h>


#include "Constants.h"
#include "subsystems/SubIMU.h"
#include "subsystems/SwerveModule.h"
#include "LimelightHelpers.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain(SubIMU * iIMU, frc2::CommandJoystick * iCommandJoystick);

  enum StartPoses{
    RougeGauche,
    RougeCentre,
    RougeDroite,
    BleuGauche,
    BleuCentre,
    BleuDroite,
    Test
  };
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

// Method that drives the robot in field relative drive
  void driveFieldRelative(float iX, float iY, float i0, double SpeedModulation);

// Method that returns a ChassisSpeeds from the robot relative speeds
  frc::ChassisSpeeds getRobotRelativeSpeeds();
// Method that drives the robot in robot relative drive
  void driveRobotRelative(frc::ChassisSpeeds speeds, double SpeedModulation);

// Method that returns the robot's pose
  frc::Pose2d getPose();
// Method that redefines the robot's pose with its input
  void resetPose(frc::Pose2d iRobotPose);

// Method that gets set as the Subsystem's default command 
  void DefaultCommand();

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
  frc::Pose2d * m_startingRobotPose;
  // Declaring the swerve odometry object
  frc::SwerveDriveOdometry<4> * m_odometry;

  frc::SwerveDrivePoseEstimator<4> * m_poseEstimator;

  wpi::array<double, 3> * visionMeasurementStdDevs;
  wpi::array<double, 3> * stateStdDevs;

  // Declaring the IMU object
  SubIMU * mIMU = nullptr;

  // Declaring the CommandJoystick object
  frc2::CommandJoystick * m_commandJoystick;

  frc::Pose2d CoordonneesInit;
  StartPoses StartPose = RougeCentre;

  LimelightHelpers::PoseEstimate mt2;
};
