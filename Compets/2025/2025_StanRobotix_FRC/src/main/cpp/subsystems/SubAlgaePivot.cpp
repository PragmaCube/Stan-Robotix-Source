// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAlgaePivot.h"
#include <cmath>


SubAlgaePivot::SubAlgaePivot(){
    // frc::ArmFeedforward::kv_unit 
  //  units::unit_t<kv_units> kV = 1.95;
    mAlgaePivotMotor = new rev::spark::SparkMax (AlgaePivotConstants::kAlgaePivotMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless);
   // feedForward = new frc::ArmFeedforward(units::volt_t(AlgaeIntakeConstants::kS), kV);
}

// This method will be called once per scheduler run
void SubAlgaePivot::Periodic() {}

void SubAlgaePivot::setSetPoint(double iPoint){ 
    mPIDController.SetSetpoint(iPoint);
}

void SubAlgaePivot::runAlgaePivotPID(){
    // mAlgaePivotMotor->SetVoltage(feedForward->Calculate(SubAlgaePivot::getAlgaePivotEncoderPosition(),SubAlgaePivot::getAlgaePivotEncoderVelocity()));
}

void SubAlgaePivot::stopAlgaePivot(){
    mAlgaePivotMotor->StopMotor();
}

int SubAlgaePivot::sgn(int x){
  return 1;
  //  return x > 0 ? 1 : -1 x < 0 ? -1 : 0
}

void SubAlgaePivot::manualAlgaePivot(){
    mPIDController.SetSetpoint(frc::SmartDashboard::GetNumber("SetPointUp", -0.2));
    //mAlgaePivotMotor->SetVoltage(units::volt_t(AlgaeIntakeConstants::kG) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 4.54766) / 64 * std::numbers::pi) + units::volt_t(AlgaeIntakeConstants::kS) * sgn(units::rad_per_s(mAlgeaPivotMotor->rev::RelativeEncoder::GetVelocity())) + AlgaeIntakeConstants::kV * sgn(units::rad_per_s(mAlgeaPivotMotor->rev::RelativeEncoder::GetVelocity())) + AlgaeIntakeConstants::kA * ((units::rad_per_s(mAlgeaPivotMotor->rev::RelativeEncoder::GetVelocity())-velocity) / 0.02));
  // mAlgaePivotMotor->SetVoltage(-(units::volt_t(frc::SmartDashboard::GetNumber("kG", 0) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi))) + units::volt_t(mPIDController.Calculate((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * std::numbers::pi) * 13));  
   mAlgaePivotMotor->SetVoltage(-(units::volt_t(frc::SmartDashboard::GetNumber("kG", 0) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi))));  
    //    mAlgaePivotMotor->SetVoltage((-units::volt_t(frc::SmartDashboard::GetNumber("armVoltage", 0.2274)) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 4.54766) / 64 * std::numbers::pi)));  
    std::cout << (mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi << std::endl;
   // velocityUp = units::rad_per_s(mAlgeaPivotMoteur->rev::RelativeEncoder::GetVelocity());
}

void SubAlgaePivot::manualAlgaePivotReverse(){
    mPIDController.SetSetpoint(frc::SmartDashboard::GetNumber("SetPointDown", 0.2274));
    //mAlgaePivotMotor->SetVoltage(-(units::voltage::volt_t(frc::SmartDashboard::GetNumber("armVoltage", 0.2274)) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 4.54766) / 64 * std::numbers::pi)));
    //std::cout << (mAlgaePivotMotor->GetEncoder().GetPosition() + 4.54766 + 8) / 64 * std::numbers::pi << std::endl;
   mAlgaePivotMotor->SetVoltage(-(units::volt_t(frc::SmartDashboard::GetNumber("kG", 0) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi))) );  
   
   //mAlgaePivotMotor->SetVoltage(-(units::volt_t(frc::SmartDashboard::GetNumber("kG", 0) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi))) + units::volt_t(mPIDController.Calculate((mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * std::numbers::pi) * 13));  
   // mAlgaePivotMotor->SetVoltage(-(units::volt_t(frc::SmartDashboard::GetNumber("armVoltage", 0.2274)) * cos((mAlgaePivotMotor->GetEncoder().GetPosition() + 4.54766) / 64 * std::numbers::pi)));  
    std::cout << (mAlgaePivotMotor->GetEncoder().GetPosition() + 11.7) / 80 * 2 * std::numbers::pi << std::endl;
}

bool SubAlgaePivot::atSetPoint(){
    return mPIDController.AtSetpoint();
}

units::radian_t SubAlgaePivot::getAlgaePivotEncoderPosition(){
    return units::radian_t(mAlgaePivotMotor->GetEncoder().GetPosition() + 8.0);
}

units::angular_velocity::radians_per_second_t SubAlgaePivot::getAlgaePivotEncoderVelocity(){
    return units::angular_velocity::radians_per_second_t (mAlgaePivotMotor->GetEncoder().GetVelocity());
}