// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class SubAscenseur : public frc2::SubsystemBase {
 public:
  SubAscenseur();

  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  int getVitesse();

  void setVitesse(float Vitesse);

  void Set(double iVitesse);



 private:

  float vitesse = 0;

  rev::CANSparkMax mAscenseurMotor1 {AscenseurConstants::kMotorId1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax mAscenseurMotor2 {AscenseurConstants::kMotorId2, rev::CANSparkMax::MotorType::kBrushless};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
