// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/Pigeon2.hpp>
#include "Constants.h"
#include <iostream>


class SubIMU : public frc2::SubsystemBase {
 public:
<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/subsystems/SubAlgaeIntake.h
  SubAlgaeIntake();
  
  void Stop();

  /* Sets a voltage to keep the algae in the mechanism. This method is 
   * useful when the motor of the intake is in idle mode,
   * which is the case when you need to use them for the climbing phase. */
  void KeepAlgae();
  
  void SetPercentage(double);
  
=======
  SubIMU();


  frc::Rotation2d getRotation2d();

  double getAngleYaw();
>>>>>>> origin/master:Activités/2025/2025_StanRobotix_Gala/src/main/include/subsystems/SubIMU.h
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void ResetAngle();


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  ctre::phoenix6::hardware::Pigeon2 mIMU{DrivingConstants::pigeon2port};
};