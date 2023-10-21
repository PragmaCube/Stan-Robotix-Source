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
  double wLeftY = mController.GetLeftY() * 0.5;
  double wLeftX = mController.GetLeftX() * 0.5;
  double wRightX = mController.GetRightX() * 0.5;

  mDrive.setParameters(wLeftX, wLeftY, wRightX, true);
  mDrive.doExecute();
  
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
    mDrive.mGyro.ResetAngle();
  }
  std::cout << mDrive.mGyro.getRotation2D().Degrees().value() << std::endl;

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
