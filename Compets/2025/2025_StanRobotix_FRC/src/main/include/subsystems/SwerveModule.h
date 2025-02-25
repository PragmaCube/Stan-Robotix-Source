// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <rev/SparkMax.h>
#include <rev/RelativeEncoder.h>
#include <rev/AbsoluteEncoder.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/controller/PIDController.h>
#include <units/velocity.h>
#include <units/angle.h>

#include "Constants.h"

class SwerveModule{
 public:
  SwerveModule();
  SwerveModule(int iNeoMotorID, int iNeo550MotorID);

  frc::SwerveModulePosition getModulePosition();

  frc::SwerveModuleState getModuleState();

  frc::SwerveModuleState OptimizeState(frc::SwerveModuleState * iDesiredState);

  void setDesiredState(frc::SwerveModuleState * iDesiredState);

  void setNeoInverted(bool iInvertion);

  void refreshModule();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  rev::spark::SparkMax * m_MotorNeo;
  rev::spark::SparkMax * m_MotorNeo550;

  rev::spark::SparkRelativeEncoder * m_NeoEncoder;
  rev::spark::SparkRelativeEncoder * m_Neo550Encoder;
  rev::spark::SparkAbsoluteEncoder * m_Neo550AbsoluteEncoder;
  frc::PIDController * m_Neo550PID;

  frc::SwerveModuleState * m_ModuleState;
  frc::SwerveModulePosition * m_ModulePosition;
  
  units::meters_per_second_t m_maxSpeed = 1_mps;
  units::radians_per_second_t m_maxSpeed0 = units::radians_per_second_t(std::numbers::pi);
  float m_gearRatio = 1 / 5.08;
  double m_wheelPerimeter = 3 * 0.0254 * std::numbers::pi;
};