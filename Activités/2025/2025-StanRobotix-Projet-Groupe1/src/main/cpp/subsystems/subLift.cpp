// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subLift.h"

subLift::subLift() {
    mSparkMaxG = new frc::PWMSparkMax (LiftConstants::kChannelG);
    mSparkMaxD = new frc::PWMSparkMax (LiftConstants::kChannelD);
}

// This method will be called once per scheduler run
void subLift::Periodic() {}

void subLift::LiftUp() {
    mSparkMaxG->Set(LiftConstants::kVitesse);
    mSparkMaxD->Set(-LiftConstants::kVitesse);
}

void subLift::LiftDown() {
    mSparkMaxG->Set(-LiftConstants::kVitesse);
    mSparkMaxD->Set(LiftConstants::kVitesse);
}

void subLift::StopLift() {
    mSparkMaxG->Set(0);
    mSparkMaxD->Set(0);
}