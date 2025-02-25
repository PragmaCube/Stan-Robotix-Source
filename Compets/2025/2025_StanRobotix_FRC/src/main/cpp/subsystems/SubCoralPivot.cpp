// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubCoralPivot.h"
#include <cmath>


SubCoralPivot::SubCoralPivot(){
    mCoralPivotMotor = new rev::spark::SparkMax (CoralConstants::Pivot::kMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubCoralPivot::Periodic() {}

void SubCoralPivot::stopCoralPivot(){
    mCoralPivotMotor->StopMotor();
}

void SubCoralPivot::Pivot(){
    double kG = frc::SmartDashboard::GetNumber("kGCoral", 0.19);
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mCoralPivotMotor->SetVoltage(-(units::volt_t(kG)));  

//  std::cout << (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 << std::endl;
}

void SubCoralPivot::Pivot(float Sens){
    // mPIDController.SetSetpoint(Setpoint);
    
    double kG = frc::SmartDashboard::GetNumber("kGCoral", 0.19);
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mCoralPivotMotor->SetVoltage(Sens * (units::volt_t(kG)));  
    
    std::cout << 1 << std::endl;
}

void SubCoralPivot::PivotUp(){
    // mPIDController.SetSetpoint(Setpoint);
    
    double kG = frc::SmartDashboard::GetNumber("kGCoral", 0.19);
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mCoralPivotMotor->SetVoltage(-(units::volt_t(0.33)));  
}

void SubCoralPivot::Stop(){
    mCoralPivotMotor->StopMotor();
}

bool SubCoralPivot::atSetPoint(){
    return mPIDController.AtSetpoint();
}

void SubCoralPivot::SetSetPoint(double iSetPoint){
    mPIDController.SetSetpoint(iSetPoint);
}

/*
    le setpoint doit etre donné en tours, même type que le cout.
    le cout renvoi la position du pivot entre -1 et 1, avec 0 comme pivot horizontale.
    le PID devrait calculer une valeur aussi entre -1 et 1, qui se fait multiplier par 13 pour avoir une nombre utilisable de volts.
*/