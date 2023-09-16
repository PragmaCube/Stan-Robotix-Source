// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "PerformanceMonitor.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <Constants.h>
#include <vector>
#include <frc/AnalogInput.h>

class SubContactDetection : public frc2::SubsystemBase, public PerformanceMonitor {
 public:
   enum InputDetection_t {input0, input1, input2, input3, input4, input5, input6, input7, input8, input9, inputMax};
  SubContactDetection();

  bool GetContactStatus(InputDetection_t index);

  void EnableLog(bool iEnable) {};
 
  void Init();

 private:
  frc::AnalogInput mContactDetection{kContactDetectionDIO};
  
  virtual void doExecute();

  virtual std::string getName() { return "SubContactDetection"; }

   std::vector<frc::DigitalInput *> mDigitalInputVector;

  bool mContactCache[10];
};