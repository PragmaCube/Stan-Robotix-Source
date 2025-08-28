// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

// #include "commands/AlgaePivotState.h"

// AlgaePivotState::AlgaePivotState(SubAlgaePivot * iSubAlgaePivot, SubCoralPivot * iSubCoralPivot, SubAlgaePivot::StatesAlgae iState) {
//   // Use addRequirements() here to declare subsystem dependencies.
//   mSubCoralPivot = iSubCoralPivot;
//   mSubAlgaePivot = iSubAlgaePivot;
//   AddRequirements(mSubCoralPivot); 
//   AddRequirements(mSubAlgaePivot);
//   mState = iState;
// }

// // Called when the command is initially scheduled.
// void AlgaePivotState::Initialize() {
//   switch (mState)
// {
// case SubAlgaePivot::StatesAlgae::horizontale:
//   mSubAlgaePivot->Pivot(0.2);
//   mSubAlgaePivot->SetState(SubAlgaePivot::StatesAlgae::horizontale);
//   break;

// case SubAlgaePivot::StatesAlgae::cage:
//   mSubAlgaePivot->Pivot(0.2);
//   mSubAlgaePivot->SetState(SubAlgaePivot::StatesAlgae::cage);
//   break;

// case SubAlgaePivot::StatesAlgae::pickAlgae:
//   mSubAlgaePivot->Pivot(0.2);
//   mSubAlgaePivot->SetState(SubAlgaePivot::StatesAlgae::pickAlgae);
//   break;

// case SubAlgaePivot::StatesAlgae::replié:
//   if ((!mSubCoralPivot->GetState()) == SubCoralPivot::StatesCoral::replié) {
//   mSubAlgaePivot->Pivot(0.2);
//   mSubAlgaePivot->SetState(SubAlgaePivot::StatesAlgae::replié);
//   }
//   break;

// default:
//   break;
// }
// }

// // Called repeatedly when this Command is scheduled to run
// void AlgaePivotState::Execute() {}

// // Called once the command ends or is interrupted.
// void AlgaePivotState::End(bool interrupted) {}

// // Returns true when the command should end.
// bool AlgaePivotState::IsFinished() {
//   return false;
// }
