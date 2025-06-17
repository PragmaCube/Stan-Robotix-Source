// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubArms.h"
#include <cmath>

SubArms::SubArms() {
    mSparkMaxRight = new rev::spark::SparkMax{ArmsConstants::kSparkMaxRightDeviceID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mSparkMaxLeft = new rev::spark::SparkMax{ArmsConstants::kSparkMaxLeftDeviceID, rev::spark::SparkLowLevel::MotorType::kBrushless};
    mSparkMaxRight->SetInverted(false);
    mSparkMaxLeft->SetInverted(true);
    mPIDRight = new frc::PIDController{ArmsConstants::kP, ArmsConstants::kI, ArmsConstants::kD};
    mPIDLeft = new frc::PIDController{ArmsConstants::kP, ArmsConstants::kI, ArmsConstants::kD};
};

// This method will be called once per scheduler run
void SubArms::Periodic() {

}

double SubArms::GetAngleRight()
{
    return (mSparkMaxRight->GetEncoder().GetPosition() + ArmsConstants::kOffset) / ArmsConstants::gearRatio * 2 * std::numbers::pi;
}

double SubArms::GetAngleLeft()
{
    return (mSparkMaxLeft->GetEncoder().GetPosition() + ArmsConstants::kOffset) / ArmsConstants::gearRatio * 2 * std::numbers::pi;
}

void SubArms::Stop()
{
    mSparkMaxRight->StopMotor();
    mSparkMaxLeft->StopMotor();
}

void SubArms::SetVoltageRight(units::volt_t iVoltage){
    mSparkMaxRight->SetVoltage(iVoltage);
}

void SubArms::SetVoltageLeft(units::volt_t iVoltage){
    mSparkMaxLeft->SetVoltage(iVoltage);
}

void SubArms::CounterGravity()
{
    double pivotAngleRight = GetAngleRight();
    mSparkMaxRight->SetVoltage(units::voltage::volt_t(ArmsConstants::kG * cos(pivotAngleRight)));

    double pivotAngleLeft = GetAngleLeft();
    mSparkMaxLeft->SetVoltage(units::voltage::volt_t(ArmsConstants::kG * cos(pivotAngleLeft)));
}

void SubArms::GoToPlace(double iSetPointRight, double iSetPointLeft){
    if (iSetPointLeft != PastSetPointLeft)
        {
            mPIDLeft->SetSetpoint(iSetPointLeft);
            PastSetPointLeft = iSetPointLeft;
        }
    if (iSetPointRight != PastSetPointRight)
        {
            mPIDRight->SetSetpoint(iSetPointRight);
            PastSetPointRight = iSetPointRight;
        }
    pivotAngleRight = GetAngleRight();
    OutputRight = mPIDRight->Calculate(pivotAngleRight) * 13;

    SetVoltageRight(units::volt_t(ArmsConstants::kG * cos(pivotAngleRight)) + units::volt_t(OutputRight));
  
    pivotAngleLeft = GetAngleLeft();
    OutputLeft = mPIDLeft->Calculate(pivotAngleLeft) * 13;

    SetVoltageLeft(units::volt_t(ArmsConstants::kG * cos(pivotAngleLeft)) + units::volt_t(OutputLeft));

    if (i == 30) {
    std::cout << "right error = " << iSetPointRight - pivotAngleRight << std::endl;
    std::cout << "left error = " << iSetPointLeft - pivotAngleLeft << std::endl;
    i = 0;}
    else {i++;}
}