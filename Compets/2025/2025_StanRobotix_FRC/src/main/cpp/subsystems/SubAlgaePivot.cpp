// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAlgaePivot.h"

SubAlgaePivot::SubAlgaePivot(){
    mAlgaePivotMotor = new rev::spark::SparkMax (AlgaePivotConstants::kAlgaePivotMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubAlgaePivot::Periodic() {}

void SubAlgaePivot::setSetPoint(double iPoint){
    mPIDController.SetSetpoint(iPoint);
}

void SubAlgaePivot::runAlgaePivotPID(){
    mAlgaePivotMotor->Set(mPIDController.Calculate(mAlgaePivotMotor->GetEncoder().GetPosition()));
}

void SubAlgaePivot::stopAlgaePivot(){
    mAlgaePivotMotor->StopMotor();
}

void SubAlgaePivot::manualAlgaePivot(){
    mAlgaePivotMotor->Set(0.02);
}

void SubAlgaePivot::manualAlgaePivotReverse(){
    mAlgaePivotMotor->Set(-0.02);
}

bool SubAlgaePivot::isEnable(){
    return mEnable;
}

bool SubAlgaePivot::atSetPoint(){
    return mPIDController.AtSetpoint();
}