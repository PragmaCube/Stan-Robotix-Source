// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShuffleboard.h"

SubShuffleboard::SubShuffleboard() {
    mTabGeneral = &frc::Shuffleboard::GetTab("Main Tab");

    //commandes
    mCmdTestShuffleBoard = &mTabGeneral->AddBoolean("mTestShuffleBoard",[this]{return mTestSuffleBoard->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
/*
    mCmdAlgaeFullIntake = &mTabGeneral->AddBoolean("mAlgaeFullIntake",[this]{return mAlgaeFullIntake->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdAlgaeIntakeIn = &mTabGeneral->AddBoolean("mAlgaeIntakeIn",[this]{return mAlgaeIntakeIn->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdAlgaeIntakeOut = &mTabGeneral->AddBoolean("mAlgaeIntakeOut",[this]{return mAlgaeIntakeOut->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdAlgaePivotDown = &mTabGeneral->AddBoolean("mAlgaePivotDown",[this]{return mAlgaePivotDown->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdAlgaePivotUp = &mTabGeneral->AddBoolean("mAlgaePivotUp",[this]{return mAlgaePivotUp->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdAutos = &mTabGeneral->AddBoolean("mAutos",[this]{return mAutos->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdClimb = &mTabGeneral->AddBoolean("mClimb",[this]{return mClimb->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdCoralIntake = &mTabGeneral->AddBoolean("mCoralIntake",[this]{return mCoralIntake->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdCoralOuttake = &mTabGeneral->AddBoolean("mCoralOuttake",[this]{return mCoralOuttake->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdCoralPivotDown = &mTabGeneral->AddBoolean("mCoralPivotDown",[this]{return mCoralPivotDown->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdCoralPivotUp = &mTabGeneral->AddBoolean("mCoralPivotUp",[this]{return mCoralPivotUp->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdGoToTag = &mTabGeneral->AddBoolean("mGoToTag",[this]{return mGoToTag->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdStopAlgaeIntake = &mTabGeneral->AddBoolean("mStopAlgaeIntake",[this]{return mStopAlgaeIntake->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
    mCmdStopCoralIntake = &mTabGeneral->AddBoolean("mStopCoralIntake",[this]{return mStopCoralIntake->IsFinished();}).WithWidget(frc::BuiltInWidgets::kBooleanBox);
*/


    //valeurs non modifiables
    NumberTestConstant = mTabGeneral->Add("turc", 0.5).WithWidget(frc::BuiltInWidgets::kDial).GetEntry();

    //valeurs modifiables
    NumberTestChangeable = mTabGeneral->Add("turc modifiable", 0.5).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();  

    //capteurs
    CameraFeed = &mTabGeneral->AddCamera("cameras","Limelight + usb",std::span<const std::string>({ "http://10.66.22.11:5800/" })).WithWidget(frc::BuiltInWidgets::kCameraStream);

    //subsystems
/*
    mSubAlgaeIntake = new SubAlgaeIntake();
    mSubAlgaePivot = new SubAlgaePivot();
    mSubCoralIntake = new SubCoralIntake();
    mSubCoralPivot = new SubCoralPivot();

    AlgaeIntakeSpeed = mTabGeneral->Add("AlgaeIntakeSpeed", SubAlgaeIntake->GetInSpeed()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    AlgaeOuttakeSpeed = mTabGeneral->Add("AlgaeOuttakeSpeed", SubAlgaeIntake->GetOuttakeSpeed()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    AlgaeSetPoint = mTabGeneral->Add("AlgaeSetPoint", SubAlgaePivot->GetSetPoint()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    AlgaekG = mTabGeneral->Add("AlgaekG", SubAlgaePivot->GetkG()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    AlgaeClimb = mTabGeneral->Add("AlgaeClimb", SubAlgaePivot->GetClimbV()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    AlgaeStayStill = mTabGeneral->Add("AlgaeStayStill", SubAlgaePivot->GetStayStill()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    CoralIntakeSpeed = mTabGeneral->Add("CoralIntakeSpeed", SubCoralIntake->GetIntakeSpeed()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    CoralOuttakeSpeed = mTabGeneral->Add("CoralOuttakeSpeed", SubCoralIntake->GetOuttakeSpeed()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    CoralPivotSetPoint = mTabGeneral->Add("CoralPivotSetPoint", SubCoralPivot->GetSetPoint()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
    CoralPivotkG = mTabGeneral->Add("CoralPivotkG", SubCoralPivot->GetkG()).WithWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry(); 
*/
}

// This method will be called once per scheduler run
void SubShuffleboard::Periodic() {
    frc::Shuffleboard::Update();
/*  mSubAlgaeIntake->SetInSpeed(AlgaeIntakeSpeed->GetDouble(0.0));
    mSubAlgaeIntake->SetOuttakeSpeed(AlgaeOuttakeSpeed->GetDouble(0.0));
    mSubAlgaePivot->SetkG(AlgaekG->GetDouble(0.0));
    mSubAlgaePivot->SetSetPoint(AlgaeSetPoint->GetDouble(0.0));
    mSubAlgaePivot->SetClimb(AlgaeClimb->GetDouble(0.0));
    mSubAlgaePivot->SetStayStill(AlgaeStayStill->GetDouble(0.0));
    mSubCoralIntake->SetOuttakeSpeed(CoralOuttakeSpeed->GetDouble(0.0));
    mSubCoralIntake->SetInSpeed(CoralIntakeSpeed->GetDouble(0.0));
    mSubCoralPivot->SetkG(CoralPivotkG->GetDouble(0.0));
    mSubCoralPivot->SetSetPoint(CoralPivotSetPoint->GetDouble(0.0));        */
}

double SubShuffleboard::GetNumberTestChangeable() {
    return NumberTestChangeable->GetDouble(0.0);
}

double SubShuffleboard::GetNumberTestConstant() {
    return NumberTestConstant->GetDouble(0.0);
}