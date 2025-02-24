// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/*#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/config/RobotConfig.h>
#include <pathplanner/lib/controllers/PPHolonomicDriveController.h>*/
#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Translation2d.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/DriverStation.h>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <rev/AbsoluteEncoder.h>
#include <tuple>
#include <array>
#include <vector>
#include <frc/controller/PIDController.h>
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

  void Drive(float iX, float iY, float i0);

  void driveRobotRelative(frc::ChassisSpeeds speeds);

  frc::ChassisSpeeds getRobotRelativeSpeeds();

  frc::Pose2d getPose();
  void resetPose(frc::Pose2d iRobotPose);

  void Init();

  // Load the RobotConfig from the GUI settings. You should probably
  // store this in your Constants file
  // pathplanner::RobotConfig config = pathplanner::RobotConfig::fromGUISettings();

  // Configure the AutoBuilder last

 private:

  // Locations for the swerve drive modules relative to the robot center.
  frc::Translation2d m_frontLeftLocation{0.355_m, 0.355_m};
  frc::Translation2d m_frontRightLocation{0.355_m, -0.355_m};
  frc::Translation2d m_backLeftLocation{-0.355_m, 0.355_m};
  frc::Translation2d m_backRightLocation{-0.355_m, -0.355_m};

  // Creating my kinematics object using the module locations.
  frc::SwerveDriveKinematics<4> m_kinematics{
    m_frontLeftLocation, m_frontRightLocation, m_backLeftLocation,
    m_backRightLocation};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  SwerveModule * m_frontLeftModule;
  SwerveModule * m_frontRightModule;
  SwerveModule * m_backLeftModule;
  SwerveModule * m_backRightModule;

  units::meters_per_second_t m_maxSpeed = 1_mps;
  units::radians_per_second_t m_maxSpeed0 = units::radians_per_second_t(std::numbers::pi);
  frc::Pose2d * m_robotPose;
  float m_gearRatio = 5.08;
  double m_wheelPerimeter = 3 * 0.0254 * std::numbers::pi;

  wpi::array<frc::SwerveModulePosition, 4> * m_swerveModulePositions;

  frc::SwerveDriveOdometry<4> * m_odometry;

  SubIMU * mIMU = nullptr;
};
