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

  m_commandJoystick = new frc2::CommandJoystick{{DrivingConstants::joystickPort}};
  m_joystick = &m_commandJoystick->GetHID();
/*
  mSub->SetDefaultCommand(frc2::RunCommand(
      [this] {
        mSub->drive(m_joystick->GetX(), m_joystick->GetY(), m_joystick->GetZ(), mIMU->getRotation2d());
        },
        {mSub}));


*/
  mArms->SetDefaultCommand(frc2::RunCommand([this] {
        mArms->GoToPlace(((m_joystick->GetThrottle() + 1) / 2), 0);
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
  m_commandJoystick->Button(2).OnTrue(ArmsPivotAt(mArms, SubArms::Positions::Up, SubArms::Positions::Down).ToPtr());
  m_commandJoystick->Button(3).OnTrue(ArmsPivotAt(mArms, SubArms::Positions::Down, SubArms::Positions::Up).ToPtr());
}

void RobotContainer::setLED()
{
  if (std::abs(m_joystick->GetX()) > 0.2)
  { 
    mLED.setMode(mLED.moving);
    // std::cout << "moving X " << m_joystick->GetX() << std::endl;
  }

  if (m_joystick->GetRawButtonPressed(7))
  {
    if (timer == 3)
    {
      mLED.setMode(mLED.giving);
      timer = 0;
    }
    else
    {
      timer++;
    }
  }

  if (std::abs(m_joystick->GetY()) > 0.2)
  {
    mLED.setMode(mLED.moving);
    // std::cout << "moving Y" << m_joystick->GetY() << std::endl;
  }
  if (m_joystick->GetRawButtonPressed(8))
  {
    mLED.setMode(mLED.immobile);
  }
  if ((abs(m_joystick->GetY())) < 0.2 && abs(m_joystick->GetX()) < 0.2){
    mLED.setMode(mLED.immobile);
  }
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
