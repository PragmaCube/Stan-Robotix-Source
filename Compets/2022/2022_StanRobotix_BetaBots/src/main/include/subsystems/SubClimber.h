// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <rev/SparkMaxRelativeEncoder.h>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/SmartDashboard.h>


#include "Constants.h"
#include <frc2/command/SubsystemBase.h>

class SubClimber : public frc2::SubsystemBase {
 public:
  SubClimber();
  enum eHeight{h0 = 0 ,h1 = 1, h2 = 2 , h3 = 3}; // TODO: donner des noms plus explicites
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Stage(eHeight iHeight);
  void UpHold();
  void DownHold();
  
  int GetEncoderPosition();

  bool isOperationCompleted();

  void Periodic();
  
  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
    
    rev::CANSparkMax mMotorClimber{kCanIdClimber, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxRelativeEncoder mMotorEncoder = mMotorClimber.GetEncoder();
    rev::SparkMaxPIDController mPidController = mMotorClimber.GetPIDController();
    double mHeight_ = kMinHeight;
};
