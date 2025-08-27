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

// Constructor that takes as parameters the IDs of the motor controllers for the Neo and Neo550 in one given module.
  SwerveModule(int iNeoMotorID, int iNeo550MotorID);

// Méthode that returns the SwerveModulePosition of the module.
  frc::SwerveModulePosition GetModulePosition();

// Method that returns the SwerveModuleState of the module
  frc::SwerveModuleState GetModuleState();

// Method that takes the desired SwerveModuleState as a parameter and returns an optimised SwerveModuleState.
  frc::SwerveModuleState OptimizeState(frc::SwerveModuleState iDesiredState);

// Method that takes the desired SwerveModuleState as a parameter and activates the motor controllers consequently.
  void SetDesiredState(frc::SwerveModuleState iDesiredState, double SpeedModulation);

// Method that reverses the motors direction.
  void SetNeoInverted(bool iInvertion);

// Method that updates the SwerveModulePosition and the SwerveModuleState of the module.
  void RefreshModule();

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
};