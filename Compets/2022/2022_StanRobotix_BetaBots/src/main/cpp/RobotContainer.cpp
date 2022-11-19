// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <iostream>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {

  mEjector = new Ejector;
  // mAutoTimer.Start();
  mAutoTimer.Reset();
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

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
