// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <cameraserver/CameraServer.h>
void Robot::RobotInit()
{
  mMotors[eRight].SetInverted(true);
  frc::CameraServer::StartAutomaticCapture();
  //ils ont reprogrammé l'opérateur / pour faire comme dans les chemins de fichiers
  std::cout << "Début Robot Init" << std::endl;
  std::cout << "Fin file read" << std::endl;
  frc::ShuffleboardTab& wGalaTab = frc::Shuffleboard::GetTab("Gala");
  wGalaTab.Add("Drive Train", mDrive);
  mClimberEnabled =       wGalaTab
                         .Add("ClImberEnabled", true)
                         .WithWidget("Toggle Button")
                         .GetEntry();

  mSetpoint1 =            wGalaTab
                         .Add("SetPoint1", mSetpoints[0])
                         .WithWidget("Text View")
                         .GetEntry();
                         
  mSetpoint2 =            wGalaTab
                         .Add("SetPoint2", mSetpoints[1])
                         .WithWidget("Text View")
                         .GetEntry();
  mIntensity =            wGalaTab
                         .Add("Intensity", 0)
                         .WithWidget("Graph")
                         .GetEntry();
  mPosition =             wGalaTab
                         .Add("Position", mSetpoints[0])
                         .WithWidget("Number Bar")
                         .GetEntry();
  mIsClimberEnabled = mClimberEnabled->GetBoolean(true);
  mLedStrip.SetLength(kLedLenght + kTourLenght);
  mLedStrip.Start();


  
  std::cout << "Fin Robot Init" << std::endl;
}
void Robot::RobotPeriodic()
{
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
  //Calibration 0 climber
  mClimbPid.SetReference(0.5, rev::ControlType::kVoltage);
  double wI = mClimb.GetOutputCurrent();

  
  mIntensity->SetDouble(mClimb.GetOutputCurrent());
  mClimbZero = mClimbEncoder.GetPosition() ;
  mClimbPid.SetReference(mClimbZero, rev::ControlType::kSmartMotion);
  std::cout << "Fin Teleop Init" << std::endl;
}
void Robot::TeleopPeriodic()
{
  //Drive Train
  double wLeftY = mController.GetLeftY() * -0.5;
  double wRightY = mController.GetRightY() * -0.5;

  if((mMotionSmoothedDrive[0] > 0 && wLeftY < mMotionSmoothedDrive[0]) || (mMotionSmoothedDrive[0] < 0 && wLeftY > mMotionSmoothedDrive[0]))
  {
    mMotionSmoothedDrive[0] = wLeftY;
    mLeftFilter.Reset(wLeftY);
  }
  else
  {
    mMotionSmoothedDrive[0] = mLeftFilter.Calculate(wLeftY);
  }
  if((mMotionSmoothedDrive[1] > 0 && wRightY < mMotionSmoothedDrive[1]) || (mMotionSmoothedDrive[1] < 0 && wRightY > mMotionSmoothedDrive[1]))
  {
    mMotionSmoothedDrive[1] = wRightY;
    mRightFilter.Reset(wRightY);
  }
  else
  {
    mMotionSmoothedDrive[1] = mRightFilter.Calculate(wRightY);
  }
  mDrive.TankDrive(mMotionSmoothedDrive[0],mMotionSmoothedDrive[1]);
  //Climber
  if(mIsClimberEnabled)
  {
    if (mController.GetYButtonPressed())
    {
      std::cout << mSetpoints[1] << std::endl;
      mClimbPid.SetReference(mSetpoints[1] + mClimbZero, rev::ControlType::kSmartMotion);
    }
    else if (mController.GetAButtonPressed())
    {
      std::cout << mSetpoints[0] << std::endl;
      mClimbPid.SetReference(mSetpoints[0] + mClimbZero, rev::ControlType::kSmartMotion);
    }
    else if (mController.GetRawAxis(frc::XboxController::Axis::kLeftTrigger) > 0)
    {
      double wCustomSetpoint = mController.GetLeftTriggerAxis() * (mSetpoints[1] - mSetpoints[0]) + mSetpoints[0];
      // std::cout << wCustomSetpoint << std::endl;
      mClimbPid.SetReference(wCustomSetpoint + mClimbZero, rev::ControlType::kSmartMotion);
    }
  }
  else
  {
    mClimbPid.SetReference(0, rev::ControlType::kDutyCycle);
  }
  //Bande Led + Servo
  int wClimbPosition = mClimbEncoder.GetPosition()-mClimbZero;
  mPosition->SetDouble(wClimbPosition);
  // std::cout << wClimbPosition << std::endl;

  /*
  
  BRO WHAT C'EST PAS BEAU
  ET PAS PROPRE

  */

  if(wClimbPosition >= mSetpoints[0] - 1)
  {
    mState = eIdle;
  }
  else if(wClimbPosition <= mSetpoints[1] + 1)
  {
    mState = eUp;
  }
  else
  {
    mState = eClimbing;
  }
  mHSVCounter++;
  double wLedMeter = wClimbPosition  * kActualTourLenght / (mSetpoints[1]+1) / 4;
  switch(mState)
  {
    case eIdle:
      mServo.Set(0);
      for(int i = 0; i < kLedLenght / 4; i++)
      {
        mLedData[(i+mHSVCounter/2)%kLedLenght + kTourLenght] = frc::AddressableLED::LEDData(i*255*4/kLedLenght, 0, 0);
      }
      for(int i = kLedLenght/4; i < kLedLenght / 2; i++)
      {
        mLedData[(i+mHSVCounter/2)%kLedLenght + kTourLenght] = frc::AddressableLED::LEDData(255-(i-kLedLenght/4)*255*4/kLedLenght, 0, 0);
      }
      for(int i = kLedLenght/2; i < kLedLenght * 3 / 4; i++)
      {
        mLedData[(i+mHSVCounter/2)%kLedLenght + kTourLenght] = frc::AddressableLED::LEDData(0, 0, (i-kLedLenght/2)*255*4/kLedLenght);
      }
      for(int i = kLedLenght * 3 / 4; i < kLedLenght; i++)
      {
        mLedData[(i+mHSVCounter/2)%kLedLenght + kTourLenght] = frc::AddressableLED::LEDData(0, 0, 255-(i-kLedLenght*3/4)*255*4/kLedLenght);
      }
      for(int i = 0; i < kActualTourLenght; i += 19)
      {
        for(int j = 0; j < 9 ; j++)
        {
          mLedData[((int)(mHSVCounter*0.6)+i+j)%kActualTourLenght] = frc::AddressableLED::LEDData{127,63,0};
        }
        mLedData[((int)(mHSVCounter*0.6)+10+i)%kActualTourLenght] = frc::AddressableLED::LEDData{63 , 31, 0};
        for(int j = 11; j < 19 ; j++)
        {
          mLedData[((int)(mHSVCounter*0.6)+i+j)%kActualTourLenght] = kBlack;
        }  
      } 
      break;
    case eClimbing:
      mServo.Set(0);
      if(mHSVCounter%5 == 0)
      {
        if(mLedData[0].r == kAmber.r)
        {
          for(int i = 0; i < kLedLenght; i++)
          {
            mLedData[i + kTourLenght] = kBlack;
          }
        }
        else
        {
          for(int i = 0; i < kLedLenght; i++)
          {
            mLedData[i + kTourLenght] = kAmber;
          }
        }
      }
      mClimbMotionSmoothing = (9*mClimbMotionSmoothing + wLedMeter) / 10;
      for(int i = 0; i < 4; i++)
      {
        for(int j = 0; j < mClimbMotionSmoothing; j++)
        {
          mLedData[i*kActualTourLenght/4 + j] = frc::AddressableLED::LEDData{255-255*4*mClimbMotionSmoothing/kActualTourLenght, 255*4*mClimbMotionSmoothing/kActualTourLenght, 0};
        }
        mLedData[(int)mClimbMotionSmoothing] = frc::AddressableLED::LEDData{(255-255*4*mClimbMotionSmoothing/kActualTourLenght)*(mClimbMotionSmoothing - ((int)mClimbMotionSmoothing)), 255*4*mClimbMotionSmoothing/kActualTourLenght*(mClimbMotionSmoothing - ((int)mClimbMotionSmoothing)), 0};
        for(int j = mClimbMotionSmoothing; j < kActualTourLenght / 4 ; j++)
        {
          mLedData[i*kActualTourLenght/4 + j] = kBlack;
        }
      }
      break;
    case eUp:
      mServo.SetAngle(80);
      for(int i = 0; i < kLedLenght; i++)
      {
        if((i+(mHSVCounter/5))%3 == 0)
        {
          mLedData[i + kTourLenght] = kOrange;
        }
        else
        {
          mLedData[i + kTourLenght] = kBlack;
        }
      }
      if(mHSVCounter % 255 < 128)
      {
        for(int i = 0; i < kActualTourLenght; i++)
        {
          mLedData[i] = frc::AddressableLED::LEDData{0, mHSVCounter % 255, 0};
        }
      }
      else
      {
        for(int i = 0; i < kActualTourLenght; i++)
        {
          mLedData[i] = frc::AddressableLED::LEDData{0, 255 - mHSVCounter % 255, 0};
        }
      }
      break;
    default:
    mServo.Set(0);
    mLedData[mHSVCounter%kLedLenght + kTourLenght] = kMagenta;
  }

  mLedStrip.SetData(std::span{mLedData});

  //Mise à jour des setpoints
  mSetpoints[0] = mSetpoint1->GetDouble(mSetpoints[0]);
  // mSetpoints[1] = mSetpoint2->GetDouble(mSetpoints[1]);
  mIsClimberEnabled = mClimberEnabled->GetBoolean(false);

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
