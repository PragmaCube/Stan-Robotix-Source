// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>

#include <frc2/command/SubsystemBase.h>
#include <photon/PhotonCamera.h>
#include <photon/targeting/PhotonTrackedTarget.h>


class SubCameraVision : public frc2::SubsystemBase {
 public:
  SubCameraVision();

  frc::Pose2d tragetPose();

  bool isTarget();

  double getYaw();
  double getPitch();
  double getSkew();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  photon::PhotonCamera usbCam{"USB_CAM"};
  photon::PhotonPipelineResult CamResults = usbCam.GetLatestResult();
  photon::PhotonTrackedTarget target = CamResults.GetBestTarget();
};
