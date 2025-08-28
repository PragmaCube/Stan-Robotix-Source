// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubCameraVision.h"

SubCameraVision::SubCameraVision() = default;

// This method will be called once per scheduler run
void SubCameraVision::Periodic() {
    photon::PhotonPipelineResult CamResults = usbCam.GetLatestResult();
    photon::PhotonTrackedTarget target = CamResults.GetBestTarget();
}

frc::Pose2d SubCameraVision::tragetPose() {
    return frc::Pose2d();
}

bool SubCameraVision::isTarget() {
 //   return CamResults.HasTargets();
 return 0;
}

double SubCameraVision::getPitch() {
 //   return target.GetPitch();
  return 0;

}

double SubCameraVision::getYaw() {
    return usbCam.GetLatestResult().GetBestTarget().GetYaw();
}

std::vector<photon::TargetCorner> SubCameraVision::getCorner() {
   // return target.GetSkew();<
    return usbCam.GetLatestResult().GetBestTarget().GetMinAreaRectCorners();
}