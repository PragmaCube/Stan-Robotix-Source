// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>


class Drivetrain : public frc2::SubsystemBase {
 public:
 
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void tankDrive(double leftSpeed, double rightSpeed);


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX * mMoteurADroite = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX * mMoteurDDroite = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX * mMoteurAGauche = nullptr;
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX * mMoteurDGauche = nullptr;

  
  frc::MotorControllerGroup * Droite;// Groupe Droite 
  frc::MotorControllerGroup * Gauche;// Groupe Gauche
  frc::DifferentialDrive * Drive;//Tank drive

};

