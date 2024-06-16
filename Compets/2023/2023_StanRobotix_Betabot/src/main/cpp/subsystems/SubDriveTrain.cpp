// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/subDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{

    mMotorL1 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorL1Id};
    mMotorL2 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorL2Id};
    mMotorR1 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR1Id};
    mMotorR2 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR2Id};

    mDrive = new frc::MecanumDrive{*mMotorL1, *mMotorL2, *mMotorR1, *mMotorR2};
    
    mMotorL1->SetInverted(true);
    mMotorL2->SetInverted(true);

}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}


void SubDriveTrain::mecanumDrive(float x, float y, float z, frc::Rotation2d iRotation2d)
{
    try
    {
        drive.DriveCartesian(y*vitesse, x*vitesse, z*vitesse, iRotation2d);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
}

// fichier local "", autre <>


int SubDriveTrain::getVitesse()
{
    return mVitesse;
}
