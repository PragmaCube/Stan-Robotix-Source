// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subLift.h"

subLift::subLift() {
    mSparkMax1 = new frc::PWMSparkMax (LiftConstants::kChannel1);
    mSparkMax2 = new frc::PWMSparkMax (LiftConstants::kChannel2);
}

// This method will be called once per scheduler run
void subLift::Periodic() {}
