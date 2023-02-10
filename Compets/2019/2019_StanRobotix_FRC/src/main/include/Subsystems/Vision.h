/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/Subsystem.h"
#include <CameraServer.h>
#include "RobotMap.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

#include <SmartDashboard/SmartDashboard.h>

class Vision : public frc::Subsystem {
 private:
  frc::CameraServer* mCameraServer;
  nt::NetworkTableInstance mNetworkTableInstanceInst; 

 public:
  Vision();

  void Initialization(); 
  void InitDefaultCommand() override;

  double GetContoursCentreX();
  double GetContourAngle();

  bool FoundContour();
 private:
  bool foundContour;
};
