// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// #include <frc2/command/PIDSubsystem.h>
#include "subsystems/SubPivot.h"

SubPivot::SubPivot ()
{
    // mPIDController.SetP(PivotConstants::kP);
    // mPIDController.SetI(PivotConstants::kI);
    // mPIDController.SetD(PivotConstants::kD);
    // mPIDController.SetIZone(PivotConstants::kIz);
    // mPIDController.SetFF(PivotConstants::kFF);

    // mPIDController.SetOutputRange(PivotConstants::kMinOutput, PivotConstants::kMaxOutput);
    // mPIDController.SetSmartMotionMaxVelocity(kMaxVel);
    // mPIDController.SetSmartMotionMinOutputVelocity(kMinVel);
    // mPIDController.SetSmartMotionMaxAccel(kMaxAcc);
    // mPIDController.SetSmartMotionAllowedClosedLoopError(kAllErr);
}

// This method will be called once per scheduler run
void SubPivot::Periodic() 
{
   mPIDController.SetReference(mHeight,rev::ControlType::kSmartMotion);
}

void SubPivot::pivotDown() 
{
    mPIDController.SetReference(PivotConstants::kHeightDown,rev::ControlType::kSmartMotion);
}

void SubPivot::pivotMiddle()
{
    mPIDController.SetReference(PivotConstants::kHeightMiddle,rev::ControlType::kSmartMotion);
}

void SubPivot::pivotUp()
{
    mPIDController.SetReference(PivotConstants::kHeightUp,rev::ControlType::kSmartMotion);
}

void SubPivot::pivotGo(double ivitesse)
{
    mPivotMotor.Set(ivitesse);
}

double SubPivot::getEncodeurPosition()
{
    return mPivotMotorEncodeur.GetPosition();
}

double SubPivot::getVelocityMotor()
{
    return mPivotMotorEncodeur.GetVelocity();
}
void SubPivot::stopPivot()
{
    mPivotMotor.Set(0);
}