// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>

#include <vector>

class SubContactDetection : public frc2::SubsystemBase {
 public:
  
  SubContactDetection();

  bool GetContactStatus();
  
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
   bool mContactStatus [10] = {false, false, false, false, false, false, false, false, false, false} ;
   std::vector<frc::DigitalInput *> mTototo;

  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};