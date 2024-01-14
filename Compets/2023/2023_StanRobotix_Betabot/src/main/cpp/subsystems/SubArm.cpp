// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
// Pour installer le PID
#include <frc2/command/PIDSubsystem.h>
#include "subsystems/SubArm.h"
// ---------------------

SubArm::SubArm()
{
    // Pour installer le PID
    mPIDController.SetP(ArmConstants::kP);
    mPIDController.SetI(ArmConstants::kI);
    mPIDController.SetD(ArmConstants::kD);
    mPIDController.SetIZone(ArmConstants::kIz);
    mPIDController.SetFF(ArmConstants::kFF);

    mPIDController.SetOutputRange(ArmConstants::kMinOutput, ArmConstants::kMaxOutput);
    mPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    mPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    mPIDController.SetSmartMotionMaxAccel(kMaxAcc);
    mPIDController.SetSmartMotionAllowedClosedLoopError(kAllErr);
    // ---------------------
}

// This method will be called once per scheduler run
void SubArm::Up()
{
    Height = ArmConstants::kArmLimitUp;
}

// This method will be called once per scheduler run
void SubArm::Down()
{
    Height = ArmConstants::kArmLimitDown;
}

double SubArm::GetEncodeurPosition()
{
    return mArmMotorEncodeur.GetPosition();
}

void SubArm::StopArm()
{
    mArmMotor.Set(0);
}


void SubArm::Periodic() 
{
    mPIDController.SetReference(Height,rev::ControlType::kSmartMotion);
}
