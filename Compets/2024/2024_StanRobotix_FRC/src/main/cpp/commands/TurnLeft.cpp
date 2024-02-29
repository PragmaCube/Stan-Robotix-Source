

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
  angleDebut = mIMU->getAngleYaw();
  mDriveTrain->setEnableDriveTrain(false);
  mPIDController.SetSetpoint(-90);
  mPIDController.SetPID(0.065 , 0 , 0.065);
 }


 void TurnLeft::Execute()
 {
    mDriveTrain->mecanumDrive(0, 0, -0.7, mIMU->getRotation2d());
 }

 void TurnLeft::End(bool interrupted) 
 {
  mDriveTrain->setEnableDriveTrain(true);
 }

 bool TurnLeft::IsFinished() 
 {
  return (mIMU->getAngleYaw()-angleDebut) < -80;
 }
