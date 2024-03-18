
 #include <frc/drive/MecanumDrive.h>
 
 #include "commands/GoToTag.h"
 #include "commands/TurnRight.h"

 TurnRight::TurnRight(SubDriveTrain *iDriveTrain, SubIMU *iIMU) 
 {
   mDriveTrain = iDriveTrain;
   mIMU = iIMU;
   AddRequirements(mDriveTrain);
   AddRequirements(mIMU);

  
 }
  
 void TurnRight::Initialize() 
 {
  angleDebut = mIMU->getAngleYaw();
  // mDriveTrain->setEnableDriveTrain(false);
 }


 void TurnRight::Execute()
 {
    mDriveTrain->mecanumDrive(0, 0, 0.8, mIMU->getRotation2d());
 }

 void TurnRight::End(bool interrupted) 
 {
  // mDriveTrain->setEnableDriveTrain(true);
 }

 bool TurnRight::IsFinished() 
 {
   return (mIMU->getAngleYaw()-angleDebut) > 72;
 }