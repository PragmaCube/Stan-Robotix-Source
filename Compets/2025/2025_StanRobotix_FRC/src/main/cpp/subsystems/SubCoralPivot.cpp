// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubCoralPivot.h"
#include <cmath>


SubCoralPivot::SubCoralPivot(){
    mCoralPivotMotor = new rev::spark::SparkMax (CoralConstants::Pivot::kMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void SubCoralPivot::Periodic() {
    mPIDController.SetP(frc::SmartDashboard::GetNumber("kPCoral", 0));
    mPIDController.SetI(frc::SmartDashboard::GetNumber("kICoral", 0));
    mPIDController.SetD(frc::SmartDashboard::GetNumber("kDCoral", 0));
}

void SubCoralPivot::stopCoralPivot(){
    mCoralPivotMotor->StopMotor();
}

void SubCoralPivot::Pivot(){
    double kG = frc::SmartDashboard::GetNumber("kGCoral", 0.19);
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mCoralPivotMotor->SetVoltage(-(units::volt_t(kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID));  

//  std::cout << (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 << std::endl;
}

void SubCoralPivot::Pivot(int Sens){    
    double kG = frc::SmartDashboard::GetNumber("kGCoral", 0.19);
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mCoralPivotMotor->SetVoltage(Sens * (units::volt_t(kG)));  
}

void SubCoralPivot::Pivot(double Setpoint){
    mPIDController.SetSetpoint(Setpoint);
    
    double kG = frc::SmartDashboard::GetNumber("kGCoral", 0.19);
    double pivotPositionRad = (mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController.Calculate((mCoralPivotMotor->GetEncoder().GetPosition() + 11.7) / 80) * 13;

    mCoralPivotMotor->SetVoltage(-(units::volt_t(kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID));  
}

bool SubCoralPivot::atSetPoint(){
    return mPIDController.AtSetpoint();
}

void SubCoralPivot::SetSetPoint(double iSetPoint){
    mPIDController.SetSetpoint(iSetPoint);
}
