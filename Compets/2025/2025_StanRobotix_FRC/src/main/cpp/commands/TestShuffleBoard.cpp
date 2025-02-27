// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TestShuffleBoard.h"

TestShuffleBoard::TestShuffleBoard() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TestShuffleBoard::Initialize() {
i = 0;
}

// Called repeatedly when this Command is scheduled to run
void TestShuffleBoard::Execute() {
  i++;
}

// Called once the command ends or is interrupted.
void TestShuffleBoard::End(bool interrupted) {
  i = 0;
}

// Returns true when the command should end.
bool TestShuffleBoard::IsFinished() {
  return i = 50;
}
