/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <cameraserver/CameraServer.h>
#include "Camera.h"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>

class SubsystemCamera : public frc2::SubsystemBase {
 public:
  SubsystemCamera();
  ~SubsystemCamera();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  //A Commenter ?
  //void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */

  // A commenter ?
  //void SimulationPeriodic() override;


  void captureImage();


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  //frc::CameraServer mCameraServer;
  grip::Camera mCameraFilter;

  cv::Mat mMat;
  cv::VideoCapture* mCameraCapture;
};
