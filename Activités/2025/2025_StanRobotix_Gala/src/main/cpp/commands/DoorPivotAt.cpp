// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DoorPivotAt.h"

DoorPivotAt::DoorPivotAt(SubDoor *iDoor, SubDoor::Positions iPosition)
{
  mPosition = iPosition;
  mDoor = iDoor;
  AddRequirements(mDoor);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void DoorPivotAt::Initialize()
{
  switch (mPosition)
  {
    case SubDoor::Positions::Open:
      mSetpoint = DoorConstants::Positions::kOpen;
      break;
    case SubDoor::Positions::Close:
      mSetpoint = DoorConstants::Positions::kClose;
      break;
  }
  mPID = new frc::PIDController{DoorConstants::kP, DoorConstants::kI, DoorConstants::kD};
  mPID->SetTolerance(0.05);
}

// Called repeatedly when this Command is scheduled to run
void DoorPivotAt::Execute()
{
  mPID->SetSetpoint(mSetpoint);
  double pivotAngle = mDoor->GetAngle();
  double Output = mPID->Calculate(pivotAngle) * 13;

  mDoor->SetVoltage(units::volt_t(DoorConstants::kG * cos(pivotAngle)) + units::volt_t(Output));
}

// Called once the command ends or is interrupted.
void DoorPivotAt::End(bool interrupted) {
  mDoor->Stop();
}

// Returns true when the command should end.
bool DoorPivotAt::IsFinished()
{
  return mPID->AtSetpoint();
}
