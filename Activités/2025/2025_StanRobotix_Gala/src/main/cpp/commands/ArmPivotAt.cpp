// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ArmPivotAt.h"

ArmsPivotAt::ArmsPivotAt(SubArms *iArms, SubArms::Positions iPositionLeft, SubArms::Positions iPositionRight)
{
  mPositionRight = iPositionRight;
  mPositionLeft = iPositionLeft;
  mArms = iArms;
  AddRequirements(mArms);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ArmsPivotAt::Initialize()
{
  switch (mPositionRight)
  {
    case SubArms::Positions::Up:
      mSetpointRight = ArmsConstants::Positions::kUp;
      break;
    case SubArms::Positions::Down:
      mSetpointRight = ArmsConstants::Positions::kDown;
      break;
  }
  switch (mPositionLeft)
  {
    case SubArms::Positions::Up:
      mSetpointLeft = ArmsConstants::Positions::kUp;
      break;
    case SubArms::Positions::Down:
      mSetpointLeft = ArmsConstants::Positions::kDown;
      break;
  }
  mPIDRight = new frc::PIDController{ArmsConstants::kP, ArmsConstants::kI, ArmsConstants::kD};
  mPIDLeft = new frc::PIDController{ArmsConstants::kP, ArmsConstants::kI, ArmsConstants::kD};
  mPIDRight->SetTolerance(0.05);
  mPIDLeft->SetTolerance(0.05);
}

// Called repeatedly when this Command is scheduled to run
void ArmsPivotAt::Execute()
{
  mPIDRight->SetSetpoint(mSetpointRight);
  double pivotAngleRight = mArms->GetAngleRight();
  double OutputRight = mPIDRight->Calculate(pivotAngleRight) * 13;

  mArms->SetVoltageRight(units::volt_t(ArmsConstants::kG * cos(pivotAngleRight)) + units::volt_t(OutputRight));
  
  mPIDLeft->SetSetpoint(mSetpointLeft);
  double pivotAngleLeft = mArms->GetAngleLeft();
  double OutputLeft = mPIDLeft->Calculate(pivotAngleLeft) * 13;

  mArms->SetVoltageLeft(units::volt_t(ArmsConstants::kG * cos(pivotAngleLeft)) + units::volt_t(OutputLeft));
}

// Called once the command ends or is interrupted.
void ArmsPivotAt::End(bool interrupted) {
  mArms->Stop();
}

// Returns true when the command should end.
bool ArmsPivotAt::IsFinished()
{
  return mPIDLeft->AtSetpoint() && mPIDRight->AtSetpoint();
}
