// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeOut.h"

IntakeOut::IntakeOut(SubIntake *iSubIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mIntake = iSubIntake;
  AddRequirements(mIntake);
}

// Called when the command is initially scheduled.
void IntakeOut::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeOut::Execute() {
  if (!mIntake->getRotation()) {
    mIntake->ChangeRotation();
  }
  if (i == 0) {
    mIntake->Start();
  }
  i++;
      std::cout << "start" << std::endl;

}

// Called once the command ends or is interrupted.
void IntakeOut::End(bool interrupted) {
  mIntake->Stop();
}

// Returns true when the command should end.
bool IntakeOut::IsFinished() {
return (i == CommandConstants::kIterationsGoal);
}

//50 iterations pour 1s car 1s/20ms = 50