

 #include "commands/TurnLeft.h"
 #include <frc/drive/MecanumDrive.h>
 #include "commands/GoToTag.h"

 TurnLeft::TurnLeft(SubDriveTrain *iDriveTrain, SubIMU *iIMU) 
 {
   mDriveTrain = iDriveTrain;
   mIMU = iIMU;
   AddRequirements(mDriveTrain);
   AddRequirements(mIMU);

  
 }
  
 void TurnLeft::Initialize() 
 {
  mPIDController.SetSetpoint(90);

  //  mCoefP = frc::Shuffleboard::GetTab("TurnLeft")
  //                                                  .Add("CoefP", DrivePIDConstants::kTurnP)
  //                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
  //                                                  .GetEntry();

  //  mCoefI = frc::Shuffleboard::GetTab("TurnLeft")
  //                                                  .Add("CoefI", DrivePIDConstants::kTurnI)
  //                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
  //                                                  .GetEntry();

  //  mCoefD = frc::Shuffleboard::GetTab("TurnLeft")
  //                                                  .Add("CoefD", DrivePIDConstants::kTurnD)
  //                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
  //                                                  .GetEntry();
 }


 void TurnLeft::Execute()
 {
    mDriveTrain->mecanumDrive(0, 0, mPIDController.Calculate(mIMU->getAngleYaw()), mIMU->getRotation2d());
    mPIDController.SetPID(mCoefP->GetDouble(DrivePIDConstants::kTurnP),mCoefI->GetDouble(DrivePIDConstants::kTurnI),mCoefD->GetDouble(DrivePIDConstants::kTurnD));
 }

 void TurnLeft::End(bool interrupted) 
 {

 }

 bool TurnLeft::IsFinished() {
   if (mPIDController.AtSetpoint())
   {
     return true;
   }
 return false;
 }
