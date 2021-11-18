/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubsystemCamera.h"

SubsystemCamera::SubsystemCamera() : Subsystem("ExampleSubsystem") {}

void SubsystemCamera::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  mCameraInput = frc::CameraServer.getInstance().startAutomaticCapture();
  mCameraInput.setResolution(320, 240);
}

std::vector<grip::Line> SubsystemCamera::getLines()
{
  mCamera.process(mCameraInput);
  return mCamera.GetFilterLinesOutput();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
