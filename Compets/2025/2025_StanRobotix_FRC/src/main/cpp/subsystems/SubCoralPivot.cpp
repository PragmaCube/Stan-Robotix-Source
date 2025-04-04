// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubCoralPivot.h"
#include <cmath>


SubCoralPivot::SubCoralPivot(){
    mCoralPivotMotor = new rev::spark::SparkMax (CoralConstants::Pivot::kMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless);
    mPIDController.SetTolerance(0.1);
}

// This method will be called once per scheduler run
void SubCoralPivot::Periodic() {
    // std::cout << cos((mCoralPivotMotor->GetEncoder().GetPosition() + kOffset) / 20 * 2 * std::numbers::pi) << std::endl; //  
    // std::cout << (mCoralPivotMotor->GetEncoder().GetPosition() + kOffset) / 64 * 2 * std::numbers::pi << std::endl;
    // std::cout << mCoralPivotMotor->GetEncoder().GetPosition() << std::endl;
}


void SubCoralPivot::Pivot(float SetPoint){
    mPIDController.SetSetpoint(SetPoint);
    
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + kOffset) / 64 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mCoralPivotMotor->GetEncoder().GetPosition() + kOffset) / 64 * 2 * std::numbers::pi) * 13;

    mCoralPivotMotor->SetVoltage(-(units::volt_t(kG)) * cos(pivotPositionRad) + units::volt_t(CalculatedPID) * PIDEnable);
}

void SubCoralPivot::Stop(){
    mCoralPivotMotor->StopMotor();
}

bool SubCoralPivot::AtSetPoint(){
    return mPIDController.AtSetpoint();
}

void SubCoralPivot::SetSetPoint(double iSetPoint){
    mPIDController.SetSetpoint(iSetPoint);
}

void SubCoralPivot::SetPIDEnable(bool iState){
    PIDEnable = iState;
}

SubCoralPivot::StatesCoral SubCoralPivot::GetState(){
    return mState;
}

void SubCoralPivot::SetState(StatesCoral iState){
    mState = iState;
}

void SubCoralPivot::CounterGravity(){
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + kOffset) / 20 * 2 * std::numbers::pi;   
    mCoralPivotMotor->SetVoltage(-units::volt_t(kG) * cos(pivotPositionRad)); //  
}

void SubCoralPivot::SetVoltage(double iVoltage){
    mCoralPivotMotor->SetVoltage(units::volt_t(iVoltage));
}

double SubCoralPivot::GetPosition(){
    return (mCoralPivotMotor->GetEncoder().GetPosition() + kOffset) / 20 * 2 * std::numbers::pi;
}

/*
    le setpoint doit etre donné en tours, même type que le cout.
    le cout renvoi la position du pivot entre -1 et 1, avec 0 comme pivot horizontale.
    le PID devrait calculer une valeur aussi entre -1 et 1, qui se fait multiplier par 13 pour avoir une nombre utilisable de volts.
*/