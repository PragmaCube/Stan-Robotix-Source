// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "RobotContainer.h"

RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
 
  // Configure the button bindings
  ConfigureBindings();
  mDriveTrain.setVitesse(0.7);
  mIMU.ResetAngle();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kGotoTag);
  }).OnTrue(GoToTag(&mDriveTrain).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kElevatorUp);
  // }).OnTrue(ElevatorUp(&mElevator).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kElevatorMiddle);
  // }).OnTrue(ElevatorMiddle(&mElevator).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kElevatorDown);
  // }).OnTrue(ElevatorDown(&mElevator).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kElevatorUp);
  }).OnTrue(TrapUp(&mPivot, &mElevator).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kElevatorDown);
  }).OnTrue(TrapDown(&mPivot, &mElevator).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPivotDown);
  // }).OnTrue(PivotDown(&mPivot, &mElevator).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPivotUp);;
  // }).OnTrue(PivotUp(&mPivot).ToPtr());

   frc2::Trigger([this] {
    return mJoystick.GetPOV() == 90 || mJoystick.GetPOV() == 270;
  }).OnTrue(PivotMiddle(&mPivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAmplificator);
  }).OnTrue(Amplificator(&mPivot, &mElevator).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPickup);
  }).OnTrue(Pickup(&mPivot, &mElevator).ToPtr());

  // A voir quel bouton utiliser
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kPosStorage); // 5 ou 3?
  }).OnTrue(PosStorage(&mPivot, &mElevator).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  if (LimelightHelpers::getCameraPose_TargetSpace().size() == 0)
  {
    return Automatisation(&mDriveTrain, &mIMU, &mElevator, &mPivot, &mEjector, Automatisation::ePeriodAuto::FowardSolo).ToPtr();
  }
  else
  {       
    return Automatisation(&mDriveTrain, &mIMU, &mElevator, &mPivot, &mEjector, Automatisation::ePeriodAuto::BlueAlliance).ToPtr();
  }
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

  // if (mJoystick.GetPOV() == 0)
  // {
  //   mPivot.pivotGo(-0.5);
  // }
  // if (mJoystick.GetPOV() == 180)
  // {
  //   mPivot.pivotGo(0.5);
  // }
}

void RobotContainer::MoveElevator()
{
  if (mElevator.isEnable())
  {
    if (!mJoystick.GetRawButton(JoystickBindingsConstants::kPivotUp) && !mJoystick.GetRawButton(JoystickBindingsConstants::kPivotDown))
    {
      mElevator.stopElevatorMotors();
    }
    else if (mJoystick.GetRawButton(JoystickBindingsConstants::kPivotUp))
    {
      mElevator.manualMoveElevator(0.2);
    }
    else
    {
      mElevator.manualMoveElevator(-0.2);
    }
  }
}

void RobotContainer::MoveEjector()
{
  if (!mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorIn) && !mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorOutUp))
  {
    mEjector.Stop();
  }
  else if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorIn))
  {
    mEjector.In();
  }
  else if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorOutDown) && mPivot.getEncodeurPosition() < PivotConstants::kHeightUp + 1)
  {
    mEjector.OutDown();
  }
  else if (mJoystick.GetRawButton(JoystickBindingsConstants::kEjectorOutUp))
  {
    mEjector.OutUp();
  }
}