// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{    
    motorL1.SetInverted(true);
    motorL2.SetInverted(true);
    vitesse = 0.5F;
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::mecanumDrive(float x, float y, float z, frc::Rotation2d iRotation2d)
{
    try
    {
        drive.DriveCartesian(y*vitesse, x*vitesse, z*vitesse, iRotation2d);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
}

void SubDriveTrain::setVitesse(float Vitesse)
{
    vitesse = Vitesse;
}

