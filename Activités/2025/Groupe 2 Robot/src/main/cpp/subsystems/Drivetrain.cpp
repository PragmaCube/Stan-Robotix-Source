// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
{
   moteur1L = new  ctre::phoenix::motorcontrol::can::WPI_TalonSRX{DriveTrainConstants::kMoteur1LID};
   moteur2L = new  ctre::phoenix::motorcontrol::can::WPI_TalonSRX{DriveTrainConstants::kMoteur2LID};
   moteur1R = new  ctre::phoenix::motorcontrol::can::WPI_TalonSRX{DriveTrainConstants::kMoteur1RID};
   moteur2R = new  ctre::phoenix::motorcontrol::can::WPI_TalonSRX{DriveTrainConstants::kMoteur2RID};
   
   GroupL = new frc::MotorControllerGroup{*moteur1L, *moteur2L};
   GroupR = new frc::MotorControllerGroup{*moteur1R, *moteur2R};
   Drive = new frc::DifferentialDrive(*GroupL, *GroupR);
}

// This method will be called once per scheduler runs
void Drivetrain::Periodic() {}

void Drivetrain::TankDrive( double leftSpeed, double rightSpeed)
{
    Drive->TankDrive( leftSpeed, rightSpeed);
}




