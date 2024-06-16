// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain()
{
    mMotorL1 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorL1Id};
    mMotorL2 = new ctre::phoenix::motorcontrol::can::WPI_TalonSRX{DriveTrainConstants::kMotorL2Id};
    mMotorR1 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR1Id};
    mMotorR2 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX{DriveTrainConstants::kMotorR2Id};

    mDrive = new frc::MecanumDrive{*mMotorL1, *mMotorL2, *mMotorR1, *mMotorR2};
    
    mMotorL1->SetInverted(true);
    mMotorL2->SetInverted(true);
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

void SubDriveTrain::mecanumDrive(const float iX, const float iY, const float iZ, const frc::Rotation2d iRotation2d)
{
    mDrive->DriveCartesian(iY*(mVitesse), -iX*(mVitesse), -iZ*(mVitesse), -iRotation2d);
}

void SubDriveTrain::mecanumDrive(const float iX, const float iY, const float iZ)
{
    mDrive->DriveCartesian(iY*(mVitesse), -iX*(mVitesse), -iZ*(mVitesse));
}

void SubDriveTrain::setVitesse(float iVitesse)
{
    mVitesse = iVitesse;
}

int SubDriveTrain::getVitesse()
{
    return mVitesse;
}

void SubDriveTrain::setEnableDriveTrain(bool iEnable)
{
    mEnable = iEnable;
}

bool SubDriveTrain::getEnableDriveTrain()
{
    return mEnable;
}