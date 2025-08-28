// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/geometry/Rotation2d.h>
#include <ctre/phoenix6/Pigeon2.hpp>

#include <frc2/command/SubsystemBase.h> 

#include "Constants.h"


class SubIMU : public frc2::SubsystemBase {
 public:
  SubIMU();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  frc::Rotation2d GetRotation2d();

<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/subsystems/SubIMU.h
  void ResetAngle();

 private:
  
=======
  double getAngleYaw();

  double getRate();

  void resetAngle();

 private:

>>>>>>> origin/master:Activités/2025/PhotonVision_RnD/src/main/include/subsystems/SubIMU.h
  ctre::phoenix6::hardware::Pigeon2 * mIMU;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};