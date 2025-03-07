// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubReefPivot.h"
#include <cmath>


SubReefPivot::SubReefPivot(){
    mReefPivotMotor = new rev::spark::SparkMax (ReefConstants::Pivot::kMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless);
    mReefIntakeMotor = new rev::spark::SparkMax (13,  rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubReefPivot::Periodic() {
    // std::cout << (mReefPivotMotor->GetEncoder().GetPosition() + kOffset) / 20 * 2 * std::numbers::pi << std::endl;
}

void SubReefPivot::StopPivot(){
    mReefPivotMotor->StopMotor();
}

void SubReefPivot::Pivot(double Setpoint){
    mPIDController.SetSetpoint(Setpoint);
    
    double pivotPositionRad = (mReefPivotMotor->GetEncoder().GetPosition() + kOffset) / 20 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mReefPivotMotor->GetEncoder().GetPosition() + kOffset) / 20 * 2 * std::numbers::pi) * 13;

    mReefPivotMotor->SetVoltage(-(units::volt_t(kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID) * PIDEnable);  //   
    // std::cout << CalculatedPID << std::endl;
}

bool SubReefPivot::AtSetPoint(){
    return mPIDController.AtSetpoint();
}

void SubReefPivot::SetSetPoint(double iSetPoint){
    mPIDController.SetSetpoint(iSetPoint);
}

void SubReefPivot::SetPIDEnable(bool iState){
    PIDEnable = iState;
}

void SubReefPivot::StayStill(){
    mReefPivotMotor->SetVoltage(units::volt_t(-0.75));
}

void SubReefPivot::CounterGravity(){
    double pivotPositionRad = (mReefPivotMotor->GetEncoder().GetPosition() + kOffset) / 20 * 2 * std::numbers::pi;
    mReefPivotMotor->SetVoltage(-(units::volt_t(kG * cos(pivotPositionRad))));
}

void SubReefPivot::Intake(double iPercent){
    mReefIntakeMotor->Set(iPercent);
}

void SubReefPivot::StopIntake(){
    mReefIntakeMotor->StopMotor();
}

void SubReefPivot::SetPivotVoltage(double iVoltage){
    mReefPivotMotor->SetVoltage(units::volt_t(iVoltage));
}