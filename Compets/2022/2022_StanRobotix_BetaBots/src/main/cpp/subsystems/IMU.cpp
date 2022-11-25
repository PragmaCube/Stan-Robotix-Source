// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IMU.h"

#include "subsystems/ExampleSubsystem.h"

IMU::IMU() = default;

// This method will be called once per scheduler run
void IMU::Periodic() {}

 float getAccelX() {
     return static_cast<float>(mIMU.GetAccelX());
 }

 float getAccelY(){
     return static_cast<float>(mIMU.GetAccelY());
 }

 float getAngle(){
     return static_cast<float>(mIMU.GetAngle());
 }


 