
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
  angleDebut = mIMU->getAngleYaw();
  // mDriveTrain->setEnableDriveTrain(false);
 }


 void TurnRight::Execute()
 {
    mDriveTrain->mecanumDrive(0, 0, 0.7, mIMU->getRotation2d());
 }

 void TurnRight::End(bool interrupted) 
 {
  // mDriveTrain->setEnableDriveTrain(true);
 }

 bool TurnRight::IsFinished() 
 {
   return (mIMU->getAngleYaw()-angleDebut) > 80;
 }