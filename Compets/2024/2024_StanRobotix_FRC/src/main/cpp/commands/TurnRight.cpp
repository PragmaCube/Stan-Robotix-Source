
 #include "commands/TurnRight.h"
 #include <frc/drive/MecanumDrive.h>
 #include "commands/GoToTag.h"

 TurnRight::TurnRight(SubDriveTrain *iDriveTrain, SubIMU *iIMU) 
 {
   mDriveTrain = iDriveTrain;
   mIMU = iIMU;
   AddRequirements(mDriveTrain);
   AddRequirements(mIMU);

  
 }
  
 void TurnRight::Initialize() 
 {
  mPIDController.SetSetpoint(-90);

 mCoefP = frc::Shuffleboard::GetTab("TurnRight")
                                                 .Add("CoefP", DrivePIDConstants::kTurnP)
                                                 .WithWidget(frc::BuiltInWidgets::kTextView)
                                                 .GetEntry();

 mCoefI = frc::Shuffleboard::GetTab("TurnRight")
                                                 .Add("CoefI", DrivePIDConstants::kTurnI)
                                                 .WithWidget(frc::BuiltInWidgets::kTextView)
                                                 .GetEntry();

 mCoefD = frc::Shuffleboard::GetTab("TurnRight")
                                                 .Add("CoefD", DrivePIDConstants::kTurnD)
                                                 .WithWidget(frc::BuiltInWidgets::kTextView)
                                                 .GetEntry();
 }


 void TurnRight::Execute()
 {
    mDriveTrain->mecanumDrive(0, 0, mPIDController.Calculate(mIMU->getAngleYaw()), mIMU->getRotation2d());
    mPIDController.SetPID(mCoefP->GetDouble(DrivePIDConstants::kTurnP),mCoefI->GetDouble(DrivePIDConstants::kTurnI),mCoefD->GetDouble(DrivePIDConstants::kTurnD));
 }

 void TurnRight::End(bool interrupted) 
 {

 }

 bool TurnRight::IsFinished() {
   if (mPIDController.AtSetpoint())
   {
     return true;
   }
 return false;
 }
