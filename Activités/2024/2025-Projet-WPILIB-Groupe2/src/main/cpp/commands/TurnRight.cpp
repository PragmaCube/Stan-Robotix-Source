// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnRight.h"
#include <iostream>

TurnRight::TurnRight(SubDriveTrain *iDriveTrain, SubIMU *iIMU) 
{
  mDriveTrain = iDriveTrain;
  mIMU = iIMU;
  AddRequirements(mDriveTrain);
  AddRequirements(mIMU);
  mPIDController.SetSetpoint(90);
}

// Called when the command is initially scheduled.
void TurnRight::Initialize() {
  angleDebut = mIMU->getAngleYaw();
  std::cout << mIMU->getAngleYaw() << std::endl;
  std::cout << angleDebut << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void TurnRight::Execute() {
   mDriveTrain->drive(0, 0, mPIDController.Calculate(mIMU->getAngleYaw()-angleDebut), mIMU->getRotation2d());
   std::cout << "Angle courant : " << mIMU->getAngleYaw() << std::endl;
}

// Called once the command ends or is interrupted.
void TurnRight::End(bool interrupted) {}

// Returns true when the command should end.
bool TurnRight::IsFinished() {
  std::cout << "Angle debut : " << angleDebut << std::endl;
return (abs(90 - (mIMU->getAngleYaw()-angleDebut)) < 0.5);

}
