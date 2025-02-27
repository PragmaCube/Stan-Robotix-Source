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
  mIMU = new SubIMU;
  mSubAlgaeIntake = new SubAlgaeIntake;
  mSubCoralPivot = new SubCoralPivot;
  mSubCoralIntake = new SubCoralIntake;
  mJoystick = new frc::Joystick{0};

mDriveTrain->SetDefaultCommand(frc2::RunCommand(
    [this] {
    mDriveTrain->Drive(-mJoystick->GetX(), -mJoystick->GetY(), -mJoystick->GetZ());
    },
    {mDriveTrain}));

  ConfigureBindings();

  mIMU->resetAngle();

  frc::SmartDashboard::PutNumber("SetPointDown", 0.2274);
  frc::SmartDashboard::PutNumber("SetPointUp", -0.2274);
  frc::SmartDashboard::PutNumber("SetPointDownCoral", 0.2274);
  frc::SmartDashboard::PutNumber("SetPointUpCoral", -0.2274);
  frc::SmartDashboard::PutNumber("kP", 0);
  frc::SmartDashboard::PutNumber("kI", 0);
  frc::SmartDashboard::PutNumber("kD", 0);
  frc::SmartDashboard::PutNumber("kG", 0.19);
  frc::SmartDashboard::PutNumber("kGCoral", 0.19);
}


void RobotContainer::periodic(){}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
  
  // frc2::Trigger([this] {
  //   return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kResetIMU);
  // }).OnTrue(frc2::RunCommand([this] {mIMU->resetAngle();},{mIMU}).ToPtr());  

   frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(12);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->StayStill();},{mSubAlgaePivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::kClimb);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->Climb();},{mSubAlgaePivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kManualIn);
  }).OnTrue(CoralIntake(mSubCoralIntake, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kManualOut);
  }).OnTrue(CoralOuttake(mSubCoralIntake, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kManualIn);
  }).OnTrue(AlgaeIntakeIn(mSubAlgaeIntake, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kManualOut);
  }).OnTrue(AlgaeIntakeOut(mSubAlgaeIntake, mJoystick).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotUp);
  }).OnTrue(AlgaePivotUp(mSubAlgaePivot).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotDown);
  }).OnTrue(AlgaePivotDown(mSubAlgaePivot).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotUp);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralPivot->Pivot(-1.15);},{mSubCoralPivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotDown);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralPivot->Pivot(-0.1);},{mSubCoralPivot}).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotStop);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralPivot->Stop();},{mSubCoralPivot}).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick->GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotStop);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->Stop();},{mSubAlgaePivot}).ToPtr());
  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
