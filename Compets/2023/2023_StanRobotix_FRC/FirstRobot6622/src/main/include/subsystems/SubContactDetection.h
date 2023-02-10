// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>

class SubContactDetection : public frc2::SubsystemBase {
 public:
  SubContactDetection();

  bool GetContactStatus();



  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  frc::bool ContactList [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ;

  frc::DigitalInput mContactStatus {0}; 

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

