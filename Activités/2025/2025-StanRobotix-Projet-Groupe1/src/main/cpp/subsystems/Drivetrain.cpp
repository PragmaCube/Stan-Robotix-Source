// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "Constants.h"


Drivetrain::Drivetrain(){
    mMoteurADroite= new ctre::phoenix::motorcontrol::can::WPI_TalonSRX (DriveConstants::kPortMoteurADroite); 
    mMoteurDDroite= new ctre::phoenix::motorcontrol::can::WPI_TalonSRX (DriveConstants::kPortMoteurDDroite); 
    mMoteurAGauche= new ctre::phoenix::motorcontrol::can::WPI_TalonSRX (DriveConstants::kPortMoteurAGauche); 
    mMoteurDGauche= new ctre::phoenix::motorcontrol::can::WPI_TalonSRX (DriveConstants::kPortMoteurDGauche);

    Droite= new frc::MotorControllerGroup(*mMoteurADroite, *mMoteurDDroite);
    Gauche= new frc::MotorControllerGroup(*mMoteurAGauche, *mMoteurDGauche);
    DifferentialDrive= new frc::DifferentialDrive(*Droite, *Gauche);
}

// This method will be called once per scheduler runn
void Drivetrain::Periodic() {}

void Drivetrain::tankDrive(double leftSpeed, double rightSpeed) 
{
   DifferentialDrive->TankDrive(-leftSpeed, rightSpeed);
}
