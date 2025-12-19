// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    victorLeft1.SetInverted(true);
    victorLeft2.SetInverted(true);
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::TankDrive(double left, double right, int LBpressed) 
{
    m_drive.TankDrive(left * LBpressed / 2, right * LBpressed / 2);
}