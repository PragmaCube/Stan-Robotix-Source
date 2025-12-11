// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnRight.h"

TurnRight::TurnRight(Drivetrain* iDriveTrain, IMU* imu) 
{
  // Use addRequirements() here to declare subsystem dependencies.
  mDrivetrain = new Drivetrain;
  mIMU = new IMU;
  AddRequirements(mDrivetrain);
  AddRequirements(imu);

}

// Called when the command is initially scheduled.
void TurnRight::Initialize() 
{
  StartingAngle = mIMU->GetAngle();
  mPIDcontroller.SetSetpoint;

// Called repeatedly when this Command is scheduled to run
void TurnRight::Execute() 
{
  mDrivetrain->TankDrive (0.0, 0.8);
}

// Called once the command ends or is interrupted.
void TurnRight::End(bool interrupted) {}

// Returns true when the command should end.
bool TurnRight::IsFinished() 
{
  return (mIMU->GetAngle() - StartingAngle) > PIDConstants::SetPoint;
}

void frc::PIDController::SetSetpoint(double setpoint)
{
  setpoint = PIDConstants::SetPoint;
}

bool frc::PIDController::AtSetpoint()
{

}
