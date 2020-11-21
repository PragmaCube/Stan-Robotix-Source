/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <RobotMap.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/Spark.h>
#include <frc/Talon.h>

class DriveTrain : public frc::Subsystem {
 private:
  // 1 est a l'avant, 2 est a l'arriere
  frc::Spark motorL1{kMotorL1};
  frc::Talon motorL2{kMotorL2};
  frc::Talon motorR1{kMotorR1};
  frc::Talon motorR2{kMotorR2};  
  
  // frc::Spark motorL1{kMotorL1};
  // frc::Talon motorL2{10};
  // frc::Talon motorR1{10};
  // frc::Talon motorR2{10};  

  frc::MecanumDrive drive{motorL1, motorL2, motorR1, motorR2};

 public:
  DriveTrain();
  void Drive(double x, double y, double z);
  void InitDefaultCommand() override;
};
