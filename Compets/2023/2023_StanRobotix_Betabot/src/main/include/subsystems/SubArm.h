// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


#include <rev/SparkMaxRelativeEncoder.h>
#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/GenericEntry.h>
#include <networktables/NetworkTableInstance.h>



class SubArm : public frc2::SubsystemBase {
 public:
  SubArm();
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void PosDown();
  void PosUp();

  void Move(float);

  double CurrentPosition();
  double CurrentSpeed();

  void Init();

 private:

  frc::ShuffleboardTab& mArmTab = frc::Shuffleboard::GetTab("Arm");

  rev::CANSparkMax mMotorArm{ArmConstants::kArmCanId, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder mMotorArmEncoder = mMotorArm.GetEncoder();
  rev::SparkMaxPIDController mPIDArmController = mMotorArm.GetPIDController();


  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
