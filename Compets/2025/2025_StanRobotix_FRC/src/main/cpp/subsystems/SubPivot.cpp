// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPivot.h"

SubPivot::SubPivot(){
    mMoteurPivot = new rev::spark::SparkMax (PivotConstants::moteurPivot,  rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubPivot::Periodic() {}

void SubPivot::setSetPoint(double iPoint){
    PIDController.SetSetpoint(iPoint);
}

void SubPivot::runPivot(){
    mMoteurPivot->Set(PIDController.Calculate(mMoteurPivot->GetEncoder().GetPosition()));
}

void SubPivot::stopPivot(){
    mMoteurPivot->StopMotor();
}

bool SubPivot::isEnable(){
    return mEnable;
}

bool SubPivot::atSetPoint(){
    return PIDController.AtSetpoint();
}