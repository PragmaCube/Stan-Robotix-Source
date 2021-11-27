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
  m_mat = new cv::Mat;
}

SubsystemCamera::~SubsystemCamera()
{ 
  delete m_mat;
}

void SubsystemCamera::streamLinesLenght()
{
  cv::VideoCapture w_camera(0);
  w_camera >> *m_mat;
  m_camera_processing.setImage(*m_mat);
  m_camera_processing.setParameters(7, 80, 5, 0, 0);
  m_camera_processing.Process();
  std::cout << m_camera_processing.getAverageLine().getLineLenght();
}

double getAverageAngle()
{
  cv::VideoCapture w_camera(0);
  w_camera >> *m_mat;
  m_camera_processing.setImage(*m_mat);
  m_camera_processing.setParameters(7, 80, 5, 0, 0);
  m_camera_processing.Process();
  return m_camera_processing.getAverageLine().getLineAngle();
}

double getAverageLenght()
{
  cv::VideoCapture w_camera(0);
  w_camera >> *m_mat;
  m_camera_processing.setImage(*m_mat);
  m_camera_processing.setParameters(7, 80, 5, 0, 0);
  m_camera_processing.Process();
  return m_camera_processing.getAverageLine().getLineLenght();
}



// Put methods for controlling this subsystem
// here. Call these from Commands.
