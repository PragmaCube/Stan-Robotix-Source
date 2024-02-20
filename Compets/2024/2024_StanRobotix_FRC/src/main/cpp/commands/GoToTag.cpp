// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "commands/GoToTag.h"

#include <cmath>

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
                     
  mPIDControllerAngle.SetTolerance(1, 0.1);
  mPIDControllerX.SetTolerance(1, 0.1);
  mPIDControllerY.SetTolerance(1, 0.1);

                      // mCoefPAngle = frc::Shuffleboard::GetTab("GoToTag")
                      //                             .Add("CoefPAngle", 42)
                      //                             .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                             .GetEntry();

                      // mCoefIAngle = frc::Shuffleboard::GetTab("GoToTag")
                      //                             .Add("CoefIAngle", 0)
                      //                             .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                             .GetEntry();

                      // mCoefDAngle = frc::Shuffleboard::GetTab("GoToTag")
                      //                             .Add("CoefDAngle", 0)
                      //                             .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                             .GetEntry();
                      // frc::Shuffleboard::GetTab("GoToTag").Add("Debug", 1.0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();


                      //   mCoefPX = frc::Shuffleboard::GetTab("GoToTag")
                      //                               .Add("CoefPX", 42)
                      //                               .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                               .GetEntry();

                      //   mCoefIX = frc::Shuffleboard::GetTab("GoToTag")
                      //                               .Add("CoefIX", 0)
                      //                               .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                               .GetEntry();

                      //   mCoefDX = frc::Shuffleboard::GetTab("GoToTag")
                      //                               .Add("CoefDX", 0)
                      //                               .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                               .GetEntry();
                      //   frc::Shuffleboard::GetTab("GoToTag").Add("Debug", 1.0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();


                      //     mCoefPY = frc::Shuffleboard::GetTab("GoToTag")
                      //                               .Add("CoefPY", 42)
                      //                               .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                               .GetEntry();

                      //     mCoefIY = frc::Shuffleboard::GetTab("GoToTag")
                      //                               .Add("CoefIY", 0)
                      //                               .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                               .GetEntry();

                      //     mCoefDY = frc::Shuffleboard::GetTab("GoToTag")
                      //                               .Add("CoefDY", 0)
                      //                               .WithWidget(frc::BuiltInWidgets::kTextView)
                      //                               .GetEntry();
                      //   frc::Shuffleboard::GetTab("GoToTag").Add("Debug", 1.0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();


  mPIDControllerAngle.SetP(0.065);
  mPIDControllerAngle.SetI(0);
  mPIDControllerAngle.SetD(0.005);

  mPIDControllerX.SetP(1.3);
  mPIDControllerX.SetI(0);
  mPIDControllerX.SetD(0);

  mPIDControllerY.SetP(1.6);
  mPIDControllerY.SetI(0);
  mPIDControllerY.SetD(0.005);
  // std::cout<< Output << std::endl; 
}

void GoToTag::Execute() 
{ 
  OutputAngle = mPIDControllerAngle.Calculate(LimelightHelpers::getTX(""), 0) ; 
  OutputX = mPIDControllerX.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(0), 0) ; 
  OutputY = mPIDControllerY.Calculate(LimelightHelpers::getCameraPose_TargetSpace().at(2), -1) ; 
// std::cout << LimelightHelpers::getCameraPose_TargetSpace().at(2) <<std::endl;
  // std::cout << mPIDController.GetP() << std::endl;
  // std::cout<< Output << std::endl; 
  mDriveTrain->mecanumDrive(OutputX,-OutputY,-OutputAngle,frc::Rotation2d(0_rad));  
}
// Returns true when the command should end.
 bool GoToTag::IsFinished() {
  return mPIDControllerAngle.AtSetpoint() && mPIDControllerX.AtSetpoint() && mPIDControllerY.AtSetpoint();
}

void GoToTag::End(bool interrupted) 
{
  mDriveTrain->setEnableDriveTrain(true);
}