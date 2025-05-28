// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/drive/MecanumDrive.h>

SubDriveTrain::SubDriveTrain()
{
    mMotor4 = new ctre::phoenix::motorcontrol::can::WPI_TalonSRX (DrivingConstants::motor4port);
    mMotor2 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX (DrivingConstants::motor2port);
    mMotor3 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX (DrivingConstants::motor3port);
    mMotor1 = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX (DrivingConstants::motor1port);

     mMotor4->SetInverted(true);        // Le filage est inverse pour ce moteur dans le robot.
     mMotor3->SetInverted(true); 

    mDrive = new frc::MecanumDrive(*mMotor1, *mMotor2, *mMotor3, *mMotor4);    
};

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}   

 void SubDriveTrain::drive(const double iX, const double iY, const double iZ, const frc::Rotation2d iRotate) {
     mDrive->DriveCartesian(-iY * 0.4, iX * 0.4, (iZ - 0.44) * 0.4, iRotate);
}


