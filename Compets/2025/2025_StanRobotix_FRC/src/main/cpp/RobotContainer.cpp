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
  mSubAlgaePivot = new SubAlgaePivot;
  mSubAlgaeIntake = new SubAlgaeIntake;
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
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaeIntakeInCmd);
  }).OnTrue(AlgaeIntakeIn(mSubAlgaeIntake).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaeIntakeOutCmd);
  }).OnTrue(AlgaeIntakeOut(mSubAlgaeIntake).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaeIntakeManualIn);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaeIntake->AlgaeIntake();},{mSubAlgaeIntake}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaeIntakeManualOut);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaeIntake->AlgaeOutake();},{mSubAlgaeIntake}).ToPtr());
  
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaeIntakeStopSub);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaeIntake->AlgaeIntakeStop();},{mSubAlgaeIntake}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaePivotUpCmd);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->manualAlgaePivotReverse();},{mSubAlgaePivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaePivotDownCmd);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->manualAlgaePivot();},{mSubAlgaePivot}).ToPtr());  

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaePivotUpCmd);
  // }).OnTrue(PivotUp(mSubAlgaePivot).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaePivotDownCmd);
  // }).OnTrue(PivotDown(mSubAlgaePivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::SubAlgaePivotStop);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->stopAlgaePivot();},{mSubAlgaePivot}).ToPtr());


  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
