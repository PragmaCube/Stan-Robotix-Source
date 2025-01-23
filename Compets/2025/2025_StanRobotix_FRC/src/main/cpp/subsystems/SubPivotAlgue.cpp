// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPivotAlgue.h"

SubPivotAlgue::SubPivotAlgue() = default;

// This method will be called once per scheduler run
void SubPivotAlgue::Periodic() {
    mMoteurPivotAlgue = new rev::spark::SparkMax (Pivot::Algue::moteurPort,  rev::spark::SparkLowLevel::MotorType::kBrushless);
}

void SubPivotAlgue::Up() {
    PIDController.SetSetpoint(0);
}

void SubPivotAlgue::Down() {
    PIDController.SetSetpoint(180);
    mMoteurPivotAlgue->Set(PIDController.Calculate(mMoteurPivotAlgue->GetEncoder().GetPosition()));
}

void SubPivotAlgue::Recup() {
    PIDController.SetSetpoint(45);

}
