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
#include <wpi/array.h>

#include "Constants.h"
#include "subsystems/SubIMU.h"

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


  rev::spark::SparkMax m_frontLeft{DriveTrainConstants::kFrontLeftMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax m_frontLeft550{DriveTrainConstants::kFrontLeftMotor550ID, rev::spark::SparkLowLevel::MotorType::kBrushless};

  rev::spark::SparkRelativeEncoder m_frontLeftEncoder = m_frontLeft.GetEncoder();
  rev::spark::SparkRelativeEncoder m_frontLeft550Encoder = m_frontLeft550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_frontLeft550AbsoluteEncoder = m_frontLeft550.GetAbsoluteEncoder();
  frc::PIDController m_frontLeft550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};


  rev::spark::SparkMax m_frontRight{DriveTrainConstants::kFrontRighttMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax m_frontRight550{DriveTrainConstants::kFrontRightMotor550ID, rev::spark::SparkLowLevel::MotorType::kBrushless};

  rev::spark::SparkRelativeEncoder m_frontRightEncoder = m_frontRight.GetEncoder();
  rev::spark::SparkRelativeEncoder m_frontRight550Encoder = m_frontRight550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_frontRight550AbsoluteEncoder = m_frontRight550.GetAbsoluteEncoder();
  frc::PIDController m_frontRight550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};


  rev::spark::SparkMax m_backLeft{DriveTrainConstants::kBackLeftMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax m_backLeft550{DriveTrainConstants::kBackLefttMotor550ID, rev::spark::SparkLowLevel::MotorType::kBrushless};

  rev::spark::SparkRelativeEncoder m_backLeftEncoder = m_backLeft.GetEncoder();
  rev::spark::SparkRelativeEncoder m_backLeft550Encoder = m_backLeft550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_backLeft550AbsoluteEncoder = m_backLeft550.GetAbsoluteEncoder();
  frc::PIDController m_backLeft550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};


  rev::spark::SparkMax m_backRight{DriveTrainConstants::kBackRightMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax m_backRight550{DriveTrainConstants::kBackRightMotor550ID, rev::spark::SparkLowLevel::MotorType::kBrushless};

  rev::spark::SparkRelativeEncoder m_backRightEncoder = m_backRight.GetEncoder();
  rev::spark::SparkRelativeEncoder m_backRight550Encoder = m_backRight550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_backRight550AbsoluteEncoder = m_backRight550.GetAbsoluteEncoder();
  frc::PIDController m_backRight550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};
  
  

  units::meters_per_second_t m_maxSpeed = 1_mps;
  units::radians_per_second_t m_maxSpeed0 = units::radians_per_second_t(std::numbers::pi);
  frc::Pose2d m_robotPose = frc::Pose2d(units::meter_t(0),units::meter_t(0),mIMU.getRotation2d());
  float m_gearRatio = 5.08;
  double m_wheelPerimeter = 3 * 0.0254 * std::numbers::pi;

    
  wpi::array<frc::SwerveModulePosition, 4> m_swerveModulePositions = {
      frc::SwerveModulePosition({units::meter_t(m_frontLeftEncoder.GetPosition()*m_gearRatio*m_wheelPerimeter)  ,  (units::radian_t(m_backRight550AbsoluteEncoder.GetPosition() - 0.5) * std::numbers::pi)}), 
      frc::SwerveModulePosition({units::meter_t(m_frontRightEncoder.GetPosition()*m_gearRatio*m_wheelPerimeter) , (units::radian_t(m_frontRight550AbsoluteEncoder.GetPosition() - 0.5) * std::numbers::pi)}), 
      frc::SwerveModulePosition({units::meter_t(m_backLeftEncoder.GetPosition()*m_gearRatio*m_wheelPerimeter)   ,   (units::radian_t(m_backLeft550AbsoluteEncoder.GetPosition() - 0.5) * std::numbers::pi)}), 
      frc::SwerveModulePosition({units::meter_t(m_backRightEncoder.GetPosition()*m_gearRatio*m_wheelPerimeter)  ,  (units::radian_t(m_backRight550AbsoluteEncoder.GetPosition() - 0.5) * std::numbers::pi)})};

  //frc::SwerveDriveOdometry<4> m_odometry{m_kinematics, mIMU.getRotation2d(), m_swerveModulePositions};

  SubIMU mIMU;
};
