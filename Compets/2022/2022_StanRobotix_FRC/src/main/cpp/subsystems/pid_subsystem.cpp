// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/pid_subsystem.h"

PidSubsystem::PidSubsystem(double kP, double kI, double kD) {
  // Implementation of subsystem constructor goes here.
  mPid = new PIDController(kP, kI, kD);
}

PidSubsystem::~PidSubsystem() {
  delete mPid;
}

void PidSubsystem:::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void PidSubsystem:::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void SetPoint(double iSetPoint)
{
  mPid->reset();
  mSetPoint = iSetPoint;
}

