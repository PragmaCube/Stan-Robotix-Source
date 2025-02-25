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
// Constructeur de la classe avec un motorID pour le Neo et un pour le Neo550
  SwerveModule(int iNeoMotorID, int iNeo550MotorID);

// Méthode qui retourne le SwerveModulePosition du module
  frc::SwerveModulePosition getModulePosition();
// Méthode qui retourne le SwerveModuleState du module
  frc::SwerveModuleState getModuleState();

// Méthode qui retourne un SwerveModuleState optimisé à partir du SwerveModuleState désiré
  frc::SwerveModuleState OptimizeState(frc::SwerveModuleState * iDesiredState);

// Méthode qui fait rouler le module à partir du SwerveModuleState désiré
  void setDesiredState(frc::SwerveModuleState * iDesiredState);

// Méthode qui inverse le moteur Neo du module
  void setNeoInverted(bool iInvertion);

// Méthode qui met à jour le SwerveModulePosition et le SwerveModuleState du module
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
};