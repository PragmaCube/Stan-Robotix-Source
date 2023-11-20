// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::tankDrive(double leftSpeed, double rightSpeed) 
{

    Drive.TankDrive(leftSpeed*coef, rightSpeed*coef); 

}

void SubDriveTrain::setCoef(int Position)
{
    coef = Mapper[TCoef[Position]];
}
