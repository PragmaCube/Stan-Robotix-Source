// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  mDriveTrain = new DriveTrain;
  // Initialize all of your commands and subsystems here
  mMotorSpeed[0] = DriveTrain::MotorSpeed::eSlow;
  mMotorSpeed[1] = DriveTrain::MotorSpeed::eMedium;
  mMotorSpeed[2] = DriveTrain::MotorSpeed::eFast;
  mEjector = new Ejector;
  // mAutoTimer.Start();
  mAutoTimer.Reset();
  mMotorIndex = 1;
  ConfigureButtonBindings();

}

void RobotContainer::Drive()
{
  
  if (mController.GetAButton() && !ejector_in_use)
  {
    ejector_in_use = true;
    mAutoTimer.Start();
    std::cout << "Pressed A Button" << std::endl;
  }

  std::cout << mAutoTimer.Get().value() << std::endl;

  if (ejector_in_use)
  {
    if (mAutoTimer.Get().value()<=0.5)
    {
      mEjector->Push();
    }
    else if (mAutoTimer.Get().value()<=1.65) 
    {
      mEjector->Pull();
    }
    else
    {
      mEjector->Stop();
      ejector_in_use = false;
      mAutoTimer.Stop();
      mAutoTimer.Reset();
    }
  }
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

void RobotContainer::Drive()
{
  if (mController.GetPOV() == 0)
  {
    if (mMotorIndex < 2)
    {
      mMotorIndex++;
    }
  }

  if (mController.GetPOV() == 180)
  {
    if (mMotorIndex > 0)
    {
      mMotorIndex--;
    }
  }
  std::cout<<mMotorIndex<<std::endl;

  mDriveTrain->TankDrive(
        - mController.GetLeftY(),
        - mController.GetRightY(), mMotorSpeed[mMotorIndex]);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
