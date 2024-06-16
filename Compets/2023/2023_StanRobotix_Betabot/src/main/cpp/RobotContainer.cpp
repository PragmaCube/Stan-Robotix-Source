// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <iostream>

#include <iostream>

#include "RobotContainer.h"

#include "Constants.h"
#include <frc2/command/button/Trigger.h>
//#include "commands/oui.h"
#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include <iostream>

/*-------------------------------------------------------------------------------------------*/


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
//   // Configure the button bindings
//   driveTrain = new subDriveTrain;
   joystick = new frc::Joystick;

   ConfigureBindings();


void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] 
  {
    return joystick.GetPOV() == 180;
  }).OnTrue(Down(&mArm).ToPtr()); // A CONFIRMER

  frc2::Trigger([this] 
  {
    return joystick.GetPOV() == 0;
  }).OnTrue(Up(&mArm).ToPtr()); // A CONFIRMER

  frc2::Trigger([this] {

    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());
  frc2::Trigger([this] {
    return joystick.GetRawButton(7);
  }).OnTrue(GoToTag(&driveTrain).ToPtr());

  /*frc2::Trigger([this] {
    return joystick.GetRawButton(6);
  }).OnTrue(oui().ToPtr());*/

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  // m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
  // frc::Shuffleboard::

}

// frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return Autos::ExampleAuto(&m_subsystem);
// }

void RobotContainer::ArmLimit()
{ 
    // if (joystick.GetPOV() == 0 && mArm->GetEncodeurPosition() > ArmConstants::kArmLimitDown)
    // {
    //   std::cout << "message" << std::endl;
    //   mArm->Down();
    // }
    
    // // Baisser bras
    // else if (joystick.GetPOV() == 180 && mArm->GetEncodeurPosition() < ArmConstants::kArmLimitUp)
    // {
    //   std::cout << "messageoui" << std::endl;
    //   mArm->Up();
    // }
}

void RobotContainer::drive() 
{

  driveTrain.mecanumDrive(joystick.GetX(), -joystick.GetY(), -joystick.GetZ(), IMU.getRotation2D());
  if (joystick.GetRawButtonPressed(8))
  {
    IMU.ResetAngle();
  }
}

void RobotContainer::oEjector()
{
  if (joystick.GetRawButtonPressed(6))
  {
    isArmForward = false;
    std::cout << "forward" << std::endl;  
  }
  else if (joystick.GetRawButtonPressed(4))
  {
    isArmForward = true;
    std::cout << "backward" << std::endl;
  }

  if (joystick.GetRawButton(1))
  {
    if (isArmForward)
    {
      Ejector.On(-(joystick.GetThrottle()-1)/2);
    }
    else
    {
      Ejector.On((joystick.GetThrottle()-1)/2);
    }
  }
  else
  {
    Ejector.Off();
  }
}

void RobotContainer::oArm()
{
  if (joystick.GetRawButtonPressed(5))
  {
    Arm.PosUp();
  }
  if (joystick.GetRawButtonPressed(3))
  {
    Arm.PosDown();

  }

  /*if (mJoystick.GetRawButtonPressed(6) == 1)
  {
    mDriveTrain.setVitesse(1);
  }

  if (mJoystick.GetRawButtonPressed(4) == 1)
  {
    mDriveTrain.setVitesse(2);
  }*/
  
  /* if (joystick.GetRawButtonPressed(1))
  {
    if ( m_SubEjector.GetMoveState() == true)
    {
      m_SubEjector.Set(SubEjector::eForwards, joystick.GetThrottle());
    }

    if ( m_SubEjector.GetMoveState() == false)
    {
      m_SubEjector.Set(SubEjector::eBackwards, joystick.GetThrottle());
    }
  }
  else
  {
      m_SubEjector.Set(SubEjector::eStop, 0);
  }*/
/////////////////////////////////////////////////////////
  if (mJoystick.GetRawButtonPressed(1))
  {
     m_SubEjector.SetRoll((m_SubEjector.GetRoll() +1) %3);
  }

  switch (m_SubEjector.GetRoll())
    {
    case 0:
      m_SubEjector.Set(SubEjector::eStop, (mJoystick.GetThrottle()-1)/2);
      
      break;
    case 1:
      m_SubEjector.Set(SubEjector::eForwards, (mJoystick.GetThrottle()-1)/2);
      
      break;
    case 2:
      m_SubEjector.Set(SubEjector::eBackwards, (mJoystick.GetThrottle()-1)/2);
      
      break;
    default:
      m_SubEjector.Set(SubEjector::eStop, (mJoystick.GetThrottle()-1)/2);
      
      break;
      
    }

  if (mJoystick.GetRawButtonPressed(4) == 1) 
  {
    switch(mDriveTrain.getVitesse())
    {
      case 1 :
        mDriveTrain.setVitesse(2);
        break;
      case 2 :
        mDriveTrain.setVitesse(1);
        break;
      default:
        mDriveTrain.setVitesse(2);
    }
  }
}

// typeDuReturn classe::fonction(parametres); -> parametres: Get...()