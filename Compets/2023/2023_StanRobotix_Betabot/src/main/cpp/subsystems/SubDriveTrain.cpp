// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    motorL1 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorL1Id};
    motorL2 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorL2Id};
    motorR1 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR1Id};
    motorR2 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR2Id};

    drive = new frc::MecanumDrive{*motorL1, *motorL2, *motorR1, *motorR2};
    
    motorL1->SetInverted(true);
    motorL2->SetInverted(true);

    
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}
void SubDriveTrain::mecanumDrive(const float x, const float y, const float z, const frc::Rotation2d iRotation2d)
{
    drive->DriveCartesian(y*(vitesse), x*(vitesse), z*(vitesse), iRotation2d);
}

void SubDriveTrain::setVitesse(float Vitesse)
{
    vitesse = Vitesse;
}
// fichier local "", autre <>