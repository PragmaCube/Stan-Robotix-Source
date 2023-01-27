// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Use addRequirements() here to declare subsystem dependencies.
  mUltrasonic = new SubUltrasonic;
  vas_y = 0;
}

void RobotContainer::Drive() 
{
  if (vas_y%5 == 0)
  {
    std::cout << mUltrasonic->getDistance() << std::endl;
    vas_y=1;
  }
  else
  {
    vas_y++;
  }
  
}

