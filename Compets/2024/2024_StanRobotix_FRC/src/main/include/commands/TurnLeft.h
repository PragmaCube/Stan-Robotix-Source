
 #pragma once
 #include <frc/controller/PIDController.h>
 #include <frc2/command/Command.h>
 #include <frc2/command/CommandHelper.h>
 #include "subsystems/SubDriveTrain.h"
 #include "subsystems/SubIMU.h"
 #include "RobotContainer.h"
 #include "Constants.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/GenericEntry.h>
#include <frc/shuffleboard/BuiltInWidgets.h>
 /**
  * An example command.
  *
  * <p>Note that this extends CommandHelper, rather extending Command
  * directly; this is crucially important, or else the decorator functions in
  * Command will *not* work!
  */
 class TurnLeft
     : public frc2::CommandHelper<frc2::Command, TurnLeft> {
  public:
   TurnLeft(SubDriveTrain* iDriveTrain, SubIMU* iIMU);

   void Initialize() override;

   void Execute() override;

   void End(bool interrupted) override;

   bool IsFinished() override;

  private:
    
     SubDriveTrain* mDriveTrain;
     SubIMU* mIMU;

     frc::PIDController mPIDController {DrivePIDConstants::kTurnP, DrivePIDConstants::kTurnI, DrivePIDConstants::kTurnD};
     double Output;
 
  nt::GenericEntry* mCoefP = nullptr;
  nt::GenericEntry* mCoefI = nullptr;
  nt::GenericEntry* mCoefD = nullptr;
 };