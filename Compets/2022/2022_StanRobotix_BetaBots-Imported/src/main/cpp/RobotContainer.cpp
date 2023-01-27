// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {

  mEjector = new Ejector;
  mAutoTimer.Start();
  ConfigureButtonBindings();

}

void RobotContainer::Drive()
{
  if (mController.GetAButton() && !ejector_in_use)
  {
    ejector_in_use = true;
    mAutoTimer.Start();
  }

  if (ejector_in_use)
  {
    if (mAutoTimer.Get().value()<=2)
    {
      mEjector->Push();
    }
    else if (mAutoTimer.Get().value()<=4)
    {
      mEjector->Pull();
    }
    else
    {
      mEjector->Stop();
      ejector_in_use = false;
      mAutoTimer.Stop();
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
