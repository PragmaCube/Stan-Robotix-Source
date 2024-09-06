// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Translation2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxRelativeEncoder.h>
#include <tuple>
#include <array>
#include <vector>

class Swerve : public frc2::SubsystemBase {
 public:
  Swerve();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Move(float iX, float iY, float i0); 
  void Move(float iX, float iY, float i0, float angle);

  void Init();

 private:

  // Locations for the swerve drive modules relative to the robot center.
  frc::Translation2d m_frontLeftLocation{0.125_m, 0.125_m};
  frc::Translation2d m_frontRightLocation{0.125_m, -0.125_m};
  frc::Translation2d m_backLeftLocation{-0.125_m, 0.125_m};
  frc::Translation2d m_backRightLocation{-0.125_m, -0.125_m};

  // Creating my kinematics object using the module locations.
  frc::SwerveDriveKinematics<4> m_kinematics{
    m_frontLeftLocation, m_frontRightLocation, m_backLeftLocation,
    m_backRightLocation};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.


  rev::CANSparkMax m_frontLeft{1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_frontLeft550{2, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder m_frontLeft550Encoder = m_frontLeft550.GetEncoder();
  rev::SparkMaxPIDController m_frontLeft550PID = m_frontLeft550.GetPIDController();

  rev::CANSparkMax m_frontRight{3, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_frontRight550{4, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder m_frontRight550Encoder = m_frontRight550.GetEncoder();
  rev::SparkMaxPIDController m_frontRight550PID = m_frontRight550.GetPIDController();

  rev::CANSparkMax m_backLeft{5, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_backLeft550{6, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder m_backLeft550Encoder = m_backLeft550.GetEncoder();
  rev::SparkMaxPIDController m_backLeft550PID = m_backLeft550.GetPIDController();

  rev::CANSparkMax m_backRight{7, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_backRight550{8, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder m_backRight550Encoder = m_backRight550.GetEncoder();
  rev::SparkMaxPIDController m_backRight550PID = m_backRight550.GetPIDController();
  
  

  units::meters_per_second_t m_maxSpeedX = 1_mps;
  units::meters_per_second_t m_maxSpeedY = 1_mps;
  units::radians_per_second_t m_maxSpeed0 = units::radians_per_second_t(2 * std::numbers::pi);

};
