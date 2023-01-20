// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Use addRequirements() here to declare subsystem dependencies.
  mUltrasonic = new SubUltrasonic;
}

void RobotContainer::Drive() 
{
  std::cout << mUltrasonic->getDistance() << std::endl;
}

