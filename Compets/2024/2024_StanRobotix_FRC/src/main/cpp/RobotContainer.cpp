// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "RobotContainer.h"



RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
 
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());


  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kGotoTag);
  }).OnTrue(GoToTag(&mDriveTrain).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(2) ;
  // }).OnTrue(TurnLeft(&mDriveTrain, &mIMU).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurUp);
  }).OnTrue(AscenseurHaut(&mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurMiddle);
  }).OnTrue(AscenseurMilieu(&mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurDown);
  }).OnTrue(AscenseurBas(&mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetPOV() == 180;
  }).OnTrue(PivotDown(&mPivot, &mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetPOV() == 0;
  }).OnTrue(PivotUp(&mPivot).ToPtr());

   frc2::Trigger([this] {
    return mJoystick.GetPOV() == 90 || mJoystick.GetPOV() == 270;
  }).OnTrue(PivotMiddle(&mPivot).ToPtr());


  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

void RobotContainer::Init()
 {
    mIsInit=true;
 }


void RobotContainer::drive() 
{
  if (mDriveTrain.getEnableDriveTrain())
  {
    mDriveTrain.mecanumDrive(mJoystick.GetX(), mJoystick.GetY(), mJoystick.GetZ(), mIMU.getRotation2d());
    // mDriveTrain.mecanumDrive(mJoystick.GetX(), 0,0, mIMU.getRotation2d());
  }

  if (mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kImuReset))
  {
    mIMU.ResetAngle();
  }
  
  // for (int i = 0; i < LimelightHelpers::getBotpose_TargetSpace().size(); i++)
  // {
  //   std::cout << i << " : " << LimelightHelpers::getBotpose_TargetSpace().at(i) << std::endl;
  // }
  // std::cout << " : " << LimelightHelpers::getCameraPose_TargetSpace().size() << std::endl;
}

void RobotContainer::MoveAscenseur()
{
  if (mAscenseur.isEnable())
  {
    if (mJoystick.GetRawButton(JoystickBindingsConstants::kAscenseurManualUp))
    {
      mAscenseur.bougeAscenseur(0.5);
    }
    else if (mJoystick.GetRawButton(JoystickBindingsConstants::kAscenseurManualDown))
    {
      mAscenseur.bougeAscenseur(-0.5);
    }
    else
    {
      mAscenseur.stopAscenseurMotors();
    }
  }
}

void RobotContainer::MovePivot()
{
  if (mPivot.isEnable())
  {
    if (mJoystick.GetRawButton(JoystickBindingsConstants::kPivotManualUp))
    {
      mPivot.pivotGo(-0.1);
    }
    else if (mJoystick.GetRawButton(JoystickBindingsConstants::kPivotManualDown))
    {
      mPivot.pivotGo(0.1);
    }
  }
}

void RobotContainer::MoveEjector()
{
  if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorIn))
  {
    mEjector.In(-(mJoystick.GetRawAxis(4)-1/2));
  }
  else if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorOut))
  {
    mEjector.Out(-(mJoystick.GetRawAxis(4)-1/2));
  }
  else
  {
    mEjector.Stop();
  }
}