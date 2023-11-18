// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/Spark.h>
#include "Constants.h"
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  
  void tankDrive(double leftSpeed, double rightSpeed);
  void setCoef(Coef eValueCoef);

  

  enum Coef
  {
    High, 
    Medium, 
    Low,
  };

 Coef TCoef[3] = {Low , Medium , High};
 private:

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Spark SparkAG{DriveTrainConstants::AvantGauche}; //spark avant gauche 
  frc::Spark SparkAD{DriveTrainConstants::AvantDroite}; //spark avant droite 
  frc::Spark SparkDG{DriveTrainConstants::ArriereGauche}; //spark derriere gauche 
  frc::Spark SparkDD{DriveTrainConstants::ArriereDroite}; //spark derriere droite 

  float coef;
  
  frc::MotorControllerGroup Droite{SparkAD, SparkDD};// Groupe Droite 
  frc::MotorControllerGroup Gauche{SparkAG, SparkDG};// Groupe Gauche
  frc::DifferentialDrive Drive{Gauche, Droite};//Tank drive
};








