// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimitSwitch.h"

SubLimitSwitch::SubLimitSwitch(int iPort){
    *input = frc::DigitalInput(iPort);
};

bool SubLimitSwitch::getState(){
    return input->Get();
};

// This method will be called once per scheduler run
void SubLimitSwitch::Periodic() {}
