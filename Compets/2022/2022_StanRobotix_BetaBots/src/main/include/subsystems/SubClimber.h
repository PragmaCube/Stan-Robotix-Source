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
  enum Height{h0 = 0 ,h1 = 1, h2 = 2 , h3 = 3}; 
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Stage(Height iHeight);
  void UpHold();
  void DownHold();
  void Down();
  void Stop();
  
  int GetEncoderPosition();

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
    double mOffset = 0;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  // set PID coefficients
    /*mPidController.SetP(kP);
    mPidController.SetI(kI);
    mPidController.SetD(kD);
    mPidController.SetIZone(kIz);
    mPidController.SetFF(kFF);
    mPidController.SetOutputRange(kMinOutput, kMaxOutput);
    mPidController.SetSmartMotionMaxVelocity(kMaxVel);
    mPidController.SetSmartMotionMinOutputVelocity(kMinVel);
    mPidController.SetSmartMotionMaxAccel(kMaxAcc);
    mPidController.SetSmartMotionAllowedClosedLoopError(kAllErr);
*/
};
