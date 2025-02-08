// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GoToTag.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html

GoToTag::GoToTag(SubDriveTrain *iDriveTrain, SubIMU *iIMU)
{
  mDriveTrain = iDriveTrain;
  mIMU = iIMU;
  AddRequirements(mDriveTrain);
  AddRequirements(mIMU);
}

void GoToTag::Initialize() 
{
  AngleP = frc::SmartDashboard::GetNumber("AngleP", AngleP);
  AngleI = frc::SmartDashboard::GetNumber("AngleI", AngleI);
  AngleD = frc::SmartDashboard::GetNumber("AngleD", AngleD);

  mTimer.Start();
  mTimer.Reset();
  mDriveTrain->setEnableDriveTrain(false);
                     
  mPIDControllerAngle.SetTolerance(0.5, 0.1);
  mPIDControllerX.SetTolerance(0.5, 0.1);
  mPIDControllerY.SetTolerance(0.5, 0.1);

  mPIDControllerAngle.SetP(AngleP);
  mPIDControllerAngle.SetI(AngleI);
  mPIDControllerAngle.SetD(AngleD);

  mPIDControllerX.SetP(1.3);
  mPIDControllerX.SetI(0.05);
  mPIDControllerX.SetD(0.05);

  mPIDControllerY.SetP(1.6);
  mPIDControllerY.SetI(0.03);
  mPIDControllerY.SetD(0.005);

  if (LimelightHelpers::getFiducialID() == 1 || LimelightHelpers::getFiducialID() == 2 || LimelightHelpers::getFiducialID() == 10 || LimelightHelpers::getFiducialID() == 9)
  { // Source
    SetPoint = -1.5;
    WrongTag = false;
  }
  else if (LimelightHelpers::getFiducialID() == 6 || LimelightHelpers::getFiducialID() == 5)
  { // Amplficateur
    SetPoint = -0.5;
    WrongTag = false;
  }
  else
  { // Speacker ou Trap
    WrongTag = true;
  }
}

void GoToTag::Execute() 
{ 
  OutputAngle = mPIDControllerAngle.Calculate(LimelightHelpers::getTX(""), 0) ; 
  std::cout << LimelightHelpers::getTX("") << std::endl;
  OutputX = mPIDControllerX.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(0), 0) ; 
  OutputY = mPIDControllerY.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(2), 3) ; 
  
  if (!(LimelightHelpers::getFiducialID() == -1))
  {
    mDriveTrain->drive(OutputX, 0,-OutputAngle, mIMU->getRotation2d());  

  } 
}

// Returns true when the command should end.
 bool GoToTag::IsFinished() {
  return (mPIDControllerAngle.AtSetpoint() && mPIDControllerX.AtSetpoint() && mPIDControllerY.AtSetpoint()) || WrongTag || mDriveTrain->getEnableDriveTrain(); // || mTimer.Get().value() >= 3
}

void GoToTag::End(bool interrupted) 
{
  mDriveTrain->setEnableDriveTrain(true);
}