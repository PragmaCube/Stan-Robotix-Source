// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubArm.h"
#include <iostream>

SubArm::SubArm()
{
    
}

// This method will be called once per scheduler run
void SubArm::Up()
{
    mArmMotor.Set(ArmConstants::motorSpeed);	
}

// This method will be called once per scheduler run
void SubArm::Down()
{
    mArmMotor.Set(-(ArmConstants::motorSpeed));
}

double SubArm::GetEncodeurPosition()
{
    return mArmMotorEncodeur.GetPosition();
}

void SubArm::StopArm()
{
    std::cout<<mArmMotorEncodeur.GetPosition();
    mArmMotor.Set(0);
}

void SubArm::Periodic() {}

  

