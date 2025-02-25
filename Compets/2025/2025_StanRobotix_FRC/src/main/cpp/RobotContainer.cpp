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

    mDriveTrain->Drive(-mJoystick.GetX(), -mJoystick.GetY(), -mJoystick.GetZ());
    },
    {mDriveTrain}));
  // Configure the button bindings
  ConfigureBindings();

  mIMU->resetAngle();

  frc::SmartDashboard::PutNumber("SetPointDown", 0.2274);
  frc::SmartDashboard::PutNumber("SetPointUp", -0.2274);
  frc::SmartDashboard::PutNumber("kP", 0);
  frc::SmartDashboard::PutNumber("kI", 0);
  frc::SmartDashboard::PutNumber("kD", 0);
  frc::SmartDashboard::PutNumber("kG", 0.19);

  frc::SmartDashboard::PutNumber("SetPointDownCoral", 0.2274);
  frc::SmartDashboard::PutNumber("SetPointUpCoral", -0.2274);
  frc::SmartDashboard::PutNumber("kPCoral", 0);
  frc::SmartDashboard::PutNumber("kICoral", 0);
  frc::SmartDashboard::PutNumber("kDCoral", 0);
  frc::SmartDashboard::PutNumber("kGCoral", 0.19);
}


void RobotContainer::periodic(){
  // std::cout << double(mSubAlgaePivot->getAlgaePivotEncoderPosition()) << std::endl;
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
  
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(11);
  }).OnTrue(frc2::RunCommand([this] {mIMU->resetAngle();},{mIMU}).ToPtr());  



  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Coral::kManualIn);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralIntake->Intake();},{mSubCoralIntake}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Coral::kManualOut);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralIntake->Outtake();},{mSubCoralIntake}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kIntakeStop);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralIntake->stop();},{mSubCoralIntake}).ToPtr());



  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kManualIn);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaeIntake->Intake();},{mSubAlgaeIntake}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kManualOut);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaeIntake->Outake();},{mSubAlgaeIntake}).ToPtr());
  
  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kIntakeStop);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaeIntake->Stop();},{mSubAlgaeIntake}).ToPtr());



  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotUp);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->Pivot(frc::SmartDashboard::GetNumber("SetPointUp", -0.2274));},{mSubAlgaePivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotDown);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->Pivot(frc::SmartDashboard::GetNumber("SetPointDown", 0.2274));},{mSubAlgaePivot}).ToPtr());  

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotStop);
  }).OnTrue(frc2::RunCommand([this] {mSubAlgaePivot->Stop();},{mSubAlgaePivot}).ToPtr());




  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotUp);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralPivot->Pivot(frc::SmartDashboard::GetNumber("SetPointUpCoral", 0.2274));},{mSubCoralPivot}).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Coral::kPivotDown);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralPivot->Pivot(frc::SmartDashboard::GetNumber("SetPointDownCoral", 0.2274));},{mSubCoralPivot}).ToPtr());  

    frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::Algae::kPivotStop);
  }).OnTrue(frc2::RunCommand([this] {mSubCoralPivot->stopCoralPivot();},{mSubCoralPivot}).ToPtr());



    // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaePivotUpCmd);
  // }).OnTrue(PivotUp(mSubAlgaePivot).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(JoystickBindingsConstants::kAlgaePivotDownCmd);
  // }).OnTrue(PivotDown(mSubAlgaePivot).ToPtr());


  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());

}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
