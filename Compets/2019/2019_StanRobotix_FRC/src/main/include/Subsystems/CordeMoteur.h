/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>

#include <RobotMap.h>
#include <Spark.h>

class CordeMoteur : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  Spark* moteur;
  double cordeProg;
  double cordeMax;
  double cordeMin;
 public:
  CordeMoteur();
  void InitDefaultCommand() override;
  void Set(double value);
};
