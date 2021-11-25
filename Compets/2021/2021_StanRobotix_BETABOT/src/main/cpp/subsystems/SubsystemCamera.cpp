/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubsystemCamera.h"

//SubsystemCamera::SubsystemCamera() : SubsystemBase("ExampleSubsystem") {}

/*
void SubsystemCamera::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  //frc::CameraServer::GetInstance().StartAutomaticCapture();
}
*/

SubsystemCamera::SubsystemCamera()
{
  mCameraCapture = new cv::VideoCapture(0);
}

SubsystemCamera::~SubsystemCamera()
{ }

void SubsystemCamera::captureImage()
{
  *mCameraCapture >> mMat;
  mCameraFilter.Process(mMat);
  for (grip::Line wCurrentLine : *mCameraFilter.GetFilterLinesOutput())
  {
    std::cout << wCurrentLine.length() << std::endl;
  }
}



// Put methods for controlling this subsystem
// here. Call these from Commands.
