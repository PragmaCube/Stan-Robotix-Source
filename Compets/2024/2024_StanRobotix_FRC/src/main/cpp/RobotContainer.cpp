// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "RobotContainer.h"

#include <iostream>

RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
 
  // Configure the button bindings
  ConfigureBindings();
  mIsInit=true;
  mDriveTrain.setVitesse(0.5);
  mIMU.ResetAngle();
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
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurUp);
  // }).OnTrue(AscenseurHaut(&mAscenseur).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurMiddle);
  // }).OnTrue(AscenseurMilieu(&mAscenseur).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurDown);
  // }).OnTrue(AscenseurBas(&mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurUp);
  }).OnTrue(TrapUp(&mPivot, &mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAscenseurDown);
  }).OnTrue(TrapDown(&mPivot, &mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPivotDown);
  }).OnTrue(PivotDown(&mPivot, &mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPivotUp);;
  }).OnTrue(PivotUp(&mPivot).ToPtr());

   frc2::Trigger([this] {
    return mJoystick.GetPOV() == 90 || mJoystick.GetPOV() == 270;
  }).OnTrue(PivotMiddle(&mPivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAmplificator);
  }).OnTrue(Amplificateur(&mPivot, &mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPickup);
  }).OnTrue(Pickup(&mPivot, &mAscenseur).ToPtr());

  // A voir quel bouton utiliser
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPosStorage); // 5 ou 3?
  }).OnTrue(PosStorage(&mPivot, &mAscenseur).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

void RobotContainer::Init() {}

void RobotContainer::drive() 
{
  if (mDriveTrain.getEnableDriveTrain())
  {
    mDriveTrain.mecanumDrive(mJoystick.GetX(), mJoystick.GetY(), mJoystick.GetZ(), mIMU.getRotation2d());
  }

  if (mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kImuReset))
  {
    mIMU.ResetAngle();
  }
}

void RobotContainer::MoveAscenseur()
{
  if (mAscenseur.isEnable())
  {
    if (!mJoystick.GetRawButton(JoystickBindingsConstants::kAscenseurUp) && !mJoystick.GetRawButton(JoystickBindingsConstants::kAscenseurDown))
    {
      mAscenseur.stopAscenseurMotors();
    }
    else if (mJoystick.GetRawButton(JoystickBindingsConstants::kAscenseurUp))
    {
      mAscenseur.bougeAscenseur(1);
    }
    else
    {
      mAscenseur.bougeAscenseur(-1);
    }
  }
}

void RobotContainer::MoveEjector()
{
  if (!mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorIn) && !mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorOutDown))
  {
    mEjector.Stop();
  }
  else if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorIn))
  {
    mEjector.In();
  }
  else if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorOutDown) && mPivot.getEncodeurPosition() < PivotConstants::kHeightUp + 0.1)
  {
    mEjector.OutUp();
  }
  else if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorOutUp))
  {
    mEjector.OutDown();
  }
}