// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "RobotContainer.h"



RobotContainer::RobotContainer() {
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
    return mJoystick.GetRawButtonPressed(12);
  }).OnTrue(GoToTag(&mDriveTrain).ToPtr());

  // frc2::Trigger([this] {
  //   return mJoystick.GetRawButtonPressed(2) ;
  // }).OnTrue(TurnLeft(&mDriveTrain, &mIMU).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(7);
  }).OnTrue(Haut(&mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(9);
  }).OnTrue(Milieu(&mAscenseur).ToPtr());

  frc2::Trigger([this] {
    return mJoystick.GetRawButtonPressed(11);
  }).OnTrue(Bas(&mAscenseur).ToPtr());

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


void RobotContainer::drive() 
{
  if (mDriveTrain.getEnableDriveTrain())
  {
    mDriveTrain.mecanumDrive(mJoystick.GetX(), mJoystick.GetY(), mJoystick.GetZ(), mIMU.getRotation2d());
  }

  // std::cout << mIMU.getAngleYaw() << std::endl;

  if (mJoystick.GetRawButtonPressed(1))
  {
    mIMU.ResetAngle();
  }
  
  // for (int i = 0; i < LimelightHelpers::getBotpose_TargetSpace().size(); i++)
  // {
  //   std::cout << i << " : " << LimelightHelpers::getBotpose_TargetSpace().at(i) << std::endl;
  // }
}

void RobotContainer::MoveAscenseur()
{
  // if (mJoystick.GetRawButton(7))
  // {
  //   mAscenseur.setPositionAscenseur(AscenseurConstants::kAscenseurLimitDown);
  // }
  // else if (mJoystick.GetRawButton(9))
  // {
  //   mAscenseur.setPositionAscenseur(AscenseurConstants::kAscenseurLimitMiddle);
  // }
  // else if (mJoystick.GetRawButton(11))
  // {
  //   mAscenseur.setPositionAscenseur(AscenseurConstants::kAscenseurLimitUp);
  // }
  // else if (mJoystick.GetRawButton(8))
  // {
  //   mAscenseur.bougeAscenseur(0.5);
  // }
  // else if (mJoystick.GetRawButton(10))
  // {
  //   mAscenseur.bougeAscenseur(-0.5);
  // }
  // else
  // {
  //   mAscenseur.stopAscenseurMotors();
  // }
  // std::cout << mAscenseur.getEncoderPositionMotor1() << " : Encoder 1" << std::endl;
  // std::cout << mAscenseur.getEncoderPositionMotor2() << " : Encoder 2" << std::endl;
  // std::cout << mAscenseur.MotorStruggling() << " : Amps" << std::endl;
}
