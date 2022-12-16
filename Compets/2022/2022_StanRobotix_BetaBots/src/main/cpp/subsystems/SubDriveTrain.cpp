// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"
#include <iostream>

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::MoveDrive(double iLeftHand, double iRightHand, MotorSpeed iMotorSpeed)  
{
    double wLeftSpeed = 0.0, wRightSpeed = 0.0;

    switch (iMotorSpeed)
    {
    case eSlow:
        wLeftSpeed = 0.60 * iLeftHand;
        wRightSpeed = -0.60 * iRightHand * kCoeffFriction;
        break;

    case eMedium:
        wLeftSpeed = 0.70 * iLeftHand;
        wRightSpeed = -0.70 * iRightHand * kCoeffFriction;
        break;

    case eFast:
        wLeftSpeed = 0.90 * iLeftHand;
        wRightSpeed= -0.90 * iRightHand * kCoeffFriction;
        break;

    default:
        wLeftSpeed = 0.45 * iLeftHand;
        wRightSpeed= -0.45 * iRightHand * kCoeffFriction;
        break;
    }
    mDriveTrain.TankDrive(wLeftSpeed, wRightSpeed);

  //  std::cout << "Speed Left " << wLeftSpeed << "Speed Left " << wRightSpeed << std::endl; 
}