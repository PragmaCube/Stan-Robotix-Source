// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <Constants.h>
#include <vector>

class SubContactDetection : public frc2::SubsystemBase {
 public:
  
  SubContactDetection();

  bool GetContactStatus(int index);
  
  int mIndex=0;
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Init();

 private:
  // bool mContactStatus [10] = {false, false, false, false, false, false, false, false, false, false} ;
   std::vector<frc::DigitalInput *> mDigitalInputVector;

  bool mContactCache[10];
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};