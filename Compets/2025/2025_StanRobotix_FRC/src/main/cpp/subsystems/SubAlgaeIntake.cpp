// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAlgaeIntake.h"

SubAlgaeIntake::SubAlgaeIntake() {
   mAlgaeIntakeMotor = new rev::spark::SparkMax (AlgaeConstants::Intake::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless);
};

// This method will be called once per scheduler run
void SubAlgaeIntake::Periodic() {}

void SubAlgaeIntake::Outake() {
    mAlgaeIntakeMotor->Set(AlgaeConstants::Intake::kAlgaeIntakeSpeed);
}

void SubAlgaeIntake::Intake() {
    mAlgaeIntakeMotor->Set(-AlgaeConstants::Intake::kAlgaeIntakeSpeed);
}

void SubAlgaeIntake::Stop() {
    mAlgaeIntakeMotor->StopMotor();
}

void SubAlgaeIntake::KeepAlgae(){
    mAlgaeIntakeMotor->Set(0.15);
}

void SubAlgaeIntake::SetCommandsState(bool iState){
    CommandsEnabled = iState;
}

bool SubAlgaeIntake::GetCommandsState(){
    return CommandsEnabled;
}