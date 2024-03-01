// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "commands/GoToTag.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html

GoToTag::GoToTag(SubDriveTrain *iDriveTrain)
    // : CommandHelper{frc2::PIDController{0.001, 0, 0},
    //                 // This should return the measurement
    //                 [] { return LimelightHelpers::getTX(""); },
    //                 // This should return the setpoint (can also be a constant)
    //                 [] { return 0; },
    //                 // This uses the output
    //                 [this](double output) {
    //                   // Use the output here
    //                   try
    //                   {
    //                     if(mDriveTrain != 0x0)
    //                     mDriveTrain->mecanumDrive(0.0F,0.0F,(float)output,frc::Rotation2d(0_rad));
    //                   }
    //                   catch(const std::exception& e)
    //                   {
    //                     std::cout << e.what() << '\n';
    //                   }
                      
    //                   Output = output;
    //                   std::cout << output << std::endl;
    //                   this->GetController().SetPID(mCoefP->GetDouble(0),mCoefI->GetDouble(0),mCoefD->GetDouble(0));
    //                 }}
                    {
                      mDriveTrain = iDriveTrain;
                      AddRequirements(mDriveTrain);
                    }

void GoToTag::Initialize() 
{
  mTimer.Start();
  mDriveTrain->setEnableDriveTrain(false);
                     
  mPIDControllerAngle.SetTolerance(0.5, 0.1);
  mPIDControllerX.SetTolerance(0.5, 0.1);
  mPIDControllerY.SetTolerance(0.5, 0.1);

  mPIDControllerAngle.SetP(0.065);
  mPIDControllerAngle.SetI(0);
  mPIDControllerAngle.SetD(0.005);

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
  OutputX = mPIDControllerX.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(0), 0) ; 
  OutputY = mPIDControllerY.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(2), SetPoint) ; 
  
  if (!(LimelightHelpers::getFiducialID() == -1))
  {
    mDriveTrain->mecanumDrive(OutputX,-OutputY,-OutputAngle);  
  } 
  std::cout << mTimer.Get().value() << std::endl;
}
// Returns true when the command should end.
 bool GoToTag::IsFinished() {
  return (mPIDControllerAngle.AtSetpoint() && mPIDControllerX.AtSetpoint() && mPIDControllerY.AtSetpoint()) || WrongTag || mTimer.Get().value() >= 3;
}

void GoToTag::End(bool interrupted) 
{
  mDriveTrain->setEnableDriveTrain(true);
}