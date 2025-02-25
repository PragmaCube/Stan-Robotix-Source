// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAlgaePivot.h"
#include <cmath>


SubAlgaePivot::SubAlgaePivot(){
    mAlgaePivotMotor = new rev::spark::SparkMax (AlgaeConstants::Pivot::kMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubAlgaePivot::Periodic() {}

void SubAlgaePivot::Stop(){
    mAlgaePivotMotor->StopMotor();
}

void SubAlgaePivot::Pivot(){
    double kG = frc::SmartDashboard::GetNumber("kG", 0.19);
    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mAlgaePivotMotor->SetVoltage(-(units::volt_t(kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID));  

//  std::cout << (mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 << std::endl;
}

void SubAlgaePivot::Pivot(int Setpoint){
    mPIDController.SetSetpoint(Setpoint);
    
    double kG = frc::SmartDashboard::GetNumber("kG", 0.19);
    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mAlgaePivotMotor->SetVoltage(-(units::volt_t(kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID));  
}

bool SubAlgaePivot::atSetPoint(){
    return mPIDController.AtSetpoint();
}

void SubAlgaePivot::SetSetPoint(double iSetPoint){
    mPIDController.SetSetpoint(iSetPoint);
}

