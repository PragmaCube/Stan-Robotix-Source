// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeIn.h"
#include <iostream>

IntakeIn::IntakeIn(SubIntake *iSubIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  mIntake = iSubIntake;
  AddRequirements(mIntake);
  std::cout << "Coucou Constructeur" << std::endl;
}

// Called when the command is initially scheduled.
void IntakeIn::Initialize() {
  i = 0;
  std::cout << "Coucou Initialize" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void IntakeIn::Execute() {
  mIntake->Start();
  i++;
      std::cout << "start" << std::endl;

}

// Called once the command ends or is interrupted.
void IntakeIn::End(bool interrupted) {
  mIntake->Stop();
  std::cout << "Coucou End" << std::endl;
}

// Returns true when the command should end.
bool IntakeIn::IsFinished() {
  return (i == CommandConstants::kIterationsGoal);
}