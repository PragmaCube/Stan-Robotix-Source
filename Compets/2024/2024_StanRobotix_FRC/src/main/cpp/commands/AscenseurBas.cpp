// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AscenseurBas.h"

AscenseurBas::AscenseurBas(SubAscenseur *iAscenseur) {

  mAscenseur = iAscenseur;
  AddRequirements(mAscenseur);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AscenseurBas::Initialize() 
{
  mAscenseur->setEnable(false);
  mAscenseur->setPositionVoulue(AscenseurConstants::kAscenseurLimitDown);
}

// Called repeatedly when this Command is scheduled to run
void AscenseurBas::Execute() 
{
  mAscenseur->setPositionAscenseur(mAscenseur->getPositionVoulue());
}

// Called once the command ends or is interrupted.
void AscenseurBas::End(bool interrupted) 
{
  mAscenseur->setEnable(true);
}

// Returns true when the command should end.
bool AscenseurBas::IsFinished() 
{
  return (std::abs(mAscenseur->getEncoderPositionMotor1() - mAscenseur->getPositionVoulue()) < 0.05 &&
         std::abs(mAscenseur->getEncoderPositionMotor2() - mAscenseur->getPositionVoulue()) < 0.05 &&
         std::abs(mAscenseur->getVelocityMotor1()) < 0.05 &&
         std::abs(mAscenseur->getVelocityMotor2()) < 0.05);
//        (std::abs(mPivot->getEncodeurPosition() - PivotConstants::kHeightDown) < 0.05);
}