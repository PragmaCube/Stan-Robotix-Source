// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnRight.h"
#include <frc2/command/Command.h>



TurnRight::TurnRight(Drivetrain * iDrivetrain, IMUsubsystem * iIMUsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  mDrivetrain = iDrivetrain;
  mIMUsubsystem = iIMUsubsystem;
  mPIDController= new frc::PIDController(TurnRightConstants::kP,TurnRightConstants::kI,TurnRightConstants::kD);
  AddRequirements(mDrivetrain);
  AddRequirements(mIMUsubsystem);
}

// Called when the command is initially scheduled.
void TurnRight::Initialize() {
  Resultat = mIMUsubsystem->GetYawAxis();
  Resultat -= TurnRightConstants::kSetPoint;
  mPIDController->SetSetpoint(Resultat);
  std::cout << "Debut de la commande" << Resultat << std::endl ;
}

// Called repeatedly when this Command is scheduled to run
void TurnRight::Execute()
{
  std::cout << "Rotation su Axe Y : " << mIMUsubsystem->GetYawAxis() << std::endl;
  Movement= mPIDController->Calculate(mIMUsubsystem->GetYawAxis());
  mDrivetrain->tankDrive(Movement, -Movement);
}

// Called once the command ends or is interrupted.
void TurnRight::End(bool interrupted) {
  std::cout << "Fin de la commande" << std::endl;
}

// Returns true when the command should end.
bool TurnRight::IsFinished() {
  return mPIDController->AtSetpoint();
}
