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
  //Pourrait ne pas fonctionner, à voir...
  mCameraCapture = new cv::VideoCapture(0);
  *mCameraCapture >> mMat;
  mCameraFilter.Process(mMat);
}

SubsystemCamera::~SubsystemCamera()
{ 
  delete mCameraCapture;
}

void SubsystemCamera::streamLinesLenght()
{
  for (grip::Line wCurrentLine : *mCameraFilter.GetFilterLinesOutput())
  {
    std::cout << wCurrentLine.length() << std::endl;
  }
}

grip::Line SubsystemCamera::getAverageLine()
{
  grip::Line wAverageLine(0, 0, 0, 0);
  int wLineCount = 0;
  for (grip::Line wCurrentLine : *mCameraFilter.getFilterLinesOutput())
  {
    //Somme algébrique des coordonnées

    wAverageLine.x1 += wCurrentLine.x1; 
    wAverageLine.x2 += wCurrentLine.x2;
    wAverageLine.y1 += wCurrentLine.y1;
    wAverageLine.y2 += wCurrentLine.y2;
    wLineCount ++;
  }

  //On ne veut pas de divisions par 0 :)
  if (wLineCount)
  {
    //Calcul de moyenne

    wAverageLine.x1 /= wLineCount;
    wAverageLine.x2 /= wLineCount;
    wAverageLine.y1 /= wLineCount;
    wAverageLine.y2 /= wLineCount;
  }

  return wAverageLine;
}



// Put methods for controlling this subsystem
// here. Call these from Commands.
