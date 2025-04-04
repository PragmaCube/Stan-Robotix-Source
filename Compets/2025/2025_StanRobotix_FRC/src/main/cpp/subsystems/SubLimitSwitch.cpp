// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimitSwitch.h"

SubLimitSwitch::SubLimitSwitch(int iPort, int iPort2){
    input = new frc::DigitalInput{iPort};
    input2 = new frc::DigitalInput{iPort2};
}

bool SubLimitSwitch::getState(int iPort){
    if (input->GetChannel() == iPort)
        {
            return input->Get();
        }
    else if (input2->GetChannel() == iPort)
    {
        return input2->Get();
    }
}

// This method will be called once per scheduler run
void SubLimitSwitch::Periodic() {}
