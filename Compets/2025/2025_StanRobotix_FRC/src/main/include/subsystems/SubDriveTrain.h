// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Translation2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <rev/AbsoluteEncoder.h>
#include <tuple>
#include <array>
#include <vector>
#include <frc/controller/PIDController.h>
#include <subsystems/SubIMU.h>

#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Drive(float iX, float iY, float i0); 
  void Drive(float iX, float iY, float i0, float angle);

  void Init();

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

  rev::spark::SparkRelativeEncoder m_frontLeft550Encoder = m_frontLeft550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_frontLeft550AbsoluteEncoder = m_frontLeft550.GetAbsoluteEncoder();
  frc::PIDController m_frontLeft550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};


  rev::spark::SparkMax m_frontRight{DriveTrainConstants::kFrontRighttMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax m_frontRight550{DriveTrainConstants::kFrontRightMotor550ID, rev::spark::SparkLowLevel::MotorType::kBrushless};

  rev::spark::SparkRelativeEncoder m_frontRight550Encoder = m_frontRight550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_frontRight550AbsoluteEncoder = m_frontRight550.GetAbsoluteEncoder();
  frc::PIDController m_frontRight550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};


  rev::spark::SparkMax m_backLeft{DriveTrainConstants::kBackLeftMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax m_backLeft550{DriveTrainConstants::kBackLefttMotor550ID, rev::spark::SparkLowLevel::MotorType::kBrushless};

  rev::spark::SparkRelativeEncoder m_backLeft550Encoder = m_backLeft550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_backLeft550AbsoluteEncoder = m_backLeft550.GetAbsoluteEncoder();
  frc::PIDController m_backLeft550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};


  rev::spark::SparkMax m_backRight{DriveTrainConstants::kBackRightMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkMax m_backRight550{DriveTrainConstants::kBackRightMotor550ID, rev::spark::SparkLowLevel::MotorType::kBrushless};

  rev::spark::SparkRelativeEncoder m_backRight550Encoder = m_backRight550.GetEncoder();
  rev::spark::SparkAbsoluteEncoder  m_backRight550AbsoluteEncoder = m_backRight550.GetAbsoluteEncoder();
  frc::PIDController m_backRight550PID {DriveTrainConstants::PIDs::kP , DriveTrainConstants::PIDs::kI , DriveTrainConstants::PIDs::kD};
  
  

  units::meters_per_second_t m_maxSpeed = 1_mps;
  units::radians_per_second_t m_maxSpeed0 = units::radians_per_second_t(std::numbers::pi);



  SubIMU mIMU;
};
