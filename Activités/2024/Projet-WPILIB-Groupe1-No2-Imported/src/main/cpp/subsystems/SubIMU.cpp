// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIMU.h"

SubIMU::SubIMU()
{
    mIMU = new ctre::phoenix6::hardware::Pigeon2{1};
}

// This method will be called once per scheduler run
void SubIMU::Periodic() {}

<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/cpp/subsystems/SubIMU.cpp
frc::Rotation2d SubIMU::GetRotation2d()
{
    return mIMU->GetRotation2d();
}

void SubIMU::ResetAngle()
{
    mIMU->Reset();
}
=======
frc::Rotation2d SubIMU::getRotation2d() {
    return mIMU.GetRotation2d();
}
>>>>>>> origin/master:Activités/2024/Projet-WPILIB-Groupe1-No2-Imported/src/main/cpp/subsystems/SubIMU.cpp
