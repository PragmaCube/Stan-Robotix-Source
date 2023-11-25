// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    motorL1.SetInverted(true);
    motorL2.SetInverted(true);
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}
void SubDriveTrain::mecanumDrive(float x, float y, float z, frc::Rotation2d iRotation2d)
{
    drive.DriveCartesian(y*0.5, x*0.5, z*0.5, iRotation2d);
    
}

// fichier local "", autre <>