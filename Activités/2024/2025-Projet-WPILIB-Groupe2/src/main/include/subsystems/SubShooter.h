// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include "Constants.h"

class SubShooter : public frc2::SubsystemBase {
 public:
  SubShooter();

<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/subsystems/SubCoralIntake.h
=======
  void invertRotation();

  void Shoot();

  void stop();

  void startAndStop();

>>>>>>> origin/master:Activités/2024/2025-Projet-WPILIB-Groupe2/src/main/include/subsystems/SubShooter.h
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/subsystems/SubCoralIntake.h

  void SetVoltage(double);

  void SetPercentage(double);
  
  void Stop();

 private:
  rev::spark::SparkMax * mCoralIntakeMotor = nullptr;
=======
 private:
>>>>>>> origin/master:Activités/2024/2025-Projet-WPILIB-Groupe2/src/main/include/subsystems/SubShooter.h
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  rev::spark::SparkMax * mMotorShooter = nullptr;
  bool isRotated = false;
};
