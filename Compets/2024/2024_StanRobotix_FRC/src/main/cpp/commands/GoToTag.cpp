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
  mDriveTrain->setEnableDriveTrain(false);
}

void GoToTag::Execute() 
{
                      mCoefP = frc::Shuffleboard::GetTab("GoToTag")
                                                  .Add("CoefP", 42)
                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
                                                  .GetEntry();

                      mCoefI = frc::Shuffleboard::GetTab("GoToTag")
                                                  .Add("CoefI", 0)
                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
                                                  .GetEntry();

                      mCoefD = frc::Shuffleboard::GetTab("GoToTag")
                                                  .Add("CoefD", 0)
                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
                                                  .GetEntry();
                      frc::Shuffleboard::GetTab("GoToTag").Add("Debug", 1.0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();
  mPIDController.SetP(mCoefP->GetDouble(42));
  mPIDController.SetI(mCoefI->GetDouble(0));
  mPIDController.SetD(mCoefD->GetDouble(0));
  Output = mPIDController.Calculate(LimelightHelpers::getTX(""), 0) ; 
  std::cout<< Output << std::endl; 
  mDriveTrain->mecanumDrive(0.0F,0.0F,-Output,frc::Rotation2d(0_rad));
}
// Returns true when the command should end.
 bool GoToTag::IsFinished() {
  return mPIDController.AtSetpoint();
}

void GoToTag::End(bool interrupted) 
{
  mDriveTrain->setEnableDriveTrain(true);
}