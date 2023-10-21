// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <cameraserver/CameraServer.h>
void Robot::RobotInit()
{
  
  std::cout << "Fin Robot Init" << std::endl;
}
void Robot::RobotPeriodic()
{
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
  std::cout << "Fin Teleop Init" << std::endl;
}
void Robot::TeleopPeriodic()
{
  //Drive Train
  wLeftY = mController.GetLeftY() * 0.5;
  wLeftX = mController.GetLeftX() * 0.5;
  wRightX = mController.GetRightX() * 0.5;

  mDrive.drive(wLeftX, wLeftY, wRightX, mGyro.getRotation2D());
  
  // Manual Mode
  if (mController.GetLeftBumperPressed())
  {
    if (mManualMode)
    {
      mManualMode = false;
    }
    else
    {
      mManualMode = true;
    }
  }

  // Assignation Touches
  if (mManualMode)
  {
    if (mArm.getPosition() > ArmConstants::kPositionDown && mController.GetYButton())
    {
      mArm.Move(-0.1);
    }
    else if (mArm.getPosition() < ArmConstants::kPositionUp && mController.GetAButton())
    {
      mArm.Move(0.1);
    }
  }
  else
  {
    if (mController.GetXButtonPressed())
    {
      mPneumatic.Retract();
    }
    if (mController.GetBButtonPressed())
    {
      mPneumatic.Extract();
    }
    if (mController.GetYButtonPressed())
    {
      mArm.PosUp();
    }
    if (mController.GetAButtonPressed())
    {
      mArm.PosDown();
    }
    if (mController.GetBackButton())
    {
      mArm.CalibrationDown();
    }
    if (mController.GetBackButtonReleased())
    {
      mArm.Stop();
      mArm.Calibrate0();
    }
    if (mController.GetStartButton())
    {
      mGyro.ResetAngle();
    }
  }
  std::cout << mGyro.GetAngle() << std::endl;

}

void Robot::DisabledInit()
{}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
