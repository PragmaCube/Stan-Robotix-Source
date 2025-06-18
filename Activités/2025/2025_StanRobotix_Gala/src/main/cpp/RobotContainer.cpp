// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/ArmPivotAt.h"
#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include <frc2/command/RunCommand.h>

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  mIMU = new SubIMU;
  mArms = new SubArms;
  mIMU->ResetAngle();

  mSub = new SubDriveTrain{mIMU, 1};

  m_commandJoystick = new frc2::CommandJoystick{OperatorConstants::kDriverControllerPort};
  m_joystick = &m_commandJoystick->GetHID();

  mSub->SetDefaultCommand(frc2::RunCommand(
      [this] {
        mSub->driveRobotRelativeFromJoystick(m_joystick->GetX(), m_joystick->GetY(), -m_joystick->GetZ(), 0.2);
        },
        {mSub}));



  mArms->SetDefaultCommand(frc2::RunCommand([this] {
        mArms->GoToPlace(((m_joystick->GetThrottle() + 1) / 2), ((m_joystick->GetThrottle() + 1) / 2));
        },
        {mArms})); 
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
  m_commandJoystick->Button(JoystickBindingsConstants::Arms::kArmsDown).OnTrue(ArmsPivotAt(mArms, SubArms::Positions::Down, SubArms::Positions::Down).ToPtr());
  m_commandJoystick->Button(JoystickBindingsConstants::Arms::kArmsUp).OnTrue(ArmsPivotAt(mArms, SubArms::Positions::Up, SubArms::Positions::Up).ToPtr());
  m_commandJoystick->Button(1).WhileTrue(frc2::RunCommand([this] {mIMU->ResetAngle();}, {mIMU}).ToPtr());
}

void RobotContainer::setLED()
{
  if (abs(m_joystick->GetX()) > 0.2 || abs(m_joystick->GetY()) > 0.2 ||  abs(m_joystick->GetZ()) > 0.2)
  { 
    mLED.setMode(mLED.moving);
  }

  if (m_joystick->GetRawButton(JoystickBindingsConstants::Arms::kArmsUp) || m_joystick->GetRawButton(JoystickBindingsConstants::Arms::kArmsDown))
  {
    if (timer == 5)
    {
      mLED.setMode(mLED.waving);
      timer = 0;
    }
    else
    {
      timer++;
    }
  }

  if (m_joystick->GetRawButtonPressed(5))
  {
    mLED.setMode(mLED.talking);
  }

  if (std::abs(m_joystick->GetX()) < 0.2 || abs(m_joystick->GetY()) < 0.2 ||  abs(m_joystick->GetZ()) < 0.2)
  {
    mLED.setMode(mLED.immobile);
  }
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
