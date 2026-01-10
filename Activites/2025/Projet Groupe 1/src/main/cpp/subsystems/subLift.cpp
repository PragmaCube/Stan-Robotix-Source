// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subLift.h"

subLift::subLift() {
    mSparkMaxG = new rev::spark::SparkMax (LiftConstants::kChannelG, rev::spark::SparkLowLevel::MotorType::kBrushless);
    mSparkMaxD = new rev::spark::SparkMax (LiftConstants::kChannelD, rev::spark::SparkLowLevel::MotorType::kBrushless);
}

// This method will be called once per scheduler run
void subLift::Periodic() {}

void subLift::LiftUp() {
    mSparkMaxG->Set(LiftConstants::kVitesse);
    mSparkMaxD->Set(-LiftConstants::kVitesse);
    std::cout<<Encoder;
}

void subLift::LiftDown() {
    mSparkMaxG->Set(-LiftConstants::kVitesse);
    mSparkMaxD->Set(LiftConstants::kVitesse);
    std::cout<<Encoder;
}

void subLift::StopLift() {
    mSparkMaxG->Set(0);
    mSparkMaxD->Set(0);
}

void subLift::GetEncoderPosition()
{
    Encoder= mSparkMaxD->GetAlternateEncoder().GetPosition()/48*3.56;
}
