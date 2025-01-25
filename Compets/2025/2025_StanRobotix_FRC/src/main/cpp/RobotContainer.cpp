// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/RunCommand.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  mDriveTrain = new SubDriveTrain;
  mSubPivot = new SubPivot;
  mDriveTrain->SetDefaultCommand(frc2::RunCommand(
    [this] {
    // float X = 0;
    // float Y = 0;
    // float Z = 0;

    // if (mJoystick.GetX() >= 0){
    //   X = mJoystick.GetX()*mJoystick.GetX();
    // }
    // else{
    //   X = -mJoystick.GetX()*mJoystick.GetX();
    // }
    // if (mJoystick.GetY() >= 0){
    //   Y = mJoystick.GetY()*mJoystick.GetY();
    // }
    // else{
    //   Y = -mJoystick.GetY()*mJoystick.GetY();
    // }
    // if (mJoystick.GetZ() >= 0){
    //   Z = mJoystick.GetZ()*mJoystick.GetZ();
    // }
    // else{
    //   Z = -mJoystick.GetZ()*mJoystick.GetZ();
    // }

    mDriveTrain->Drive(mJoystick.GetX(), mJoystick.GetY(), mJoystick.GetZ());
    },
    {mDriveTrain}));
  // Configure the button bindings
  ConfigureBindings();

  mIMU.resetAngle();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickButtons::PivotUpCmd);
  }).OnTrue(PivotUp(mSubPivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickButtons::PivotDownCmd);
  }).OnTrue(PivotDown(mSubPivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickButtons::SubPivotStart);
  }).OnTrue(frc2::RunCommand([this] {mSubPivot->runPivot();},{mSubPivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickButtons::SubPivotStop);
  }).OnTrue(frc2::RunCommand([this] {mSubPivot->stopPivot();},{mSubPivot}).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
