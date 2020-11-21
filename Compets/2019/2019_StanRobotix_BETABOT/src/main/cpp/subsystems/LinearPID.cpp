/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/LinearPID.h"

#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Robot.h"

LinearPID::LinearPID(double targetDist)
    : PIDSubsystem("LinearPID", 0.1, 0.1, 0.1) {
    SetSetpoint(targetDist);
    SetOutputRange(-0.8,0.8);
    SetAbsoluteTolerance(1);
    Enable();  
  // Use these to get going:
  // SetSetpoint() -  Sets where the PID controller should move the system
  //                  to
  // Enable() - Enables the PID controller.
}

double LinearPID::ReturnPIDInput() {
  // Return your input value for the PID loop
  // e.g. a sensor, like a potentiometer:
  // yourPot->SetAverageVoltage() / kYourMaxVoltage;
  return Robot::m_senseurs.GetDist();
}

void LinearPID::UsePIDOutput(double output) {
  mOutput = output;
  // Use output to drive your system, like a motor
  // e.g. yourMotor->Set(output);
}

double LinearPID::ReturnPIDOutput()
{
  return mOutput;
}

void LinearPID::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
