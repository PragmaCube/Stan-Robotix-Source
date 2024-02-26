
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
  mPIDController.SetPID(0.065 , 0 , 0.065);
 }


 void TurnRight::Execute()
 {
    mDriveTrain->mecanumDrive(0, 0, mPIDController.Calculate(mIMU->getAngleYaw()), mIMU->getRotation2d());
 }

 void TurnRight::End(bool interrupted) {}

 bool TurnRight::IsFinished() 
 {
   return mPIDController.AtSetpoint();
 }
